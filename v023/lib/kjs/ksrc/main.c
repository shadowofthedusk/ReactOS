/*
 * The JS shell
 * Copyright (c) 1998 New Generation Software (NGS) Oy
 *
 * Author: Markku Rossi <mtr@ngs.fi>
 */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA
 */

/*
 * $Source: /CVS/ReactOS/reactos/lib/kjs/ksrc/main.c,v $
 * $Id: main.c,v 1.1 2004/01/10 20:38:17 arty Exp $
 */

#if HAVE_CONFIG_H
#include "jsconfig.h"
#endif

#include <stdio.h>
#include <assert.h>

#if HAVE_STDC_HEADERS
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#else /* not HAVE_STDC_HEADERS */

#if HAVE_STDLIB_H
#include <stdlib.h>
#endif

#if HAVE_STRING_H
#include <string.h>
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#endif /* not HAVE_STDC_HEADERS */

#include "js.h"
#include "getopt.h"

/*
 * Global variables.
 */

char *program;

/* Options. */

/*
 * -a, --annotate-assembler
 *
 * Annotate generated assembler listing with the original source code.
 */

int annotate_assembler = 0;

/*
 * -c, --compile
 *
 * Compile all given JavaScript files to byte-code and save the result
 * to file.
 */

int compile = 0;

/*
 * -d METHOD, --dispatch=METHOD
 *
 * Use byte-code instruction dispatch method METHOD.  Possible values are
 * `switch', `switch-basic' and `jumps'.
 */

JSVMDispatchMethod dispatch_method = JS_VM_DISPATCH_JUMPS;

/*
 * -e CODE, --eval=CODE
 *
 * Evaluate JavaScript code CODE.
 */

/*
 * -E, --events
 *
 * Print virtual machine events to the standard error.
 */
int events = 0;

/*
 * -f, --file
 *
 * Use the next argument as the main source file and pass all
 * remaining arguments to it through the ARGS array.
 */

/*
 * -g, --debug
 *
 * Generate debugging information to the generated byte-code file.
 */
int generate_debug_info = 0;

/*
 * -h, --help
 *
 * Print short help and exit successfully.
 */

/*
 * -l, --load
 *
 * Treat all following arguments, up to option -f / --file, as
 * byte-code or JavaScript files and execute them.  When option -f, --file
 * is encountered, the next argument is the actual main source file that
 * is executed with the remaining arguments.
 */

/*
 * -N, --no-compiler
 *
 * Do not define compiler in the interpreter.  Options makes the
 * interpreter a pure virtual machine that can't compile any JavaScript
 * code.
 */

int no_compiler = 0;

/*
 * -O [LEVEL], --optimize[=LEVEL]
 *
 * Optimize at level LEVEL.  The default level for batch-compile is 1.
 * Value 0 disable optimization.
 */

int optimize = 1;

/*
 * -r OPTION, --secure=OPTIONS
 *
 * Turn on security option OPTION.
 */

int secure_builtin_file = 0;
int secure_builtin_system = 0;

/*
 * -s SIZE, --stack-size=SIZE
 *
 * Set the virtual machine stack size to SIZE.
 */
unsigned int stack_size = 2048;

/*
 * -S, --no-assemble
 *
 * Compile al given JavaScript files to JavaScript assembler and save the
 * result to file.
 */

int no_assemble = 0;

/*
 * -t, --stacktrace
 *
 * Print stack trace on error.
 */

int stacktrace_on_error = 0;

/*
 * -v, --verbose
 *
 * Tell more about what we do.
 */

unsigned int verbose = 0;

/*
 * -V, --version
 *
 * Print version information and exit successfully.
 */

/*
 * -W OPTION, --compiler-option=OPTION
 *
 * Set compiler option OPTION.
 */

int warn_deprecated = 0;
int warn_unused_argument = 0;
int warn_unused_variable = 1;
int warn_undef = 1;
int warn_shadow = 1;
int warn_with_clobber = 1;
int warn_missing_semicolon = 0;
int warn_strict_ecma = 0;

/*
 * -x, --executable
 *
 * Generate executable byte-code files.
 */
int generate_executable_bc_files = 0;


/*
 * Static variables.
 */

static struct option long_options[] =
{
  {"annotate-assembler",	no_argument,		0, 'a'},
  {"compile",			no_argument,		0, 'c'},
  {"dispatch",			required_argument,	0, 'd'},
  {"eval",			required_argument,	0, 'e'},
  {"events",			no_argument,		0, 'E'},
  {"file",			no_argument,		0, 'f'},
  {"debug",			no_argument,		0, 'g'},
  {"help",			no_argument,		0, 'h'},
  {"load",			no_argument,		0, 'l'},
  {"no-compiler",		no_argument,		0, 'N'},
  {"optimize",			optional_argument,	0, 'O'},
  {"secure",			required_argument,	0, 'r'},
  {"stack-size",		required_argument,	0, 's'},
  {"no-assemble",		no_argument,		0, 'S'},
  {"stacktrace",		no_argument,		0, 't'},
  {"verbose",			no_argument,		0, 'v'},
  {"version",			no_argument,		0, 'V'},
  {"compiler-option",		required_argument,	0, 'W'},
  {"executable",		no_argument,		0, 'x'},

  {NULL, 0, 0, 0},
};

/* Compiler options. */

/* Flags for options. */
#define JSC_RUNTIME	0x01
#define JSC_WALL	0x02
#define JSC_PEDANTIC	0x04
#define JSC_LINT	0x08

static struct
{
  char *name;
  int *option;
  unsigned int flags;
} compiler_options[] =
{
  {"deprecated",		&warn_deprecated,		JSC_WALL},
  {"unused-argument",		&warn_unused_argument,		JSC_WALL},
  {"unused-variable",		&warn_unused_variable,		JSC_WALL},
  {"undefined",			&warn_undef,			JSC_RUNTIME},
  {"shadow",			&warn_shadow,			JSC_WALL},
  {"with-clobber",		&warn_with_clobber,		JSC_WALL},
  {"missing-semicolon",		&warn_missing_semicolon,	JSC_PEDANTIC},
  {"strict-ecma",		&warn_strict_ecma,		JSC_LINT},

  {NULL, NULL, 0},
};


/*
 * Prototypes for static functions.
 */

static void handle_compiler_option (char *name);

static JSInterpPtr create_interp (void);

static void usage (void);
static void version (void);

/*
 * Global functions.
 */

int
main (int argc, char *argv[])
{
  JSInterpPtr interp = NULL;
  char *cp;
  int do_load = 0;

  /* Get program's name. */
  program = strrchr (argv[0], '/');
  if (program == NULL)
    program = argv[0];
  else
    program++;

  /* Make getopt_long() to use our modified program name. */
  argv[0] = program;

  /* Parse arguments. */
  while (1)
    {
      int c;
      int option_index = 0;

      c = getopt_long (argc, argv, "acd:e:EfghlNO::r:s:StvVW:x",
		       long_options, &option_index);
      if (c == EOF)
	break;

      switch (c)
	{
	case 'a':		/* --annotate-assembler */
	  annotate_assembler = 1;
	  break;

	case 'c':		/* --compile */
	  compile = 1;
	  break;

	case 'd':		/* --dispatch */
	  if (strcmp (optarg, "switch-basic") == 0)
	    dispatch_method = JS_VM_DISPATCH_SWITCH_BASIC;
	  else if (strcmp (optarg, "switch") == 0)
	    dispatch_method = JS_VM_DISPATCH_SWITCH;
	  else if (strcmp (optarg, "jumps") == 0)
	    dispatch_method = JS_VM_DISPATCH_JUMPS;
	  else
	    {
	      fprintf (stderr, "%s: illegal dispatch method `%s'\n",
		       program, optarg);
	      exit (1);
	    }
	  break;

	case 'e':		/* --eval */
	  if (interp == NULL)
	    interp = create_interp ();

	  if (!js_eval (interp, optarg))
	    {
	      fprintf (stderr, "%s: eval failed: %s\n", program,
		       js_error_message (interp));
	      exit (1);
	    }
	  break;

	case 'E':		/* --events */
	  events = 1;
	  break;

	case 'f':		/* --file */
	  if (optind >= argc)
	    {
	    no_argument_for_file:
	      fprintf (stderr, "%s: no arguments after option --file\n",
		       program);
	      exit (1);
	    }
	  goto arguments_done;
	  break;

	case 'g':		/* --debug */
	  generate_debug_info = 1;
	  break;

	case 'h':		/* --help */
	  usage ();
	  exit (0);
	  break;

	case 'l':		/* --load */
	  do_load = 1;
	  goto arguments_done;
	  break;

	case 'N':		/* --no-compiler */
	  no_compiler = 1;
	  break;

	case 'O':		/* --optimize */
	  if (optarg)
	    optimize = atoi (optarg);
	  break;

	case 'r':		/* --secure */
	  if (strcmp (optarg, "file") == 0)
	    secure_builtin_file = 1;
	  else if (strcmp (optarg, "system") == 0)
	    secure_builtin_system = 1;
	  else
	    {
	      fprintf (stderr, "%s: unknown security option `%s'\n",
		       program, optarg);
	      exit (1);
	    }
	  break;

	case 's':		/* --stack-size */
	  stack_size = atoi (optarg);
	  break;

	case 'S':		/* --no-assemble */
	  no_assemble = 1;
	  break;

	case 't':		/* --stacktrace */
	  stacktrace_on_error = 1;
	  break;

	case 'v':		/* --verbose */
	  verbose++;
	  break;

	case 'V':		/* --version */
	  version ();
	  exit (0);
	  break;

	case 'W':		/* --compiler-option */
	  handle_compiler_option (optarg);
	  break;

	case 'x':		/* --executable */
	  generate_executable_bc_files = 1;
	  break;

	case '?':
	  fprintf (stderr, "Try `%s --help' for more information.\n",
		   program);
	  exit (1);
	  break;

	default:
	  printf ("Hey!  main() didn't handle option \"%c\" (%d)", c, c);
	  if (optarg)
	    printf (" with arg %s", optarg);
	  printf ("\n");
	  abort ();
	  break;
	}
    }

 arguments_done:

  interp = create_interp ();

  /* Let's see what we have to do. */
  if (compile)
    {
      char *jscname;

      /*
       * Treat all remaining arguments as JavaScript files and compile them.
       */

      for (; optind < argc; optind++)
	{
	  /* Create name for the byte-code file. */

	  jscname = malloc (strlen (argv[optind]) + 5);
	  assert (jscname != NULL);
	  strcpy (jscname, argv[optind]);

	  cp = strrchr (jscname, '.');
	  if (cp)
	    strcpy (++cp, "jsc");
	  else
	    strcat (jscname, ".jsc");

	  if (verbose)
	    printf ("%s: compiling `%s' to `%s'\n", program,
		    argv[optind], jscname);

	  if (!js_compile (interp, argv[optind], NULL, jscname))
	    {
	      fprintf (stderr, "%s\n", js_error_message (interp));
	      exit (1);
	    }

	  free (jscname);
	}
    }
  else if (no_assemble)
    {
      char *jasname;

      /* Compile argument files to assembler. */
      for (; optind < argc; optind++)
	{
	  /* Create name for the assembler file. */

	  jasname = malloc (strlen (argv[optind]) + 5);
	  assert (jasname != NULL);
	  strcpy (jasname, argv[optind]);

	  cp = strrchr (jasname, '.');
	  if (cp)
	    strcpy (++cp, "jas");
	  else
	    strcat (jasname, ".jas");

	  if (verbose)
	    printf ("%s: compiling `%s' to `%s'\n", program,
		    argv[optind], jasname);

	  if (!js_compile (interp, argv[optind], jasname, NULL))
	    {
	      fprintf (stderr, "%s\n", js_error_message (interp));
	      exit (1);
	    }

	  free (jasname);
	}
    }
  else if (optind < argc)
    {
      char *main_file = argv[optind];
      JSType args;
      int i;

      /*
       * Assume that <main_file> contains JavaScript (or byte-code) and
       * execute it.  All the remaining arguments are passed to the
       * interpreter through the ARGS array.
       */

      /* Save all remaining arguments to ARGS */
      js_type_make_array (interp, &args, argc - optind);

      for (i = 0; optind + i < argc; i++)
	js_type_make_string (interp, &args.u.array->data[i],
			     argv[optind + i], strlen (argv[optind + i]));

      js_set_var (interp, "ARGS", &args);

      if (!js_eval_file (interp, main_file))
	{
	  fprintf (stderr, "%s: evaluation of file `%s' failed:\n%s\n",
		   program, main_file, js_error_message (interp));
	  exit (1);
	}
    }

  js_destroy_interp (interp);

  return 0;
}


/*
 * Static functions.
 */

static inline int
is_prefix (char *prefix, char *str)
{
  int i;

  for (i = 0; prefix[i] && str[i] && prefix[i] == str[i]; i++)
    ;
  if (!prefix[i])
    return 1;

  return 0;
}


static void
handle_compiler_option (char *name)
{
  int i;
  int value = 1;
  int nmatches = 0;
  int did_match = 0;

  if (name[0] == 'n' && name[1] == 'o' && name[2] == '-')
    {
      value = 0;
      name += 3;
    }

  for (i = 0; compiler_options[i].name; i++)
    {
      int was_prefix = 0;

      if ((was_prefix = is_prefix (name, compiler_options[i].name))
	  || (strcmp (name, "runtime") == 0
	      && (compiler_options[i].flags & JSC_RUNTIME))
	  || (strcmp (name, "all") == 0
	      && (compiler_options[i].flags & JSC_WALL))
	  || (strcmp (name, "pedantic") == 0
	      && (compiler_options[i].flags & (JSC_WALL | JSC_PEDANTIC))))
	{
	  *compiler_options[i].option = value;

	  if (was_prefix)
	    nmatches++;

	  did_match = 1;
	}
    }

  if (!did_match)
    {
      fprintf (stderr, "%s: unknown compiler option `-W%s%s'\n", program,
	       value ? "" : "no-", name);
      exit (1);
    }
  if (nmatches > 1)
    {
      fprintf (stderr, "%s: ambiguous compiler option `-W%s%s'\n",
	       program, value ? "" : "no-", name);
      exit (1);
    }
}


static int
show_events_hook (int event, void *context)
{
  char *event_name;

  switch (event)
    {
    case JS_EVENT_OPERAND_COUNT:
      event_name = "operand count";
      break;

    case JS_EVENT_GARBAGE_COLLECT:
      event_name = "garbage collect";
      break;

    default:
      event_name = "unknown";
      break;
    }

  fprintf (stderr, "[%s: %s]\n", program, event_name);

  return 0;
}


static JSInterpPtr
create_interp ()
{
  JSInterpOptions options;
  JSInterpPtr interp;

  js_init_default_options (&options);

  options.stack_size = stack_size;
  options.dispatch_method = dispatch_method;
  options.verbose = verbose;

  options.no_compiler = no_compiler;
  options.stacktrace_on_error = stacktrace_on_error;

  options.secure_builtin_file = secure_builtin_file;
  options.secure_builtin_system = secure_builtin_system;

  options.annotate_assembler = annotate_assembler;
  options.debug_info = generate_debug_info;
  options.executable_bc_files = generate_executable_bc_files;

  options.warn_unused_argument		= warn_unused_argument;
  options.warn_unused_variable		= warn_unused_variable;
  options.warn_undef			= warn_undef;
  options.warn_shadow			= warn_shadow;
  options.warn_with_clobber		= warn_with_clobber;
  options.warn_missing_semicolon	= warn_missing_semicolon;
  options.warn_strict_ecma		= warn_strict_ecma;
  options.warn_deprecated		= warn_deprecated;

  /* As a default, no optimization */
  options.optimize_peephole = 0;
  options.optimize_jumps_to_jumps = 0;
  options.optimize_bc_size = 0;
  options.optimize_heavy = 0;

  if (optimize >= 1)
    {
      options.optimize_peephole = 1;
      options.optimize_jumps_to_jumps = 1;
      options.optimize_bc_size = 1;
    }

  if (optimize >= 2)
    {
      options.optimize_heavy = 1;
    }

  /* Show events? */
  if (events)
    {
      options.hook = show_events_hook;
      options.hook_operand_count_trigger = 1000000;
    }

  interp = js_create_interp (&options);
  if (interp == NULL)
    {
      fprintf (stderr, "%s: couldn't create interpreter\n", program);
      exit (1);
    }

  /* And finally, define the requested modules. */

#if WITH_JS
  if (!js_define_module (interp, js_ext_JS))
    fprintf (stderr, "%s: warning: couldn't create the JS extension\n",
	     program);
#endif

#if WITH_CURSES
  if (!js_define_module (interp, js_ext_curses))
    fprintf (stderr, "%s: warning: couldn't create the curses extension\n",
	     program);
#endif

#if WITH_MD5
  if (!js_define_module (interp, js_ext_MD5))
    fprintf (stderr, "%s: warning: couldn't create the MD5 extension\n",
	     program);
#endif

  return interp;
}


static void
usage ()
{
  printf ("\
Usage: %s [OPTION]... FILE [ARGUMENT]...\n\
Mandatory arguments to long options are mandatory for short options too.\n\
  -a, --annotate-assembler   annotate generated assembler listing with\n\
                             the original source code\n\
  -c, --compile              compile JavaScript input file to byte-code\n\
                             and save the result to the file `FILE.jsc'\n\
  -d, --dispatch=METHOD      use method METHOD for byte-code instruction\n\
                             dispatching\n\
  -e, --eval=CODE            evaluate JavaScript code CODE\n\
  -E, --events               print interpreter events\n\
  -f, --file                 evaluate the next argument file and pass\n\
                             all remaining arguments to the interpreter\n\
                             through the ARGS array\n\
  -g, --debug                generate debugging information\n\
  -h, --help                 print this help and exit\n\
  -l, --load                 evaluate argument files until option `-f',\n\
                             `--file' is encountered\n\
  -N, --no-compiler          do not define compiler to the JavaScript\n\
                             interpreter\n\
  -O, --optimize[=LEVEL]     optimize at level LEVEL\n\
  -r, --secure=OPTION        turn on security option OPTION\n\
  -s, --stack-size=SIZE      set the interpreter stack size to SIZE nodes\n\
  -S, --assembler            compile JavaScript intput file to assembler\n\
                             and save the result to the file `FILE.jas'\n\
  -t, --stacktrace           print stacktrace on error\n\
  -v, --verbose              tell what the interpreter is doing\n\
  -V, --version              print version number\n\
  -W, --compiler-option=OPTION\n\
                             set compilation option OPTION\n\
  -x, --executable           generate executable byte-code files\n",
	  program);

  printf ("\nReport bugs to mtr@ngs.fi.\n");
}


static void
version ()
{
  printf ("NGS JavaScript Interpter %s\n\
Copyright (C) 1998 New Generation Software (NGS) Oy.\n\
NGS JavaScript Interpreter comes with NO WARRANTY, to the extent\n\
permitted by law.  You may redistribute copies of NGS JavaScript\n\
Interpreter under the terms of the GNU Library General Public License.\n\
For more information about these matters, see the files named COPYING.\n\
",
	  VERSION);
}

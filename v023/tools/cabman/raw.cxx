/*
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS cabinet manager
 * FILE:        tools/cabman/raw.cpp
 * PURPOSE:     CAB codec for uncompressed "raw" data
 * PROGRAMMERS: Casper S. Hornstrup (chorns@users.sourceforge.net)
 * REVISIONS:
 *   CSH 21/03-2001 Created
 *   CSH 15/08-2003 Made it portable
 */
#include "raw.h"


/* CRawCodec */

CRawCodec::CRawCodec()
/*
 * FUNCTION: Default constructor
 */
{
}


CRawCodec::~CRawCodec()
/*
 * FUNCTION: Default destructor
 */
{
}


unsigned long CRawCodec::Compress(void* OutputBuffer,
    void* InputBuffer,
    unsigned long InputLength,
    unsigned long* OutputLength)
/*
 * FUNCTION: Compresses data in a buffer
 * ARGUMENTS:
 *     OutputBuffer = Pointer to buffer to place compressed data
 *     InputBuffer  = Pointer to buffer with data to be compressed
 *     InputLength  = Length of input buffer
 *     OutputLength = Address of buffer to place size of compressed data
 */
{
    memcpy(OutputBuffer, InputBuffer, InputLength);
    *OutputLength = InputLength;
    return CS_SUCCESS;
}

unsigned long CRawCodec::Uncompress(void* OutputBuffer,
    void* InputBuffer,
    unsigned long InputLength,
    unsigned long* OutputLength)
/*
 * FUNCTION: Uncompresses data in a buffer
 * ARGUMENTS:
 *     OutputBuffer = Pointer to buffer to place uncompressed data
 *     InputBuffer  = Pointer to buffer with data to be uncompressed
 *     InputLength  = Length of input buffer
 *     OutputLength = Address of buffer to place size of uncompressed data
 */
{
    memcpy(OutputBuffer, InputBuffer, InputLength);
    *OutputLength = InputLength;
    return CS_SUCCESS;
}

/* EOF */
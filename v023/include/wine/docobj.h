/*** Autogenerated by WIDL 0.1 from docobj.idl - Do not edit ***/
#include <rpc.h>
#include <rpcndr.h>

#ifndef __WIDL_DOCOBJ_H
#define __WIDL_DOCOBJ_H
#ifdef __cplusplus
extern "C" {
#endif
#include <ocidl.h>
#include <objidl.h>
#include <oleidl.h>
#include <oaidl.h>
#include <servprov.h>
#ifndef __IOleDocumentView_FWD_DEFINED__
#define __IOleDocumentView_FWD_DEFINED__
typedef struct IOleDocumentView IOleDocumentView;
#endif

#ifndef __IEnumOleDocumentViews_FWD_DEFINED__
#define __IEnumOleDocumentViews_FWD_DEFINED__
typedef struct IEnumOleDocumentViews IEnumOleDocumentViews;
#endif

#ifndef __IOleDocument_FWD_DEFINED__
#define __IOleDocument_FWD_DEFINED__
typedef struct IOleDocument IOleDocument;
#endif

typedef IOleDocument *LPOLEDOCUMENT;

typedef enum {
    DOCMISC_CANCREATEMULTIPLEVIEWS = 1,
    DOCMISC_SUPPORTCOMPLEXRECTANGLES = 2,
    DOCMISC_CANTOPENEDIT = 4,
    DOCMISC_NOFILESUPPORT = 8
} DOCMISC;

/*****************************************************************************
 * IOleDocument interface
 */
#ifndef __IOleDocument_INTERFACE_DEFINED__
#define __IOleDocument_INTERFACE_DEFINED__

DEFINE_GUID(IID_IOleDocument, 0xb722bcc5, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IOleDocument : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE CreateView(
        IOleInPlaceSite* pIPSite,
        IStream* pstm,
        DWORD dwReserved,
        IOleDocumentView** ppView) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDocMiscStatus(
        DWORD* pdwStatus) = 0;

    virtual HRESULT STDMETHODCALLTYPE EnumViews(
        IEnumOleDocumentViews** ppEnum,
        IOleDocumentView** ppView) = 0;

};
#else
typedef struct IOleDocumentVtbl IOleDocumentVtbl;
struct IOleDocument {
    const IOleDocumentVtbl* lpVtbl;
};
struct IOleDocumentVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IOleDocument* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IOleDocument* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IOleDocument* This);

    /*** IOleDocument methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateView)(
        IOleDocument* This,
        IOleInPlaceSite* pIPSite,
        IStream* pstm,
        DWORD dwReserved,
        IOleDocumentView** ppView);

    HRESULT (STDMETHODCALLTYPE *GetDocMiscStatus)(
        IOleDocument* This,
        DWORD* pdwStatus);

    HRESULT (STDMETHODCALLTYPE *EnumViews)(
        IOleDocument* This,
        IEnumOleDocumentViews** ppEnum,
        IOleDocumentView** ppView);

};

/*** IUnknown methods ***/
#define IOleDocument_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IOleDocument_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IOleDocument_Release(p) (p)->lpVtbl->Release(p)
/*** IOleDocument methods ***/
#define IOleDocument_CreateView(p,a,b,c,d) (p)->lpVtbl->CreateView(p,a,b,c,d)
#define IOleDocument_GetDocMiscStatus(p,a) (p)->lpVtbl->GetDocMiscStatus(p,a)
#define IOleDocument_EnumViews(p,a,b) (p)->lpVtbl->EnumViews(p,a,b)

#endif

#define IOleDocument_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IOleDocument methods ***/ \
    STDMETHOD_(HRESULT,CreateView)(THIS_ IOleInPlaceSite* pIPSite, IStream* pstm, DWORD dwReserved, IOleDocumentView** ppView) PURE; \
    STDMETHOD_(HRESULT,GetDocMiscStatus)(THIS_ DWORD* pdwStatus) PURE; \
    STDMETHOD_(HRESULT,EnumViews)(THIS_ IEnumOleDocumentViews** ppEnum, IOleDocumentView** ppView) PURE;

HRESULT CALLBACK IOleDocument_CreateView_Proxy(
    IOleDocument* This,
    IOleInPlaceSite* pIPSite,
    IStream* pstm,
    DWORD dwReserved,
    IOleDocumentView** ppView);
void __RPC_STUB IOleDocument_CreateView_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocument_GetDocMiscStatus_Proxy(
    IOleDocument* This,
    DWORD* pdwStatus);
void __RPC_STUB IOleDocument_GetDocMiscStatus_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocument_EnumViews_Proxy(
    IOleDocument* This,
    IEnumOleDocumentViews** ppEnum,
    IOleDocumentView** ppView);
void __RPC_STUB IOleDocument_EnumViews_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IOleDocument_INTERFACE_DEFINED__ */

#ifndef __IOleDocumentSite_FWD_DEFINED__
#define __IOleDocumentSite_FWD_DEFINED__
typedef struct IOleDocumentSite IOleDocumentSite;
#endif

typedef IOleDocumentSite *LPOLEDOCUMENTSITE;

/*****************************************************************************
 * IOleDocumentSite interface
 */
#ifndef __IOleDocumentSite_INTERFACE_DEFINED__
#define __IOleDocumentSite_INTERFACE_DEFINED__

DEFINE_GUID(IID_IOleDocumentSite, 0xb722bcc7, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IOleDocumentSite : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE ActivateMe(
        IOleDocumentView* pViewToActivate) = 0;

};
#else
typedef struct IOleDocumentSiteVtbl IOleDocumentSiteVtbl;
struct IOleDocumentSite {
    const IOleDocumentSiteVtbl* lpVtbl;
};
struct IOleDocumentSiteVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IOleDocumentSite* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IOleDocumentSite* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IOleDocumentSite* This);

    /*** IOleDocumentSite methods ***/
    HRESULT (STDMETHODCALLTYPE *ActivateMe)(
        IOleDocumentSite* This,
        IOleDocumentView* pViewToActivate);

};

/*** IUnknown methods ***/
#define IOleDocumentSite_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IOleDocumentSite_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IOleDocumentSite_Release(p) (p)->lpVtbl->Release(p)
/*** IOleDocumentSite methods ***/
#define IOleDocumentSite_ActivateMe(p,a) (p)->lpVtbl->ActivateMe(p,a)

#endif

#define IOleDocumentSite_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IOleDocumentSite methods ***/ \
    STDMETHOD_(HRESULT,ActivateMe)(THIS_ IOleDocumentView* pViewToActivate) PURE;

HRESULT CALLBACK IOleDocumentSite_ActivateMe_Proxy(
    IOleDocumentSite* This,
    IOleDocumentView* pViewToActivate);
void __RPC_STUB IOleDocumentSite_ActivateMe_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IOleDocumentSite_INTERFACE_DEFINED__ */

typedef IOleDocumentView *LPOLEDOCUMENTVIEW;

/*****************************************************************************
 * IOleDocumentView interface
 */
#ifndef __IOleDocumentView_INTERFACE_DEFINED__
#define __IOleDocumentView_INTERFACE_DEFINED__

DEFINE_GUID(IID_IOleDocumentView, 0xb722bcc6, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IOleDocumentView : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetInPlaceSite(
        IOleInPlaceSite* pIPSite) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetInPlaceSite(
        IOleInPlaceSite** ppIPSite) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDocument(
        IUnknown** ppunk) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetRect(
        LPRECT prcView) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRect(
        LPRECT prcView) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetRectComplex(
        LPRECT prcView,
        LPRECT prcHScroll,
        LPRECT prcVScroll,
        LPRECT prcSizeBox) = 0;

    virtual HRESULT STDMETHODCALLTYPE Show(
        BOOL fShow) = 0;

    virtual HRESULT STDMETHODCALLTYPE UIActivate(
        BOOL fUIActivate) = 0;

    virtual HRESULT STDMETHODCALLTYPE Open(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CloseView(
        DWORD dwReserved) = 0;

    virtual HRESULT STDMETHODCALLTYPE SaveViewState(
        LPSTREAM pstm) = 0;

    virtual HRESULT STDMETHODCALLTYPE ApplyViewState(
        LPSTREAM pstm) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        IOleInPlaceSite* pIPSiteNew,
        IOleDocumentView** ppViewNew) = 0;

};
#else
typedef struct IOleDocumentViewVtbl IOleDocumentViewVtbl;
struct IOleDocumentView {
    const IOleDocumentViewVtbl* lpVtbl;
};
struct IOleDocumentViewVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IOleDocumentView* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IOleDocumentView* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IOleDocumentView* This);

    /*** IOleDocumentView methods ***/
    HRESULT (STDMETHODCALLTYPE *SetInPlaceSite)(
        IOleDocumentView* This,
        IOleInPlaceSite* pIPSite);

    HRESULT (STDMETHODCALLTYPE *GetInPlaceSite)(
        IOleDocumentView* This,
        IOleInPlaceSite** ppIPSite);

    HRESULT (STDMETHODCALLTYPE *GetDocument)(
        IOleDocumentView* This,
        IUnknown** ppunk);

    HRESULT (STDMETHODCALLTYPE *SetRect)(
        IOleDocumentView* This,
        LPRECT prcView);

    HRESULT (STDMETHODCALLTYPE *GetRect)(
        IOleDocumentView* This,
        LPRECT prcView);

    HRESULT (STDMETHODCALLTYPE *SetRectComplex)(
        IOleDocumentView* This,
        LPRECT prcView,
        LPRECT prcHScroll,
        LPRECT prcVScroll,
        LPRECT prcSizeBox);

    HRESULT (STDMETHODCALLTYPE *Show)(
        IOleDocumentView* This,
        BOOL fShow);

    HRESULT (STDMETHODCALLTYPE *UIActivate)(
        IOleDocumentView* This,
        BOOL fUIActivate);

    HRESULT (STDMETHODCALLTYPE *Open)(
        IOleDocumentView* This);

    HRESULT (STDMETHODCALLTYPE *CloseView)(
        IOleDocumentView* This,
        DWORD dwReserved);

    HRESULT (STDMETHODCALLTYPE *SaveViewState)(
        IOleDocumentView* This,
        LPSTREAM pstm);

    HRESULT (STDMETHODCALLTYPE *ApplyViewState)(
        IOleDocumentView* This,
        LPSTREAM pstm);

    HRESULT (STDMETHODCALLTYPE *Clone)(
        IOleDocumentView* This,
        IOleInPlaceSite* pIPSiteNew,
        IOleDocumentView** ppViewNew);

};

/*** IUnknown methods ***/
#define IOleDocumentView_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IOleDocumentView_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IOleDocumentView_Release(p) (p)->lpVtbl->Release(p)
/*** IOleDocumentView methods ***/
#define IOleDocumentView_SetInPlaceSite(p,a) (p)->lpVtbl->SetInPlaceSite(p,a)
#define IOleDocumentView_GetInPlaceSite(p,a) (p)->lpVtbl->GetInPlaceSite(p,a)
#define IOleDocumentView_GetDocument(p,a) (p)->lpVtbl->GetDocument(p,a)
#define IOleDocumentView_SetRect(p,a) (p)->lpVtbl->SetRect(p,a)
#define IOleDocumentView_GetRect(p,a) (p)->lpVtbl->GetRect(p,a)
#define IOleDocumentView_SetRectComplex(p,a,b,c,d) (p)->lpVtbl->SetRectComplex(p,a,b,c,d)
#define IOleDocumentView_Show(p,a) (p)->lpVtbl->Show(p,a)
#define IOleDocumentView_UIActivate(p,a) (p)->lpVtbl->UIActivate(p,a)
#define IOleDocumentView_Open(p) (p)->lpVtbl->Open(p)
#define IOleDocumentView_CloseView(p,a) (p)->lpVtbl->CloseView(p,a)
#define IOleDocumentView_SaveViewState(p,a) (p)->lpVtbl->SaveViewState(p,a)
#define IOleDocumentView_ApplyViewState(p,a) (p)->lpVtbl->ApplyViewState(p,a)
#define IOleDocumentView_Clone(p,a,b) (p)->lpVtbl->Clone(p,a,b)

#endif

#define IOleDocumentView_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IOleDocumentView methods ***/ \
    STDMETHOD_(HRESULT,SetInPlaceSite)(THIS_ IOleInPlaceSite* pIPSite) PURE; \
    STDMETHOD_(HRESULT,GetInPlaceSite)(THIS_ IOleInPlaceSite** ppIPSite) PURE; \
    STDMETHOD_(HRESULT,GetDocument)(THIS_ IUnknown** ppunk) PURE; \
    STDMETHOD_(HRESULT,SetRect)(THIS_ LPRECT prcView) PURE; \
    STDMETHOD_(HRESULT,GetRect)(THIS_ LPRECT prcView) PURE; \
    STDMETHOD_(HRESULT,SetRectComplex)(THIS_ LPRECT prcView, LPRECT prcHScroll, LPRECT prcVScroll, LPRECT prcSizeBox) PURE; \
    STDMETHOD_(HRESULT,Show)(THIS_ BOOL fShow) PURE; \
    STDMETHOD_(HRESULT,UIActivate)(THIS_ BOOL fUIActivate) PURE; \
    STDMETHOD_(HRESULT,Open)(THIS) PURE; \
    STDMETHOD_(HRESULT,CloseView)(THIS_ DWORD dwReserved) PURE; \
    STDMETHOD_(HRESULT,SaveViewState)(THIS_ LPSTREAM pstm) PURE; \
    STDMETHOD_(HRESULT,ApplyViewState)(THIS_ LPSTREAM pstm) PURE; \
    STDMETHOD_(HRESULT,Clone)(THIS_ IOleInPlaceSite* pIPSiteNew, IOleDocumentView** ppViewNew) PURE;

HRESULT CALLBACK IOleDocumentView_SetInPlaceSite_Proxy(
    IOleDocumentView* This,
    IOleInPlaceSite* pIPSite);
void __RPC_STUB IOleDocumentView_SetInPlaceSite_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_GetInPlaceSite_Proxy(
    IOleDocumentView* This,
    IOleInPlaceSite** ppIPSite);
void __RPC_STUB IOleDocumentView_GetInPlaceSite_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_GetDocument_Proxy(
    IOleDocumentView* This,
    IUnknown** ppunk);
void __RPC_STUB IOleDocumentView_GetDocument_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_SetRect_Proxy(
    IOleDocumentView* This,
    LPRECT prcView);
void __RPC_STUB IOleDocumentView_SetRect_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_GetRect_Proxy(
    IOleDocumentView* This,
    LPRECT prcView);
void __RPC_STUB IOleDocumentView_GetRect_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_SetRectComplex_Proxy(
    IOleDocumentView* This,
    LPRECT prcView,
    LPRECT prcHScroll,
    LPRECT prcVScroll,
    LPRECT prcSizeBox);
void __RPC_STUB IOleDocumentView_SetRectComplex_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_Show_Proxy(
    IOleDocumentView* This,
    BOOL fShow);
void __RPC_STUB IOleDocumentView_Show_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_UIActivate_Proxy(
    IOleDocumentView* This,
    BOOL fUIActivate);
void __RPC_STUB IOleDocumentView_UIActivate_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_Open_Proxy(
    IOleDocumentView* This);
void __RPC_STUB IOleDocumentView_Open_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_CloseView_Proxy(
    IOleDocumentView* This,
    DWORD dwReserved);
void __RPC_STUB IOleDocumentView_CloseView_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_SaveViewState_Proxy(
    IOleDocumentView* This,
    LPSTREAM pstm);
void __RPC_STUB IOleDocumentView_SaveViewState_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_ApplyViewState_Proxy(
    IOleDocumentView* This,
    LPSTREAM pstm);
void __RPC_STUB IOleDocumentView_ApplyViewState_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleDocumentView_Clone_Proxy(
    IOleDocumentView* This,
    IOleInPlaceSite* pIPSiteNew,
    IOleDocumentView** ppViewNew);
void __RPC_STUB IOleDocumentView_Clone_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IOleDocumentView_INTERFACE_DEFINED__ */

typedef IEnumOleDocumentViews *LPENUMOLEDOCUMENTVIEWS;

/*****************************************************************************
 * IEnumOleDocumentViews interface
 */
#ifndef __IEnumOleDocumentViews_INTERFACE_DEFINED__
#define __IEnumOleDocumentViews_INTERFACE_DEFINED__

DEFINE_GUID(IID_IEnumOleDocumentViews, 0xb722bcc8, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IEnumOleDocumentViews : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(
        ULONG cViews,
        IOleDocumentView** rgpView,
        ULONG* pcFetched) = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        ULONG cViews) = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        IEnumOleDocumentViews** ppEnum) = 0;

};
#else
typedef struct IEnumOleDocumentViewsVtbl IEnumOleDocumentViewsVtbl;
struct IEnumOleDocumentViews {
    const IEnumOleDocumentViewsVtbl* lpVtbl;
};
struct IEnumOleDocumentViewsVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IEnumOleDocumentViews* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IEnumOleDocumentViews* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IEnumOleDocumentViews* This);

    /*** IEnumOleDocumentViews methods ***/
    HRESULT (STDMETHODCALLTYPE *Next)(
        IEnumOleDocumentViews* This,
        ULONG cViews,
        IOleDocumentView** rgpView,
        ULONG* pcFetched);

    HRESULT (STDMETHODCALLTYPE *Skip)(
        IEnumOleDocumentViews* This,
        ULONG cViews);

    HRESULT (STDMETHODCALLTYPE *Reset)(
        IEnumOleDocumentViews* This);

    HRESULT (STDMETHODCALLTYPE *Clone)(
        IEnumOleDocumentViews* This,
        IEnumOleDocumentViews** ppEnum);

};

/*** IUnknown methods ***/
#define IEnumOleDocumentViews_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IEnumOleDocumentViews_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IEnumOleDocumentViews_Release(p) (p)->lpVtbl->Release(p)
/*** IEnumOleDocumentViews methods ***/
#define IEnumOleDocumentViews_Next(p,a,b,c) (p)->lpVtbl->Next(p,a,b,c)
#define IEnumOleDocumentViews_Skip(p,a) (p)->lpVtbl->Skip(p,a)
#define IEnumOleDocumentViews_Reset(p) (p)->lpVtbl->Reset(p)
#define IEnumOleDocumentViews_Clone(p,a) (p)->lpVtbl->Clone(p,a)

#endif

#define IEnumOleDocumentViews_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IEnumOleDocumentViews methods ***/ \
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG cViews, IOleDocumentView** rgpView, ULONG* pcFetched) PURE; \
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG cViews) PURE; \
    STDMETHOD_(HRESULT,Reset)(THIS) PURE; \
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumOleDocumentViews** ppEnum) PURE;

HRESULT CALLBACK IEnumOleDocumentViews_RemoteNext_Proxy(
    IEnumOleDocumentViews* This,
    ULONG cViews,
    IOleDocumentView** rgpView,
    ULONG* pcFetched);
void __RPC_STUB IEnumOleDocumentViews_RemoteNext_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IEnumOleDocumentViews_Next_Proxy(
    IEnumOleDocumentViews* This,
    ULONG cViews,
    IOleDocumentView** rgpView,
    ULONG* pcFetched);
HRESULT __RPC_STUB IEnumOleDocumentViews_Next_Stub(
    IEnumOleDocumentViews* This,
    ULONG cViews,
    IOleDocumentView** rgpView,
    ULONG* pcFetched);
HRESULT CALLBACK IEnumOleDocumentViews_Skip_Proxy(
    IEnumOleDocumentViews* This,
    ULONG cViews);
void __RPC_STUB IEnumOleDocumentViews_Skip_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IEnumOleDocumentViews_Reset_Proxy(
    IEnumOleDocumentViews* This);
void __RPC_STUB IEnumOleDocumentViews_Reset_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IEnumOleDocumentViews_Clone_Proxy(
    IEnumOleDocumentViews* This,
    IEnumOleDocumentViews** ppEnum);
void __RPC_STUB IEnumOleDocumentViews_Clone_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IEnumOleDocumentViews_INTERFACE_DEFINED__ */

#ifndef __IOleCommandTarget_FWD_DEFINED__
#define __IOleCommandTarget_FWD_DEFINED__
typedef struct IOleCommandTarget IOleCommandTarget;
#endif

typedef IOleCommandTarget *LPOLECOMMANDTARGET;

typedef enum {
    OLECMDF_SUPPORTED = 0x1,
    OLECMDF_ENABLED = 0x2,
    OLECMDF_LATCHED = 0x4,
    OLECMDF_NINCHED = 0x8,
    OLECMDF_INVISIBLE = 0x10,
    OLECMDF_DEFHIDEONCTXTMENU = 0x20
} OLECMDF;

typedef struct _tagOLECMD {
    ULONG cmdID;
    DWORD cmdf;
} OLECMD;

typedef struct _tagOLECMDTEXT {
    DWORD cmdtextf;
    ULONG cwActual;
    ULONG cwBuf;
    WCHAR rgwz[1];
} OLECMDTEXT;

typedef enum {
    OLECMDTEXTF_NONE = 0,
    OLECMDTEXTF_NAME = 1,
    OLECMDTEXTF_STATUS = 2
} OLECMDTEXTF;

typedef enum {
    OLECMDEXECOPT_DODEFAULT = 0,
    OLECMDEXECOPT_PROMPTUSER = 1,
    OLECMDEXECOPT_DONTPROMPTUSER = 2,
    OLECMDEXECOPT_SHOWHELP = 3
} OLECMDEXECOPT;

typedef enum OLECMDID {
    OLECMDID_OPEN = 1,
    OLECMDID_NEW = 2,
    OLECMDID_SAVE = 3,
    OLECMDID_SAVEAS = 4,
    OLECMDID_SAVECOPYAS = 5,
    OLECMDID_PRINT = 6,
    OLECMDID_PRINTPREVIEW = 7,
    OLECMDID_PAGESETUP = 8,
    OLECMDID_SPELL = 9,
    OLECMDID_PROPERTIES = 10,
    OLECMDID_CUT = 11,
    OLECMDID_COPY = 12,
    OLECMDID_PASTE = 13,
    OLECMDID_PASTESPECIAL = 14,
    OLECMDID_UNDO = 15,
    OLECMDID_REDO = 16,
    OLECMDID_SELECTALL = 17,
    OLECMDID_CLEARSELECTION = 18,
    OLECMDID_ZOOM = 19,
    OLECMDID_GETZOOMRANGE = 20,
    OLECMDID_UPDATECOMMANDS = 21,
    OLECMDID_REFRESH = 22,
    OLECMDID_STOP = 23,
    OLECMDID_HIDETOOLBARS = 24,
    OLECMDID_SETPROGRESSMAX = 25,
    OLECMDID_SETPROGRESSPOS = 26,
    OLECMDID_SETPROGRESSTEXT = 27,
    OLECMDID_SETTITLE = 28,
    OLECMDID_SETDOWNLOADSTATE = 29,
    OLECMDID_STOPDOWNLOAD = 30,
    OLECMDID_ONTOOLBARACTIVATED = 31,
    OLECMDID_FIND = 32,
    OLECMDID_DELETE = 33,
    OLECMDID_HTTPEQUIV = 34,
    OLECMDID_HTTPEQUIV_DONE = 35,
    OLECMDID_ENABLE_INTERACTION = 36,
    OLECMDID_ONUNLOAD = 37,
    OLECMDID_PROPERTYBAG2 = 38,
    OLECMDID_PREREFRESH = 39,
    OLECMDID_SHOWSCRIPTERROR = 40,
    OLECMDID_SHOWMESSAGE = 41,
    OLECMDID_SHOWFIND = 42,
    OLECMDID_SHOWPAGESETUP = 43,
    OLECMDID_SHOWPRINT = 44,
    OLECMDID_CLOSE = 45,
    OLECMDID_ALLOWUILESSSAVEAS = 46,
    OLECMDID_DONTDOWNLOADCSS = 47,
    OLECMDID_UPDATEPAGESTATUS = 48,
    OLECMDID_PRINT2 = 49,
    OLECMDID_PRINTPREVIEW2 = 50,
    OLECMDID_SETPRINTTEMPLATE = 51,
    OLECMDID_GETPRINTTEMPLATE = 52
} OLECMDID;

/*****************************************************************************
 * IOleCommandTarget interface
 */
#ifndef __IOleCommandTarget_INTERFACE_DEFINED__
#define __IOleCommandTarget_INTERFACE_DEFINED__

DEFINE_GUID(IID_IOleCommandTarget, 0xb722bccb, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IOleCommandTarget : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE QueryStatus(
        const GUID* pguidCmdGroup,
        ULONG cCmds,
        OLECMD prgCmds[],
        OLECMDTEXT* pCmdText) = 0;

    virtual HRESULT STDMETHODCALLTYPE Exec(
        const GUID* pguidCmdGroup,
        DWORD nCmdID,
        DWORD nCmdexecopt,
        VARIANT* pvaIn,
        VARIANT* pvaOut) = 0;

};
#else
typedef struct IOleCommandTargetVtbl IOleCommandTargetVtbl;
struct IOleCommandTarget {
    const IOleCommandTargetVtbl* lpVtbl;
};
struct IOleCommandTargetVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IOleCommandTarget* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IOleCommandTarget* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IOleCommandTarget* This);

    /*** IOleCommandTarget methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryStatus)(
        IOleCommandTarget* This,
        const GUID* pguidCmdGroup,
        ULONG cCmds,
        OLECMD prgCmds[],
        OLECMDTEXT* pCmdText);

    HRESULT (STDMETHODCALLTYPE *Exec)(
        IOleCommandTarget* This,
        const GUID* pguidCmdGroup,
        DWORD nCmdID,
        DWORD nCmdexecopt,
        VARIANT* pvaIn,
        VARIANT* pvaOut);

};

/*** IUnknown methods ***/
#define IOleCommandTarget_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IOleCommandTarget_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IOleCommandTarget_Release(p) (p)->lpVtbl->Release(p)
/*** IOleCommandTarget methods ***/
#define IOleCommandTarget_QueryStatus(p,a,b,c,d) (p)->lpVtbl->QueryStatus(p,a,b,c,d)
#define IOleCommandTarget_Exec(p,a,b,c,d,e) (p)->lpVtbl->Exec(p,a,b,c,d,e)

#endif

#define IOleCommandTarget_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IOleCommandTarget methods ***/ \
    STDMETHOD_(HRESULT,QueryStatus)(THIS_ const GUID* pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT* pCmdText) PURE; \
    STDMETHOD_(HRESULT,Exec)(THIS_ const GUID* pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT* pvaIn, VARIANT* pvaOut) PURE;

HRESULT CALLBACK IOleCommandTarget_QueryStatus_Proxy(
    IOleCommandTarget* This,
    const GUID* pguidCmdGroup,
    ULONG cCmds,
    OLECMD prgCmds[],
    OLECMDTEXT* pCmdText);
void __RPC_STUB IOleCommandTarget_QueryStatus_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IOleCommandTarget_Exec_Proxy(
    IOleCommandTarget* This,
    const GUID* pguidCmdGroup,
    DWORD nCmdID,
    DWORD nCmdexecopt,
    VARIANT* pvaIn,
    VARIANT* pvaOut);
void __RPC_STUB IOleCommandTarget_Exec_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IOleCommandTarget_INTERFACE_DEFINED__ */

#ifndef __IContinueCallback_FWD_DEFINED__
#define __IContinueCallback_FWD_DEFINED__
typedef struct IContinueCallback IContinueCallback;
#endif

typedef IContinueCallback *LPCONTINUECALLBACK;

/*****************************************************************************
 * IContinueCallback interface
 */
#ifndef __IContinueCallback_INTERFACE_DEFINED__
#define __IContinueCallback_INTERFACE_DEFINED__

DEFINE_GUID(IID_IContinueCallback, 0xb722bcca, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IContinueCallback : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE FContinue(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE FContinuePrinting(
        LONG nCntPrinted,
        LONG nCurPage,
        WCHAR* pwszPrintStatus) = 0;

};
#else
typedef struct IContinueCallbackVtbl IContinueCallbackVtbl;
struct IContinueCallback {
    const IContinueCallbackVtbl* lpVtbl;
};
struct IContinueCallbackVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IContinueCallback* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IContinueCallback* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IContinueCallback* This);

    /*** IContinueCallback methods ***/
    HRESULT (STDMETHODCALLTYPE *FContinue)(
        IContinueCallback* This);

    HRESULT (STDMETHODCALLTYPE *FContinuePrinting)(
        IContinueCallback* This,
        LONG nCntPrinted,
        LONG nCurPage,
        WCHAR* pwszPrintStatus);

};

/*** IUnknown methods ***/
#define IContinueCallback_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IContinueCallback_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IContinueCallback_Release(p) (p)->lpVtbl->Release(p)
/*** IContinueCallback methods ***/
#define IContinueCallback_FContinue(p) (p)->lpVtbl->FContinue(p)
#define IContinueCallback_FContinuePrinting(p,a,b,c) (p)->lpVtbl->FContinuePrinting(p,a,b,c)

#endif

#define IContinueCallback_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IContinueCallback methods ***/ \
    STDMETHOD_(HRESULT,FContinue)(THIS) PURE; \
    STDMETHOD_(HRESULT,FContinuePrinting)(THIS_ LONG nCntPrinted, LONG nCurPage, WCHAR* pwszPrintStatus) PURE;

HRESULT CALLBACK IContinueCallback_FContinue_Proxy(
    IContinueCallback* This);
void __RPC_STUB IContinueCallback_FContinue_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IContinueCallback_FContinuePrinting_Proxy(
    IContinueCallback* This,
    LONG nCntPrinted,
    LONG nCurPage,
    WCHAR* pwszPrintStatus);
void __RPC_STUB IContinueCallback_FContinuePrinting_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IContinueCallback_INTERFACE_DEFINED__ */

#ifndef __IPrint_FWD_DEFINED__
#define __IPrint_FWD_DEFINED__
typedef struct IPrint IPrint;
#endif

typedef IPrint *LPPRINT;

typedef enum {
    PRINTFLAG_MAYBOTHERUSER = 1,
    PRINTFLAG_PROMPTUSER = 2,
    PRINTFLAG_USERMAYCHANGEPRINTER = 4,
    PRINTFLAG_RECOMPOSETODEVICE = 8,
    PRINTFLAG_DONTACTUALLYPRINT = 16,
    PRINTFLAG_FORCEPROPERTIES = 32,
    PRINTFLAG_PRINTTOFILE = 64
} PRINTFLAG;

typedef struct tagPAGERANGE {
    LONG nFromPage;
    LONG nToPage;
} PAGERANGE;

typedef struct tagPAGESET {
    ULONG cbStruct;
    BOOL fOddPages;
    BOOL fEvenPages;
    ULONG cPageRange;
    PAGERANGE rgPages[1];
} PAGESET;

/*****************************************************************************
 * IPrint interface
 */
#ifndef __IPrint_INTERFACE_DEFINED__
#define __IPrint_INTERFACE_DEFINED__

DEFINE_GUID(IID_IPrint, 0xb722bcc9, 0x4e68, 0x101b, 0xa2,0xbc, 0x00,0xaa,0x00,0x40,0x47,0x70);
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IPrint : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetInitialPageNum(
        LONG nFirstPage) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPageInfo(
        LONG* pnFirstPage,
        LONG* pcPages) = 0;

    virtual HRESULT STDMETHODCALLTYPE Print(
        DWORD grfFlags,
        DVTARGETDEVICE** pptd,
        PAGESET** ppPageSet,
        STGMEDIUM* pstgmOptions,
        IContinueCallback* pcallback,
        LONG nFirstPage,
        LONG* pcPagesPrinted,
        LONG* pnLastPage) = 0;

};
#else
typedef struct IPrintVtbl IPrintVtbl;
struct IPrint {
    const IPrintVtbl* lpVtbl;
};
struct IPrintVtbl {
    ICOM_MSVTABLE_COMPAT_FIELDS

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IPrint* This,
        REFIID riid,
        void** ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IPrint* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IPrint* This);

    /*** IPrint methods ***/
    HRESULT (STDMETHODCALLTYPE *SetInitialPageNum)(
        IPrint* This,
        LONG nFirstPage);

    HRESULT (STDMETHODCALLTYPE *GetPageInfo)(
        IPrint* This,
        LONG* pnFirstPage,
        LONG* pcPages);

    HRESULT (STDMETHODCALLTYPE *Print)(
        IPrint* This,
        DWORD grfFlags,
        DVTARGETDEVICE** pptd,
        PAGESET** ppPageSet,
        STGMEDIUM* pstgmOptions,
        IContinueCallback* pcallback,
        LONG nFirstPage,
        LONG* pcPagesPrinted,
        LONG* pnLastPage);

};

/*** IUnknown methods ***/
#define IPrint_QueryInterface(p,a,b) (p)->lpVtbl->QueryInterface(p,a,b)
#define IPrint_AddRef(p) (p)->lpVtbl->AddRef(p)
#define IPrint_Release(p) (p)->lpVtbl->Release(p)
/*** IPrint methods ***/
#define IPrint_SetInitialPageNum(p,a) (p)->lpVtbl->SetInitialPageNum(p,a)
#define IPrint_GetPageInfo(p,a,b) (p)->lpVtbl->GetPageInfo(p,a,b)
#define IPrint_Print(p,a,b,c,d,e,f,g,h) (p)->lpVtbl->Print(p,a,b,c,d,e,f,g,h)

#endif

#define IPrint_METHODS \
    ICOM_MSVTABLE_COMPAT_FIELDS \
    /*** IUnknown methods ***/ \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE; \
    STDMETHOD_(ULONG,AddRef)(THIS) PURE; \
    STDMETHOD_(ULONG,Release)(THIS) PURE; \
    /*** IPrint methods ***/ \
    STDMETHOD_(HRESULT,SetInitialPageNum)(THIS_ LONG nFirstPage) PURE; \
    STDMETHOD_(HRESULT,GetPageInfo)(THIS_ LONG* pnFirstPage, LONG* pcPages) PURE; \
    STDMETHOD_(HRESULT,Print)(THIS_ DWORD grfFlags, DVTARGETDEVICE** pptd, PAGESET** ppPageSet, STGMEDIUM* pstgmOptions, IContinueCallback* pcallback, LONG nFirstPage, LONG* pcPagesPrinted, LONG* pnLastPage) PURE;

HRESULT CALLBACK IPrint_SetInitialPageNum_Proxy(
    IPrint* This,
    LONG nFirstPage);
void __RPC_STUB IPrint_SetInitialPageNum_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IPrint_GetPageInfo_Proxy(
    IPrint* This,
    LONG* pnFirstPage,
    LONG* pcPages);
void __RPC_STUB IPrint_GetPageInfo_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IPrint_RemotePrint_Proxy(
    IPrint* This,
    DWORD grfFlags,
    DVTARGETDEVICE** pptd,
    PAGESET** pppageset,
    RemSTGMEDIUM* pstgmOptions,
    IContinueCallback* pcallback,
    LONG nFirstPage,
    LONG* pcPagesPrinted,
    LONG* pnLastPage);
void __RPC_STUB IPrint_RemotePrint_Stub(
    struct IRpcStubBuffer* This,
    struct IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IPrint_Print_Proxy(
    IPrint* This,
    DWORD grfFlags,
    DVTARGETDEVICE** pptd,
    PAGESET** ppPageSet,
    STGMEDIUM* pstgmOptions,
    IContinueCallback* pcallback,
    LONG nFirstPage,
    LONG* pcPagesPrinted,
    LONG* pnLastPage);
HRESULT __RPC_STUB IPrint_Print_Stub(
    IPrint* This,
    DWORD grfFlags,
    DVTARGETDEVICE** pptd,
    PAGESET** pppageset,
    RemSTGMEDIUM* pstgmOptions,
    IContinueCallback* pcallback,
    LONG nFirstPage,
    LONG* pcPagesPrinted,
    LONG* pnLastPage);

#endif  /* __IPrint_INTERFACE_DEFINED__ */

#define OLECMDERR_E_FIRST            (OLE_E_LAST+1)
#define OLECMDERR_E_NOTSUPPORTED     (OLECMDERR_E_FIRST)
#define OLECMDERR_E_DISABLED         (OLECMDERR_E_FIRST+1)
#define OLECMDERR_E_NOHELP           (OLECMDERR_E_FIRST+2)
#define OLECMDERR_E_CANCELED         (OLECMDERR_E_FIRST+3)
#define OLECMDERR_E_UNKNOWNGROUP     (OLECMDERR_E_FIRST+4)
#define MSOCMDERR_E_FIRST OLECMDERR_E_FIRST
#define MSOCMDERR_E_NOTSUPPORTED OLECMDERR_E_NOTSUPPORTED
#define MSOCMDERR_E_DISABLED OLECMDERR_E_DISABLED
#define MSOCMDERR_E_NOHELP OLECMDERR_E_NOHELP
#define MSOCMDERR_E_CANCELED OLECMDERR_E_CANCELED
#define MSOCMDERR_E_UNKNOWNGROUP OLECMDERR_E_UNKNOWNGROUP
#define LPMSODOCUMENT                  LPOLEDOCUMENT
#define LPMSODOCUMENTSITE              LPOLEDOCUMENTSITE
#define LPMSOVIEW                      LPOLEDOCUMENTVIEW
#define LPENUMMSOVIEW                  LPENUMOLEDOCUMENTVIEWS
#define LPMSOCOMMANDTARGET             LPOLECOMMANDTARGET
#define IID_IMsoDocument               IID_IOleDocument
#define IID_IMsoDocumentSite           IID_IOleDocumentSite
#define IID_IMsoView                   IID_IOleDocumentView
#define IID_IEnumMsoView               IID_IEnumOleDocumentViews
#define IID_IMsoCommandTarget          IID_IOleCommandTarget
#ifdef __cplusplus
}
#endif
#endif /* __WIDL_DOCOBJ_H */


/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for GoodPreviewer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __GoodPreviewer_i_h__
#define __GoodPreviewer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPreview_FWD_DEFINED__
#define __IPreview_FWD_DEFINED__
typedef interface IPreview IPreview;

#endif 	/* __IPreview_FWD_DEFINED__ */


#ifndef __Preview_FWD_DEFINED__
#define __Preview_FWD_DEFINED__

#ifdef __cplusplus
typedef class Preview Preview;
#else
typedef struct Preview Preview;
#endif /* __cplusplus */

#endif 	/* __Preview_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IPreview_INTERFACE_DEFINED__
#define __IPreview_INTERFACE_DEFINED__

/* interface IPreview */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPreview;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a886844e-09d0-4c7d-8490-fa851caee5a1")
    IPreview : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IPreviewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPreview * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPreview * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPreview * This);
        
        END_INTERFACE
    } IPreviewVtbl;

    interface IPreview
    {
        CONST_VTBL struct IPreviewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPreview_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPreview_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPreview_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPreview_INTERFACE_DEFINED__ */



#ifndef __GoodPreviewerLib_LIBRARY_DEFINED__
#define __GoodPreviewerLib_LIBRARY_DEFINED__

/* library GoodPreviewerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_GoodPreviewerLib;

EXTERN_C const CLSID CLSID_Preview;

#ifdef __cplusplus

class DECLSPEC_UUID("41633890-5210-4e9f-85e0-c2fa3c870286")
Preview;
#endif
#endif /* __GoodPreviewerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



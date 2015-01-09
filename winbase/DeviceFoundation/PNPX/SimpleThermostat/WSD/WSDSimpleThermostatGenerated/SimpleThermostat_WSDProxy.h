// <Include>
///////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT BY HAND.
//
///////////////////////////////////////////////////////////////////////////////
// </Include>

// <Include>
#pragma once
// </Include>

// <CDATA>

class CSimpleThermostat_WSDProxy;

// </CDATA>

// <ProxyBuilderDeclarations>
HRESULT CreateCSimpleThermostat_WSDProxy(
                LPCWSTR pszDeviceAddress,
                LPCWSTR pszLocalAddress,
                CSimpleThermostat_WSDProxy** ppProxyOut,
                IWSDXMLContext** ppContextOut);
// </ProxyBuilderDeclarations>

// <CDATA>

class CSimpleThermostat_WSDProxy: public ISimpleThermostat_WSDProxy
{
private:
    ~CSimpleThermostat_WSDProxy();
    LONG m_cRef;
    IWSDServiceProxy* m_genericProxy;

public:
    HRESULT STDMETHODCALLTYPE Init(IWSDServiceProxy* genericProxy);
    CSimpleThermostat_WSDProxy();

// </CDATA>

// <IUnknownDeclarations>
    // 
    // IUnknown
    // 
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    ULONG STDMETHODCALLTYPE AddRef();
    ULONG STDMETHODCALLTYPE Release();
// </IUnknownDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    GetCurrentTemp
    (   /* [out] */ LONG* tempOut
    );

    HRESULT STDMETHODCALLTYPE
    GetDesiredTemp
    (   /* [out] */ LONG* tempOut
    );

    HRESULT STDMETHODCALLTYPE
    SetDesiredTemp
    (   /* [in] */ LONG temp
    );

// </FunctionDeclarations>

// <FunctionDeclarations>
    HRESULT STDMETHODCALLTYPE
    BeginGetCurrentTemp
    (   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetCurrentTemp
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ LONG* tempOut
    );

    HRESULT STDMETHODCALLTYPE
    BeginGetDesiredTemp
    (   /* [in] */ IUnknown* AsyncState
    ,   /* [in] */ IWSDAsyncCallback* AsyncCallback
    ,   /* [out] */ IWSDAsyncResult** AsyncResultOut
    );

    HRESULT STDMETHODCALLTYPE
    EndGetDesiredTemp
    (   /* [in] */ IWSDAsyncResult* AsyncResult
    ,   /* [out] */ LONG* tempOut
    );

// </FunctionDeclarations>

// <CDATA>

};

// </CDATA>


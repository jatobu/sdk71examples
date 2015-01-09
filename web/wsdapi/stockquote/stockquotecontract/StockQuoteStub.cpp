// <Include>
///////////////////////////////////////////////////////////////////////////////
//
// THIS FILE IS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT BY HAND.
//
///////////////////////////////////////////////////////////////////////////////
// </Include>

// <LiteralInclude>
#include <wsdapi.h>
// </LiteralInclude>

// <LiteralInclude>
#include "StockQuote.h"
// </LiteralInclude>

// <LiteralInclude>
#include "StockQuoteTypes.h"
// </LiteralInclude>

// <MessageTypeDeclarations>
//
// Port type http://example.com/stockquote/definitions/StockQuotePortType
// Message type declarations
//
extern WSDXML_TYPE REQUESTTYPE_GetLastTradePrice;
extern WSDXML_TYPE RESPONSETYPE_GetLastTradePrice;

//
// Port type http://example.com/stockquote/definitions/StockQuoteDeviceType
// Message type declarations
//

// </MessageTypeDeclarations>

// <HostBuilderImplementation>
HRESULT CreateStockQuoteHost(
                LPCWSTR pszDeviceAddress,
                const WSD_THIS_DEVICE_METADATA* pThisDeviceMetadata,
                IStockQuote* pIStockQuote,
                IWSDDeviceHost** ppHostOut,
                IWSDXMLContext** ppContextOut)
{
    HRESULT hr = S_OK;
    IWSDXMLContext* pContext = NULL;
    IWSDDeviceHost* pHost = NULL;

    // 
    // Validate parameters
    // 
    if( NULL == pszDeviceAddress )
    {
        return E_INVALIDARG;
    }

    if( NULL == pThisDeviceMetadata )
    {
        return E_INVALIDARG;
    }

    // pIStockQuote is optional
    if( NULL == ppHostOut )
    {
        return E_POINTER;
    }

    // ppContextOut is optional

    *ppHostOut = NULL;
    if( NULL != ppContextOut )
    {
        *ppContextOut = NULL;
    }

    // 
    // Create XML context for namespace and type registration
    // 
    hr = WSDXMLCreateContext(&pContext);

    // 
    // Register types used by the service
    // 
    if( S_OK == hr )
    {
        hr = StockQuoteRegisterTypes(pContext);
    }

    // 
    // Register namespaces used by the service
    // 
    if( S_OK == hr )
    {
        hr = StockQuoteRegisterNamespaces(pContext);
    }

    // 
    // Create device host
    // 
    if( S_OK == hr )
    {
        hr = WSDCreateDeviceHost(pszDeviceAddress, pContext, &pHost);
    }

    // 
    // Register port types
    // 
    if( S_OK == hr )
    {
        hr = pHost->RegisterPortType(&PortType_StockQuotePortType);
    }

    // 
    // Set metadata
    // 
    if( S_OK == hr )
    {
        hr = pHost->SetMetadata(&thisModelMetadata, pThisDeviceMetadata, &hostMetadata, NULL);
    }

    // 
    // Register services and set discoverability
    // 
    if( S_OK == hr && pIStockQuote != NULL )
    {
        hr = pHost->RegisterService(L"http://example.com/stockquote/definitions/StockQuotePortType0", pIStockQuote);
    }

    // 
    // Cleanup
    // 
    if( S_OK == hr && ppContextOut )
    {
        *ppContextOut = pContext;
    }
    else
    {
        if( NULL != pContext )
        {
            pContext->Release();
        }
    }

    if( S_OK == hr )
    {
        *ppHostOut = pHost;
    }
    else
    {
        if( NULL != pHost )
        {
            pHost->Release();
        }
    }

    return hr;
}

// </HostBuilderImplementation>

// <StubDefinitions>
HRESULT __stdcall
Stub_GetLastTradePrice
(   IUnknown* server
,   IWSDServiceMessaging* service
,   WSD_EVENT* event
)
{
    HRESULT hr = S_OK;
    IStockQuote* pServer = NULL;

    REQUESTBODY_StockQuotePortType_GetLastTradePrice* p = reinterpret_cast<REQUESTBODY_StockQuotePortType_GetLastTradePrice*>(event->Soap->Body);
    RESPONSEBODY_StockQuotePortType_GetLastTradePrice result;
    ::ZeroMemory(&result,sizeof(result));

    hr = server->QueryInterface( __uuidof(IStockQuote), (void**)&pServer );
    if( S_OK == hr )
    {
        hr =
        pServer->GetLastTradePrice
        (   p->body
        ,   &result.body
        );

        pServer->Release();
        pServer = NULL;
    }
    if (SUCCEEDED(hr))
    {
        hr = service->SendResponse(&result,event->Operation,event->MessageParameters);
    }
    if (FAILED(hr))
    {
        hr = service->FaultRequest(&event->Soap->Header,event->MessageParameters, NULL);
    }

    // Clean up memory from outparams
    if (NULL != result.body)
    {
        WSDFreeLinkedMemory( (void*) (result.body) );
    }

    return hr;
}

// </StubDefinitions>


//#ifndef __ADAPTER_H
//#define __ADAPTER_H

// Prototypes for standard NDIS miniport entry points
MINIPORT_INITIALIZE                 MPInitializeEx;
MINIPORT_HALT                       MPHaltEx;
MINIPORT_UNLOAD                     DriverUnload;
MINIPORT_PAUSE                      MPPause;
MINIPORT_RESTART                    MPRestart;
MINIPORT_SEND_NET_BUFFER_LISTS      MPSendNetBufferLists;
MINIPORT_RETURN_NET_BUFFER_LISTS    MPReturnNetBufferLists;
MINIPORT_CANCEL_SEND                MPCancelSend;
MINIPORT_CHECK_FOR_HANG             MPCheckForHangEx;
MINIPORT_RESET                      MPResetEx;
MINIPORT_DEVICE_PNP_EVENT_NOTIFY    MPDevicePnpEventNotify;
MINIPORT_SHUTDOWN                   MPShutdownEx;
MINIPORT_CANCEL_OID_REQUEST         MPCancelOidRequest;

//#endif
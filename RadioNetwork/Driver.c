#include "driver.h"
#include "driver.tmh"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, RadioNetworkEvtDeviceAdd)
#pragma alloc_text (PAGE, RadioNetworkEvtDriverContextCleanup)
#endif

//MP_GLOBAL       GlobalData;
LIST_ENTRY g_globalAdapters;
NPAGED_LOOKASIDE_LIST   FrameDataLookaside;

NDIS_MINIPORT_DRIVER_CHARACTERISTICS g_MiniportCharacteristics;
NDIS_HANDLE g_miniPortHandle;

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject,_In_ PUNICODE_STRING RegistryPath)
{
	WDF_DRIVER_CONFIG config;
	NTSTATUS status;
	WDF_OBJECT_ATTRIBUTES attributes;

	//
	// Initialize WPP Tracing
	//
	WPP_INIT_TRACING( DriverObject, RegistryPath );

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

	// Register a cleanup callback so that we can call WPP_CLEANUP when
	// the framework driver object is deleted during driver unload.
	//
	WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
	attributes.EvtCleanupCallback = RadioNetworkEvtDriverContextCleanup;

	WDF_DRIVER_CONFIG_INIT(&config,
		RadioNetworkEvtDeviceAdd
		);

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");
	status = WdfDriverCreate(DriverObject,
		RegistryPath,
		&attributes,
		&config,
		WDF_NO_HANDLE
		);

	if (!NT_SUCCESS(status)) {
		TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "WdfDriverCreate failed %!STATUS!", status);
		WPP_CLEANUP(DriverObject);
		return status;
	}

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

	NdisZeroMemory(&g_MiniportCharacteristics,sizeof(g_MiniportCharacteristics));

	g_MiniportCharacteristics.MajorNdisVersion = MP_NDIS_MAJOR_VERSION;
	g_MiniportCharacteristics.MinorNdisVersion = MP_NDIS_MINOR_VERSION;

	// From sample....
	g_MiniportCharacteristics.MajorDriverVersion = 4;
	g_MiniportCharacteristics.MinorDriverVersion = 2;

	g_MiniportCharacteristics.Flags = 0;

#if 0
	g_MiniportCharacteristics.SetOptionsHandler = MPSetOptions; // Optional
	g_MiniportCharacteristics.InitializeHandlerEx = MPInitializeEx;
	g_MiniportCharacteristics.HaltHandlerEx = MPHaltEx;
	g_MiniportCharacteristics.UnloadHandler = DriverUnload;
	g_MiniportCharacteristics.PauseHandler = MPPause;
	g_MiniportCharacteristics.RestartHandler = MPRestart;
	g_MiniportCharacteristics.OidRequestHandler = MPOidRequest;
	g_MiniportCharacteristics.SendNetBufferListsHandler = MPSendNetBufferLists;
	g_MiniportCharacteristics.ReturnNetBufferListsHandler = MPReturnNetBufferLists;
	g_MiniportCharacteristics.CancelSendHandler = MPCancelSend;
	g_MiniportCharacteristics.CheckForHangHandlerEx = MPCheckForHangEx;
	g_MiniportCharacteristics.ResetHandlerEx = MPResetEx;
	g_MiniportCharacteristics.DevicePnPEventNotifyHandler = MPDevicePnpEventNotify;
	g_MiniportCharacteristics.ShutdownHandlerEx = MPShutdownEx;
	g_MiniportCharacteristics.CancelOidRequestHandler = MPCancelOidRequest;

	status = NdisMRegisterMiniportDriver(DriverObject,RegistryPath,NULL,&g_MiniportCharacteristics,&g_miniPortHandle);
#endif
	return status;
}

NTSTATUS RadioNetworkEvtDeviceAdd(_In_ WDFDRIVER Driver,_Inout_ PWDFDEVICE_INIT DeviceInit)
{
	NTSTATUS status;

	UNREFERENCED_PARAMETER(Driver);

	PAGED_CODE();

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

	status = RadioNetworkCreateDevice(DeviceInit);

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

	return status;
}

VOID RadioNetworkEvtDriverContextCleanup(_In_ WDFOBJECT DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);

	PAGED_CODE ();

	TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

	//
	// Stop WPP Tracing
	//
	WPP_CLEANUP( WdfDriverWdmGetDriverObject(DriverObject) );

}

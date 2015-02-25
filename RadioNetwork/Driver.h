/*++

Module Name:

    driver.h

Abstract:

    This file contains the driver definitions.

Environment:

    Kernel-mode Driver Framework

--*/

#define INITGUID

#include <ntddk.h>
#include <wdf.h>


#define MP_NDIS_MAJOR_VERSION             6
#define MP_NDIS_MINOR_VERSION             0
#define NDIS60_MINIPORT 1
#define NDIS_MINIPORT_DRIVER 1

#include <ndis.h>

#include "device.h"
#include "queue.h"
#include "trace.h"

//
// WDFDRIVER Events
//

DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD RadioNetworkEvtDeviceAdd;
EVT_WDF_OBJECT_CONTEXT_CLEANUP RadioNetworkEvtDriverContextCleanup;


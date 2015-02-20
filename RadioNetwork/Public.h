/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that app can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_RadioNetwork,
    0x86dcccdf,0x350d,0x4d38,0xb8,0x33,0x2e,0xc8,0x23,0x02,0x0d,0x16);
// {86dcccdf-350d-4d38-b833-2ec823020d16}

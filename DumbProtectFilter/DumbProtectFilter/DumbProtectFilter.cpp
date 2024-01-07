#include <fltKernel.h>
#include "FilterFunc.h"
#include "Comms.h"

PFLT_FILTER g_Filter;
extern PFLT_PORT g_pServerPort;
extern PFLT_PORT g_pClientPort;

extern "C"
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegPath) {

	DbgPrint("[DUMBPROTECT] [+] Starting registration\n");

	NTSTATUS status = FltRegisterFilter(pDriverObject, &InstanceRegistration, &g_Filter);

	if (!NT_SUCCESS(status)) {
		DbgPrint("[DUMBPROTECT] [!] Could not register filter\n");
		return status;
	}

	OBJECT_ATTRIBUTES objAttr;
	PSECURITY_DESCRIPTOR pSecDesc;
	UNICODE_STRING portName = RTL_CONSTANT_STRING(L"\\DumbProtectPort");

	FltBuildDefaultSecurityDescriptor(&pSecDesc, FLT_PORT_ALL_ACCESS);

	InitializeObjectAttributes(&objAttr, &portName, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, nullptr, pSecDesc);

	status = FltCreateCommunicationPort(g_Filter, &g_pServerPort, &objAttr, nullptr, 
		PortConnectNotify, PortDisconnectNotify, PortMessageNotify, 1);

	if (!NT_SUCCESS(status)) {
		DbgPrint("[DUMBPROTECT] [!] Could not create port\n");
	}

	FltFreeSecurityDescriptor(pSecDesc);

	DbgPrint("[DUMBPROTECT] [+] Starting filtering\n");

	status = FltStartFiltering(g_Filter);

	if (!NT_SUCCESS(status)) {
		DbgPrint("[DUMBPROTECT] [!] Could not start filtering process\n");
		FltUnregisterFilter(g_Filter);
		return status;
	}
	DbgPrint("[DUMBPROTECT] [+] Filter started\n");

	return STATUS_SUCCESS;
}
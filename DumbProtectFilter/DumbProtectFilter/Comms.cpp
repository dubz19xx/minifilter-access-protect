#include <fltKernel.h>
#include "Comms.h"
#include "Handler.h"

PFLT_PORT g_pServerPort;
PFLT_PORT g_pClientPort;

extern PFLT_FILTER g_Filter;

NTSTATUS PortConnectNotify(
	_In_ PFLT_PORT ClientPort,
	_In_ PVOID ServerPortCookie,
	_In_ PVOID ConnectionContext,
	_In_ ULONG SizeOfContext,
	_Out_ PVOID* ConnectionPortCookie
) {
	g_pClientPort = ClientPort;
	DbgPrint("[DUMBPROTECT] [+] Connected to client port\n");
	return STATUS_SUCCESS;
}

void PortDisconnectNotify(_In_ void* ConnectionCookie) {
	FltCloseClientPort(g_Filter, &g_pClientPort);
	g_pClientPort = nullptr;
}

NTSTATUS PortMessageNotify(
	_In_ PVOID PortCookie,
	_In_ PVOID InputBuffer,
	_In_ ULONG InputBufferLength,
	_Out_ PVOID OutputBuffer,
	_In_ ULONG OutputBufferLength,
	_Out_ PULONG ReturnOutputBufferLength
) {
	ProtectMessage inputMessage = *(ProtectMessage*)InputBuffer;
	AddToList(inputMessage);
	DbgPrint("[DUMBPROTECT] [PROTECT] [FILE] %s\n", inputMessage.FilePath);
	DbgPrint("[DUMBPROTECT] [PROTECT] [OP] read: %d\n", inputMessage.protect.ReadProtect);
	DbgPrint("[DUMBPROTECT] [PROTECT] [OP] write: %d\n", inputMessage.protect.WriteProtect);
	DbgPrint("[DUMBPROTECT] [PROTECT] [OP] delete: %d\n", inputMessage.protect.DeleteProtect);
	return STATUS_SUCCESS;
}
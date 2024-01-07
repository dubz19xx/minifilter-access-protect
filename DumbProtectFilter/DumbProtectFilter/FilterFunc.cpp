#include <fltKernel.h>
#include "FilterFunc.h"
#include "Handler.h"

extern PFLT_FILTER g_Filter;
extern PFLT_PORT g_pServerPort;
extern PFLT_PORT g_pClientPort;

FLT_PREOP_CALLBACK_STATUS CreatePreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext) {

	//
	PFLT_FILE_NAME_INFORMATION fileNameInfo;
	FltGetFileNameInformation(Data, FLT_FILE_NAME_NORMALIZED | FLT_FILE_NAME_QUERY_DEFAULT, &fileNameInfo);
	//

	ANSI_STRING str;
	RtlUnicodeStringToAnsiString(&str, &Data->Iopb->TargetFileObject->FileName, true);
	char fname[261];
	RtlZeroMemory(fname, 261);
	RtlCopyBytes(fname, str.Buffer,str.Length);
//	char name[261] = Data->Iopb->TargetFileObject->FileName
	SearchForObj(fname);
	RtlFreeAnsiString(&str);
	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

FLT_PREOP_CALLBACK_STATUS ReadPreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext) {
	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

FLT_PREOP_CALLBACK_STATUS WritePreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext) {
	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

FLT_PREOP_CALLBACK_STATUS SetInfoPreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext) {
	return FLT_PREOP_SUCCESS_NO_CALLBACK;
}

NTSTATUS FLTAPI DumbProtectUnload(FLT_FILTER_UNLOAD_FLAGS flags) {
	if (g_Filter != NULL) {
		FltCloseCommunicationPort(g_pServerPort);
		FltUnregisterFilter(g_Filter);
		DbgPrint("[DUMBPROTECT] [+] Unloaded filter\n");
	}
	return STATUS_SUCCESS;
}

NTSTATUS FLTAPI DumbProtectQueryTeardownCallback(
	PCFLT_RELATED_OBJECTS FltObjects,
	FLT_INSTANCE_QUERY_TEARDOWN_FLAGS Flags
) {
	return STATUS_SUCCESS;
}
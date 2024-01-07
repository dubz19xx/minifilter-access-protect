#pragma once

FLT_PREOP_CALLBACK_STATUS CreatePreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext);

FLT_PREOP_CALLBACK_STATUS ReadPreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext);

FLT_PREOP_CALLBACK_STATUS WritePreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext);

FLT_PREOP_CALLBACK_STATUS SetInfoPreOperation(
	_Inout_ PFLT_CALLBACK_DATA Data,
	_In_ PCFLT_RELATED_OBJECTS fltObjects,
	_Out_ _Flt_CompletionContext_Outptr_ PVOID* CompletionContext);


NTSTATUS FLTAPI DumbProtectUnload(FLT_FILTER_UNLOAD_FLAGS flags);

NTSTATUS FLTAPI DumbProtectQueryTeardownCallback(
	PCFLT_RELATED_OBJECTS FltObjects,
	FLT_INSTANCE_QUERY_TEARDOWN_FLAGS Flags
);


const FLT_OPERATION_REGISTRATION InstanceOperationRegistration[] = {
	{IRP_MJ_CREATE, 0, CreatePreOperation, nullptr}, //read, write and delete here
	{IRP_MJ_READ, 0, ReadPreOperation, nullptr},
	{IRP_MJ_WRITE, 0, WritePreOperation, nullptr},
	{IRP_MJ_SET_INFORMATION, 0, SetInfoPreOperation, nullptr},
	{IRP_MJ_OPERATION_END}
};

const FLT_REGISTRATION InstanceRegistration = {
	sizeof(FLT_REGISTRATION),
	FLT_REGISTRATION_VERSION,
	NULL,
	NULL, //context reg
	InstanceOperationRegistration,
	DumbProtectUnload,
	NULL,
	DumbProtectQueryTeardownCallback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};


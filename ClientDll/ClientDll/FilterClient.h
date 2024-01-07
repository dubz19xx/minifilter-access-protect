#pragma once

#include <string.h>

#pragma pack(push, 1)
struct ProtectionParameters{
	bool ReadProtect;
	bool WriteProtect;
	bool DeleteProtect;
};

struct AccessLevel {
	bool UsermodeAccess;
	bool AdminAccess;
	bool KernelAccess;
};
struct ProtectMessage {
	BYTE FileName[261];
	ProtectionParameters protect;
	AccessLevel access;
};

#pragma pack(pop)

class BackendDll {

	HANDLE hPort;

public:
	
	BackendDll();
	int EstablishCommunicationWithDriver();
	void ProtectDeez(ProtectMessage prm);
};

extern "C" __declspec(dllexport) void* GetCallback() {
	return (void*)new BackendDll();
}

extern "C" __declspec(dllexport) void SendToFilter(BackendDll* dll, ProtectMessage prm) {
	dll->ProtectDeez(prm);
}

extern "C" __declspec(dllexport) int ConnectToFilter(BackendDll * dll) {
	return dll->EstablishCommunicationWithDriver();
}
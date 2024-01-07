#include "pch.h"
#include "FilterClient.h"

int BackendDll::EstablishCommunicationWithDriver() {

	//might want to install and start the minifilter here

	auto hr = FilterConnectCommunicationPort(L"\\DumbProtectPort", 0, NULL, 0, NULL, &hPort);
	if (FAILED(hr)) {
		MessageBox(NULL, L"[DUMBPROTECT] [!] Failed to connect to minifilter", L"DumbProtect", MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}
	MessageBox(NULL, L"[DUMBPROTECT] Connected to minifilter", L"DumbProtect", MB_ICONEXCLAMATION | MB_OK);
	return 0;
}

void BackendDll::ProtectDeez(ProtectMessage prm) {
	printf("[DUMBPROTECT] [+] Sending protect message\n");
	MessageBox(NULL, L"[DUMBPROTECT] Sending protect message", L"DumbProtect", MB_ICONEXCLAMATION | MB_OK);
	DWORD retbuf;
//	LPVOID message = &prm;
	FilterSendMessage(hPort, &prm, sizeof(ProtectMessage), nullptr, 0, &retbuf);
}

BackendDll::BackendDll() {
	printf("[DUMBPROTECT] [+] Connected to dll\n");
}
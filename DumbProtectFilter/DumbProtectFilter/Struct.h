#pragma once


struct ProtectionParameters {
	bool ReadProtect = false;
	bool WriteProtect = false;
	bool DeleteProtect = false;
};

struct AccessLevel {
	bool UsermodeAccess;
	bool AdminAccess;
	bool KernelAccess;
};

struct ProtectMessage {
	char FilePath[261];
	ProtectionParameters protect;
	AccessLevel access;
};


#include <fltKernel.h>
//#include "Struct.h"
#include "Handler.h"

typedef struct ProtectMessage MsgArr;

MsgArr protect_list[sizeof(size_t)] = {};
size_t protect_list_counter = 0;

void AddToList(ProtectMessage message) {
	protect_list[protect_list_counter++] = message;
}

int SearchForObj(char* message) {
	for (int i = 0; i < protect_list_counter; i++) {
//		UNICODE_STRING* checkstr = (UNICODE_STRING*)ExAllocatePool(PagedPool, 300);
//		RtlInitUnicodeString(checkstr, Multivyt message)
		char sm[261];
		RtlZeroBytes(sm, 261);
		RtlCopyBytes(sm, protect_list[i].FilePath, 261);
		if (strcmp(sm, message) == 0) {
			DbgPrint("[DUMBPROTECT] File from protect list accessed\n");
			return 1;
		}
	}
	return 0;
}
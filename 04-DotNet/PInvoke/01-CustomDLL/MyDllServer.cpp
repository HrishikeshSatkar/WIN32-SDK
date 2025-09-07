#include <windows.h>
#include "MyDllServer.h"
BOOL WINAPIDllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}
extern "C" int SumOfTwoIntegers(int num1, int num2)
{
	//code
	int num3 = num1 + num2;
	return num3;
}

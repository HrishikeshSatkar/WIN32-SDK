#include <windows.h>
#include "AutomationServerWithRegFile.h"
// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
IDispatch* gpIDispatch = NULL;

// entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("ComClient");
	HRESULT hr;

	// code
	// COM Initialization
	hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		MessageBox(NULL, TEXT("COM Library Can Not be Initialized.\nProgram Will Now Exit."), TEXT("Program Error"), MB_OK);
		exit(0);
	}
	// WNDCLASSEX initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	//create the window in memory
	hwnd = CreateWindow(szAppName,
		TEXT("HMS:My First Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	// COM Un-initialization
	CoUninitialize();
	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	
	// variable declarations
	HRESULT hr;
	int iNum1, iNum2, iSum;
	TCHAR str[255];
	DISPID dispid;
	OLECHAR* szFunctionOne = L"SumOfTwoIntegers";
	OLECHAR* szFunctionTwo = L"SubtractionOfTwoIntegers";
	VARIANT vArg[2], vRet;
	DISPPARAMS params;

	// code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoCreateInstance(CLSID_MyMath, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&gpIDispatch);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IDispatch Interface Can Not Be Obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		iNum1 = 155;
		iNum2 = 145;
		VariantInit(vArg);
		vArg[0].vt = VT_INT;
		vArg[0].intVal = iNum2;
		vArg[1].vt = VT_INT;
		vArg[1].intVal = iNum1;
		params.rgvarg = vArg;
		params.cArgs = 2;
		params.rgdispidNamedArgs = NULL;
		params.cNamedArgs = 0;
		VariantInit(&vRet);
		//sum
		hr = gpIDispatch->GetIDsOfNames(IID_NULL, &szFunctionOne, 1, GetUserDefaultLCID(), &dispid);

		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("GetIDsOfNames Failed!!!"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		hr = gpIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &params, &vRet, NULL, NULL);
	
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("Invoke Failed!!!"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		wsprintf(str, TEXT("Sum of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Sum-IDispatch"), MB_OK);

		//subtract
		hr = gpIDispatch->GetIDsOfNames(IID_NULL, &szFunctionTwo, 1, GetUserDefaultLCID(), &dispid);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("GetIDsOfNames Failed!!!"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		hr = gpIDispatch->Invoke(dispid, IID_NULL, GetUserDefaultLCID(), DISPATCH_METHOD, &params, &vRet, NULL, NULL);

		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("Invoke Failed!!!"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		wsprintf(str, TEXT("Subtraction of %d and %d is %d"), iNum1, iNum2, vRet.lVal);
		MessageBox(hwnd, str, TEXT("Subtraction-IDispatch"), MB_OK);
		if (gpIDispatch)
		{
			gpIDispatch->Release();
			gpIDispatch = NULL;
		}
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}


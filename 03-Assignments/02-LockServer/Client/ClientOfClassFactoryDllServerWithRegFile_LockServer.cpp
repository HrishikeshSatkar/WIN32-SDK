#include <windows.h>
#include "ClassFactoryDllServerWithRegFile_LockServer.h"
// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
ISum* pISum = NULL;
ISubtract* pISubtract = NULL;
int giFlag = 0;
IClassFactory* gpIClassFactory = NULL;

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
	// function declarations
	void SafeInterfaceRelease(void);
	// variable declarations
	static HRESULT hr;
	int iNum1, iNum2, iSum;
	TCHAR str[255];
	// code
	switch (iMsg)
	{
	case WM_CREATE:
		hr = CoGetClassObject(CLSID_SumSubtract, CLSCTX_INPROC_SERVER, NULL, IID_IClassFactory, (void**)&gpIClassFactory);
		if (FAILED(hr))
		{
			MessageBox(hwnd, TEXT("IClassFactory Interface Can Not Be Obtained"), TEXT("Error"), MB_OK);
			DestroyWindow(hwnd);
		}
		gpIClassFactory->LockServer(TRUE);
		break;
	case WM_LBUTTONDOWN:
		giFlag++;
		if(giFlag == 1)
		{
			hr = gpIClassFactory->CreateInstance(NULL, IID_ISum, (void**)&pISum);
			if(FAILED(hr))
			{
				MessageBox(hwnd, TEXT("ISum Interface Can Not Be Obtained"), TEXT("ERROR"), MB_OK);
				DestroyWindow(hwnd);
			}
			iNum1 = 55;
			iNum2 = 45;
			// call SumOfTwoUntegers() of ISum to get the sum
			pISum->SumOfTwoIntegers(iNum1, iNum2, &iSum);
			// display the result
			wsprintf(str, TEXT("Sum of %d and %d = %d"), iNum1, iNum2, iSum);
			MessageBox(hwnd, str, TEXT("Result"), MB_OK);
			pISum->Release();
			pISum = NULL;
			MessageBox(hwnd,TEXT("pISum Released Successfully!!!"), TEXT("SUCCESS"), MB_OK);
		}
		if(giFlag == 2)
		{
			hr = gpIClassFactory->CreateInstance(NULL, IID_ISubtract, (void**)&pISubtract);
			if(FAILED(hr))
			{
				MessageBox(hwnd, TEXT("ISubtract Interface Can Not Be Obtained"), TEXT("ERROR"), MB_OK);
				DestroyWindow(hwnd);
			}
			iNum1 = 55;
			iNum2 = 45;
			// call SubtractionOfTwoUntegers() of ISubtract to get the subtraction
			pISubtract->SubtractionOfTwoIntegers(iNum1, iNum2, &iSum);
			// display the result
			wsprintf(str, TEXT("Subtraction of %d and %d = %d"), iNum1, iNum2, iSum);
			MessageBox(hwnd, str, TEXT("Result"), MB_OK);
			pISubtract->Release();
			pISubtract = NULL;
			MessageBox(hwnd,TEXT("pISubtract Released Successfully!!!"), TEXT("SUCCESS"), MB_OK);

		}
		if(giFlag == 3)
		{
			DestroyWindow(hwnd);
		}
		break;

	case WM_DESTROY:
		if(gpIClassFactory != NULL)
		{
			gpIClassFactory->LockServer(FALSE);
			gpIClassFactory->Release();
			gpIClassFactory = NULL;
			MessageBox(hwnd,TEXT("pIClassfactory Released Successfully!!!"), TEXT("SUCCESS"), MB_OK);
		}
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
void SafeInterfaceRelease(void)
{
	// code
	if (pISum)
	{
		pISum->Release();
		pISum = NULL;
	}
	if (pISubtract)
	{
		pISubtract->Release();
		pISubtract = NULL;
	}
}

#include<windows.h>
#include"ClassFactoryDllServerWithRegFile_LockServer.h"

//class declarations
class CSumSubtract :public ISum, ISubtract
{
private:
	long m_cRef;
public:
	//constructor method declarations
	CSumSubtract(void);

	//destructor method declarations
	~CSumSubtract(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);
	
	//ISum specific method declarations (inherited)
	HRESULT __stdcall SumOfTwoIntegers(int, int, int*);

	//ISubtract specific method declarations (inherited)
	HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*);
};

class CSumSubtractClassFactory :public IClassFactory
{
private:
	long m_cRef;
public:
	//constructor method declarations
	CSumSubtractClassFactory(void);

	//destructor method declarations
	~CSumSubtractClassFactory(void);

	//IUnknown specific method declarations (inherited)
	HRESULT __stdcall QueryInterface(REFIID, void**);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);

	//IClassFactory specific method declarations (inherited)
	HRESULT __stdcall CreateInstance(IUnknown*, REFIID, void**);
	HRESULT __stdcall LockServer(BOOL);
};

// global variable declarations
long glNumberOfActiveComponents = 0;// number of active components
long glNumberOfServerLocks = 0;// number of locks on this dll

// DllMain
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID Reserved)
{
	TCHAR str[255];
	// code
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
		MessageBox(NULL, str, TEXT("DLL_PROCESS_ATTACH"),MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
		MessageBox(NULL, str, TEXT("DLL_PROCESS_DETACH"),MB_OK);
		break;
	}
	return (TRUE);
}

// Implementation Of CSumSubtract's Constructor Method
CSumSubtract::CSumSubtract(void)
{
	// code
	m_cRef = 1;// hardcoded initialization to anticipate possible failure of QueryInterface()
	InterlockedIncrement(&glNumberOfActiveComponents);// increment global counter
}

// Implementation Of CSumSubtract's Destructor Method
CSumSubtract::~CSumSubtract(void)
{
	InterlockedDecrement(&glNumberOfActiveComponents);// decrement global counter
}

// Implementation of CSumSubtract's IUnknown's Method
HRESULT CSumSubtract::QueryInterface(REFIID riid, void** ppv)
{
	// code
	if (riid == IID_IUnknown)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISum)
		*ppv = static_cast<ISum*>(this);
	else if (riid == IID_ISubtract)
		*ppv = static_cast<ISubtract*>(this);
	else 
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return (S_OK);
}
ULONG CSumSubtract::AddRef(void)
{
	// code
	InterlockedIncrement(&m_cRef);
	return (m_cRef);
}
ULONG CSumSubtract::Release(void)
{
	// code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return (0);
	}
	return (m_cRef);
}

// Implementation Of ISum's Methods
HRESULT CSumSubtract::SumOfTwoIntegers(int num1, int num2, int* pSum)
{
	// code
	*pSum = num1 + num2;
	return (S_OK);
}

// Implementation Of ISubtract's Methods
HRESULT CSumSubtract::SubtractionOfTwoIntegers(int num1, int num2, int* pSubtract)
{
	// code
	*pSubtract = num1 - num2;
	return (S_OK);
}

// Implementation Of CSumSubtractClassFactory's Constructor Method
CSumSubtractClassFactory::CSumSubtractClassFactory(void)
{
	// code
	m_cRef = 1;// hardcoded initialization to anticipate possible failure of QueryInterface()
}

// Implementation Of CSumSubtractClassFactory's Destructor Method
CSumSubtractClassFactory::~CSumSubtractClassFactory(void)
{
	// code
}

// Implementation Of CSumSubtractClassFactory's IClassFactory's IUnknown's Methods
HRESULT CSumSubtractClassFactory::QueryInterface(REFIID riid, void** ppv)
{
	// code
	if (riid == IID_IUnknown)
		*ppv = static_cast<IClassFactory*>(this);
	else if (riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return (E_NOINTERFACE);
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return (S_OK);
}
ULONG CSumSubtractClassFactory::AddRef(void)
{
	// code
	InterlockedIncrement(&m_cRef);
	return (m_cRef);
}
ULONG CSumSubtractClassFactory::Release(void)
{
	// code
	InterlockedDecrement(&m_cRef);
	if (m_cRef == 0)
	{
		delete(this);
		return (0);
	}
	return (m_cRef);
}

// Implementation of CSumSubtractClassFactory's IClassFactory's Methods 
HRESULT CSumSubtractClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppv)
{
	// variable declarations
	TCHAR str[255];
	CSumSubtract* pCSumSubtract = NULL;
	HRESULT hr;
	wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
	MessageBox(NULL, str, TEXT("BEGINING_OF_CREATEINSTANCE"),MB_OK);
	// code
	if (pUnkOuter != NULL)
		return (CLASS_E_NOAGGREGATION);
	// create the instance of component i.e. of CSumSubtract class
	pCSumSubtract = new CSumSubtract;
	if (pCSumSubtract == NULL)
		return (E_OUTOFMEMORY);
	// get the requested interface
	hr = pCSumSubtract->QueryInterface(riid, ppv);
	pCSumSubtract->Release();// anticipate possible failure of QueryInterface()
	wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
	MessageBox(NULL, str, TEXT("ENDING_OF_CREATEINSTANCE"),MB_OK);
	return (hr);
}
HRESULT CSumSubtractClassFactory::LockServer(BOOL fLock)
{
	TCHAR str[255];
	// code
	if (fLock)
		InterlockedIncrement(&glNumberOfServerLocks);
	else
		InterlockedDecrement(&glNumberOfServerLocks);
	wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
	MessageBox(NULL, str, TEXT("INSIDE_LOCKSERVER"),MB_OK);
	return (S_OK);
}

//Implementation of EXported Functions From This Dll
extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
	// variable declarations
	CSumSubtractClassFactory* pCSumSubtractClassFactory = NULL;
	HRESULT hr;
	// code
	if (rclsid != CLSID_SumSubtract)
		return (CLASS_E_CLASSNOTAVAILABLE);
	// create class factory
	pCSumSubtractClassFactory = new CSumSubtractClassFactory;
	if (pCSumSubtractClassFactory == NULL)
		return (E_OUTOFMEMORY);
	hr = pCSumSubtractClassFactory->QueryInterface(riid, ppv);
	pCSumSubtractClassFactory->Release(); // anticipate possible failure of QueryInterface
	return (hr);
}extern "C" HRESULT __stdcall DllCanUnloadNow(void)
{
	TCHAR str[255];
	// code
	wsprintf(str,TEXT("glNumberOfActiveComponents = %d & glNumberOfServerLocks = %d"), glNumberOfActiveComponents, glNumberOfServerLocks);
	MessageBox(NULL, str, TEXT("BEFORE_DLLCANUNLOADNOW"),MB_OK);
	if (glNumberOfActiveComponents == 0 && glNumberOfServerLocks == 0)
		return (S_OK);
	else
		return (S_FALSE);
}
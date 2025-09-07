#pragma once
class ISum :public IUnknown
{
public:
	//ISum specific method declarations
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0;//pure virtual
};
class ISubtract :public IUnknown
{
public:
	//ISubtract specific method declarations
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0;//pure virtual
};

//CLSID of SumSubtract Component  {C37149B8-43A5-4560-B5D1-3234DB803EDD}
const CLSID CLSID_SumSubtract = { 0xc37149b8, 0x43a5, 0x4560, 0xb5, 0xd1, 0x32, 0x34, 0xdb, 0x80, 0x3e, 0xdd };

//IID of ISum Interface
const IID IID_ISum = { 0x514d792a, 0x2756, 0x4198, 0x86, 0xc6, 0x96, 0x5d, 0xa1, 0xe0, 0xe0, 0xa6 };

//IID of ISubtract Interface
const IID IID_ISubtract = { 0x3d7149e2, 0xdc39, 0x4630, 0x89, 0xf6, 0x1, 0x9a, 0x80, 0xa7, 0xce, 0x44 };
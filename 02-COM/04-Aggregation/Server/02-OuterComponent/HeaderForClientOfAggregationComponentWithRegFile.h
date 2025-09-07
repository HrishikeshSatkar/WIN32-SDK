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
class IMultiplication :public IUnknown
{
public:
	//IMultiplication specific method declarations pure virtual
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;
};
class IDivision :public IUnknown
{
public:
	//IDivision specific method declarations pure virtual
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0;
};
//CLSID of SumSubtract Component {C37149B8-43A5-4560-B5D1-3234DB803EDD}
const CLSID CLSID_SumSubtract = { 0xc37149b8, 0x43a5, 0x4560, 0xb5, 0xd1, 0x32, 0x34, 0xdb, 0x80, 0x3e, 0xdd };

//IID of ISum Interface
const IID IID_ISum = { 0x514d792a, 0x2756, 0x4198, 0x86, 0xc6, 0x96, 0x5d, 0xa1, 0xe0, 0xe0, 0xa6 };

//IID of ISubtract Interface
const IID IID_ISubtract = { 0x3d7149e2, 0xdc39, 0x4630, 0x89, 0xf6, 0x1, 0x9a, 0x80, 0xa7, 0xce, 0x44 };

//IID of IMultiplication Interface
const IID IID_IMultiplication = { 0xfe2b92ed, 0x1c5b, 0x4226, 0x99, 0x7d, 0x99, 0xe5, 0x84, 0x96, 0x2f, 0xbc };

//IID of IDivision Interface
const IID IID_IDivision = { 0x228e9cdc, 0x8f4d, 0x4b86, 0x99, 0x84, 0xe9, 0xaa, 0xe3, 0xd0, 0x50, 0x4f };

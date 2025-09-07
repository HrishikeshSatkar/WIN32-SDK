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

//CLSID of SumSubtract Component   {85C9D2B9-2ED9-460C-B38D-45FFE9E8FA38}
const CLSID CLSID_SumSubtract = { 0x85c9d2b9, 0x2ed9, 0x460c, 0xb3, 0x8d, 0x45, 0xff, 0xe9, 0xe8, 0xfa, 0x38 };

//IID of ISum Interface
const IID IID_ISum = { 0x668c3780, 0xaac0, 0x43cb, 0xbf, 0x36, 0x50, 0xbe, 0x8e, 0xd, 0x8b, 0xe6 };

//IID of ISubtract Interface
const IID IID_ISubtract = { 0x660fb419, 0x8500, 0x446b, 0xab, 0x84, 0xf3, 0x4f, 0xa6, 0x3f, 0xda, 0xfb };
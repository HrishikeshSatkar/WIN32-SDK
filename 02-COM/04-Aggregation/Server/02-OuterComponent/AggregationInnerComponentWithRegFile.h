#pragma once
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

//CLSID of MultiplicationDivision Component  {BE807BB8-C2C5-4B03-9CE1-FDE1F7C77C4F}
const CLSID CLSID_MultiplicationDivision = { 0xbe807bb8, 0xc2c5, 0x4b03, 0x9c, 0xe1, 0xfd, 0xe1, 0xf7, 0xc7, 0x7c, 0x4f };

//IID of IMultiplication Interface
const IID IID_IMultiplication = { 0xfe2b92ed, 0x1c5b, 0x4226, 0x99, 0x7d, 0x99, 0xe5, 0x84, 0x96, 0x2f, 0xbc };

//IID of IDivision Interface
const IID IID_IDivision = { 0x228e9cdc, 0x8f4d, 0x4b86, 0x99, 0x84, 0xe9, 0xaa, 0xe3, 0xd0, 0x50, 0x4f };

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

//CLSID of MultiplicationDivision Component  {BDC7F7AD-8139-4E66-97E1-E58DFE00A353}
const CLSID CLSID_MultiplicationDivision = { 0xbdc7f7ad, 0x8139, 0x4e66, 0x97, 0xe1, 0xe5, 0x8d, 0xfe, 0x0, 0xa3, 0x53 };

//IID of IMultiplication Interface
const IID IID_IMultiplication = { 0x56d3d65f, 0xf3ed, 0x474a, 0xa7, 0x87, 0x8a, 0x80, 0xb0, 0x29, 0x88, 0x53 };

//IID of IDivision Interface
const IID IID_IDivision = { 0x85c9d2b9, 0x2ed9, 0x460c, 0xb3, 0x8d, 0x45, 0xff, 0xe9, 0xe8, 0xfa, 0x38 };

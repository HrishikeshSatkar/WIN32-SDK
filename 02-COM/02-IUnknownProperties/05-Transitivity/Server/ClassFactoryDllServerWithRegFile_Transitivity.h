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
	//ISubtract specific method declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;//pure virtual
};
//CLSID of SumSubtract Component {6A4B6884-D687-43DB-A77E-A3FDABDD5A33}
const CLSID CLSID_SumSubtract = { 0x6a4b6884, 0xd687, 0x43db, 0xa7, 0x7e, 0xa3, 0xfd, 0xab, 0xdd, 0x5a, 0x33 };
const IID IID_ISum = { 0x31232452, 0x3bcd, 0x4470, 0xb0, 0xde, 0xda, 0xcd, 0x7a, 0xb2, 0xc9, 0xb7 };
const IID IID_ISubtract = { 0x98051796, 0x8aa8, 0x4270, 0x8c, 0x6e, 0xdc, 0x78, 0xe3, 0x69, 0x7e, 0x9 };
const IID IID_IMultiplication = { 0x82edcd8e, 0xad5b, 0x4950, 0x82, 0x28, 0xb7, 0x5f, 0x44, 0x11, 0xe, 0x1b };
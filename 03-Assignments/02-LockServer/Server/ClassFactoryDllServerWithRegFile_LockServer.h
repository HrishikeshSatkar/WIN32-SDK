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
//CLSID of SumSubtract Component {CEFA93A8-C3AA-4425-8735-C29A4B5CA389}
const CLSID CLSID_SumSubtract = { 0xcefa93a8, 0xc3aa, 0x4425, 0x87, 0x35, 0xc2, 0x9a, 0x4b, 0x5c, 0xa3, 0x89 };
const IID IID_ISum = { 0xa752b61c, 0x737e, 0x40e5, 0xaf, 0x96, 0x10, 0x70, 0x32, 0xd4, 0xae, 0xa9 };
const IID IID_ISubtract = { 0xd4061fd3, 0x7f7b, 0x495b, 0x83, 0x37, 0x13, 0xa8, 0xb6, 0x15, 0x3d, 0xc4 };
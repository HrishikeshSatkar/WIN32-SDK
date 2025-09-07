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
//CLSID of SumSubtract Component {25989449-5E45-44CD-AA0C-4C30873DB7E3}
const CLSID CLSID_SumSubtract = { 0x25989449, 0x5e45, 0x44cd, 0xaa, 0xc, 0x4c, 0x30, 0x87, 0x3d, 0xb7, 0xe3 };
const IID IID_ISum = { 0x6e340fd, 0xaf6f, 0x4f72, 0x99, 0xd, 0xc7, 0x2, 0xd2, 0x59, 0xc4, 0xce };
const IID IID_ISubtract = { 0x1c7e931c, 0xe45, 0x4929, 0xb2, 0x52, 0xdf, 0x42, 0xa4, 0x67, 0xd8, 0xc3 };
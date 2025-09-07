#pragma once
#undef INTERFACE
#define INTERFACE IMyMath
DECLARE_INTERFACE_(IMyMath, IDispatch)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID, void**) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetTypeInfoCount)(THIS_ UINT*) PURE;
	STDMETHOD(GetTypeInfo)(THIS_ UINT,LCID,ITypeInfo**) PURE;
	STDMETHOD(GetIDsOfNames)(THIS_ REFIID,LPOLESTR*,UINT,LCID,DISPID*) PURE;
	STDMETHOD(Invoke)(THIS_ DISPID,REFIID,LCID,WORD,DISPPARAMS*,VARIANT*,EXCEPINFO*,UINT*) PURE;


	STDMETHOD(SumOfTwoIntegers)(THIS_ int, int, int*) PURE;
	STDMETHOD(SubtractionOfTwoIntegers)(THIS_ int, int, int*) PURE;
};
// CLSID of MyMath Component : {F2D89068-14C0-4C09-8679-2E620D81DF44}
const CLSID CLSID_MyMath = { 0xf2d89068, 0x14c0, 0x4c09, 0x86, 0x79, 0x2e, 0x62, 0xd, 0x81, 0xdf, 0x44 };
// IID of ISum Interface : {3ED6C293-E4AF-4F50-BBA3-8DF1C878DC4C}
const IID IID_IMyMath = { 0x3ed6c293, 0xe4af, 0x4f50, 0xbb, 0xa3, 0x8d, 0xf1, 0xc8, 0x78, 0xdc, 0x4c };

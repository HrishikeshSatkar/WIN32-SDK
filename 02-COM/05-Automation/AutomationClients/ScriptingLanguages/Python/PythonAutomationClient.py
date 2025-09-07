import comtypes.client as cc
import comtypes
tlb_id = comtypes.GUID("{}")
cc.GetModule((tlb_id,1,0))
import comtypes.gen.AutomationServerTypeLib as AutomationServer
pIMyMath = cc.Create
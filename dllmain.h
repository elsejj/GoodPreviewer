// dllmain.h: 模块类的声明。

class CGoodPreviewerModule : public ATL::CAtlDllModuleT< CGoodPreviewerModule >
{
public :
	DECLARE_LIBID(LIBID_GoodPreviewerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GOODPREVIEWER, "{eda35095-e859-4d50-b31d-441fcaad6f4f}")
};

extern class CGoodPreviewerModule _AtlModule;

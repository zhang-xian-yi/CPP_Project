#include "ImguiRendererFactory.h"

namespace ImguiRendererNS
{
	MdlCommonNS::IMdlService* ImguiRendererFactory::CreateServiceInstance()
	{
		return nullptr;
	}

	MdlCommonNS::IMdlOperat* ImguiRendererFactory::CreateModuleInstance()
	{
		return nullptr;
	}
}
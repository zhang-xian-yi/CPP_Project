#include "ImguiRendererFactory.h"
#include "MdlCommon/Src/CMNInterface/IMdlOperat.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "IRMControl/RendererMdlControl.h"
#include "IRMControl/RendererServiceControl.h"
namespace ImguiRendererNS
{
	MdlCommonNS::IMdlService* ImguiRendererFactory::CreateServiceInstance()
	{
		return new RendererServiceControl();
	}

	MdlCommonNS::IMdlOperat* ImguiRendererFactory::CreateModuleInstance()
	{
		return new RendererMdlControl();
	}
}
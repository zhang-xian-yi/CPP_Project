#include "OpenGLUIFactory.h"
#include <OGMControl/OpenGLUIMdlControl.h>
#include <OGMControl/OpenGLUIServiceControl.h>

namespace OpenGLUINS
{
	OpenGLUIFactory::OpenGLUIFactory()
	{
	}
	OpenGLUIFactory::~OpenGLUIFactory()
	{
	}

	/// <summary>
	/// ����һ���µ�ҵ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlService* OpenGLUIFactory::CreateServiceInstance()
	{
		return new OpenGLUIServiceControl;
	}

	/// <summary>
	/// ����һ���µ�ģ�����ʵ��
	/// </summary>
	/// <returns></returns>
	MdlCommonNS::IMdlOperat* OpenGLUIFactory::CreateModuleInstance()
	{
		return new OpenGLUIMdlControl();
	}


}
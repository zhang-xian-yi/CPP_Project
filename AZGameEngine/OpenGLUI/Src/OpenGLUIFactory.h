#pragma once
#include <OGCommon/OGExpMarcoDefine.h>
#include "CMNInterface/IMdlFactory.h"
namespace MdlCommonNS
{
	//ǰ������
	class IMdlOperat;
	class IMdlService;
}

namespace OpenGLUINS
{
	/// <summary>
	/// openGui ��ģ�鹤��
	/// </summary>
	class OpenGLUIAPI OpenGLUIFactory :public MdlCommonNS::IMdlFactory
	{
	public:
		static IMdlFactory* GetFactory()
		{
			static OpenGLUIFactory instance;
			return &instance;
		}
	public:
		MdlCommonNS::IMdlService* CreateServiceInstance() override;
		MdlCommonNS::IMdlOperat* CreateModuleInstance() override;
	private:
		//��ֹ�������幤������ֹdelelte ��������
		OpenGLUIFactory();
		~OpenGLUIFactory();
		OpenGLUIFactory(OpenGLUIFactory& instance) = delete;
		OpenGLUIFactory& operator=(const OpenGLUIFactory& instance) = delete;
	};
}




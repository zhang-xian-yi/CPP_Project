#pragma once
#include "ILModule.h"

namespace Log4CppNS
{
	class LModuleControl:public ILModule
	{
	public:
		//��ʼ����־ģ��
		LMStatus InitModule(LogSettingPara& para) override;
		//ֹͣ��־ģ��
		LMStatus StopModule() override;
	};
}



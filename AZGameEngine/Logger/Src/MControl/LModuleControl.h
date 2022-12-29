#pragma once
#include "ILModule.h"

namespace Log4CppNS
{
	class LModuleControl:public ILModule
	{
	public:
		//��ʼ����־ģ��
		LMStatus InitModule(LogSettingPara& para) override;
		//������־����
		LMStatus UpdateSetting(LogSettingPara& para) override;
		//ֹͣ��־ģ��
		LMStatus StopModule() override;
		//��ȡģ��״̬
		bool IsUse() override;
	private:
		bool m_bIsUse;//ģ���Ƿ����
		bool m_bIsInit;//ģ���Ƿ��ʼ��
	};
}



#pragma once
#include "Common/MarcoDefine.h"

namespace Log4CppNS
{
	//ǰ������ ö��
	enum class LMStatus :unsigned char;

	//��־ģ�����ò��� ǰ������
	struct LogSettingPara;


	//��־ģ���ģ��
	class LogerAPI ILModule
	{
	public:
		//��ʼ����־ģ��
		virtual LMStatus InitModule(LogSettingPara& para) = 0;
		//������־����ģ��
		virtual LMStatus UpdateSetting(LogSettingPara& para) = 0;
		//ֹͣ��־ģ��
		virtual LMStatus StopModule() = 0;
		//��ȡģ��״̬
		virtual bool IsUse() = 0;
	};
}
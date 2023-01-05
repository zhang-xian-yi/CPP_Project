#pragma once
#include "Common/MarcoDefine.h"

namespace OpenGLUINS
{
	//ǰ������ ö��
	enum class LMStatus :unsigned char;


	//��־ģ���ģ��
	class OpenGLUIAPI IUIModule
	{
	public:
		//��ʼ����־ģ��
		virtual LMStatus InitModule() = 0;
		//ֹͣ��־ģ��
		virtual LMStatus StopModule() = 0;
	};
}
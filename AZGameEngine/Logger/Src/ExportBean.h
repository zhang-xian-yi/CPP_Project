#pragma once
#include <string>
#include "Common/MarcoDefine.h"
namespace Log4CppNS
{
	enum class ELogLevel :unsigned char;

	//��־�ĵȼ�
	enum class ELogTarget :unsigned char;

	//��־���ò���
	struct LogerAPI LogSettingPara
	{
		ELogLevel logLevel;//��־�ȼ�
		ELogTarget logTarget;//��־Ŀ��
	};

	//��־��Ϣ�Ĳ���
	struct LogerAPI LogMsgPara
	{
		std::string message;
	};
}


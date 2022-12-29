#pragma once
namespace Log4CppNS
{
	//��־�ĵȼ�
	enum class ELogLevel :unsigned char
	{
		E_DebugLevel,//����
		E_InfoLevel,//��Ϣ
		E_WarnLevel,//����
		E_ErrorLevel,//����
		E_FaultLevel,//����
	};

	//��־�ĵȼ�
	enum class ELogTarget :unsigned char
	{
		E_Console,//����̨
		E_LogFile,//��־�ļ�
	};


	//��־���ò���
	struct LogSettingPara
	{
		ELogLevel logLevel;//��־�ȼ�
		ELogTarget logTarget;//��־Ŀ��
	}; 
}



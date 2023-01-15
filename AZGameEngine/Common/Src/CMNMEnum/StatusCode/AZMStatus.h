#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace CommonNS
{
	//ע�� ö���� ����ǰ������
	//����ģ��״̬�ͷ�����Ϣ������
	//enum class ö���� -> ����ö�ٱ����LMStatus���޶���
	//unsigned char ����ö����� ���ݴ�С
	enum class AZMStatus :unsigned char
	{
		E_ModuleInit_Succ,//ģ���ʼ���ɹ�
		E_ModuleInit_Failed,//ģ���ʼ��ʧ��
		E_ModuleRunning,//ģ����������
		E_ModuleNotInit,//ģ��û�г�ʼ��
		E_ModuleNotUse,//ģ�鲻����
	};

	CommonDLLAPI std::string GetStatusDesc(AZMStatus status);
	CommonDLLAPI std::string GetStatusHelp(AZMStatus status);
}


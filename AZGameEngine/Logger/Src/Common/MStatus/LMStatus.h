#pragma once

namespace Log4CppNS
{
	//ע�� ö���� ����ǰ������
	//����ģ��״̬�ͷ�����Ϣ������
	//enum class ö���� -> ����ö�ٱ����LMStatus���޶���
	//unsigned char ����ö����� ���ݴ�С
	enum class LMStatus:unsigned char
	{
		E_ModuleInit_Succ,//ģ���ʼ���ɹ�
		E_ModuleInit_Failed,//ģ���ʼ��ʧ��
		E_ModuleRunning,//ģ����������
		E_ModuleNotInit,//ģ��û�г�ʼ��
		E_ModuleNotUse,//ģ�鲻����
	};
}


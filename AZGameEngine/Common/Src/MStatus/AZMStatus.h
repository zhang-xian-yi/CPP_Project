#pragma once
#include <Common/ExportMarcoDefine.h> //������
#include <string>
namespace CommonNS
{
	//ע�� ö���� ����ǰ������
	//����ģ��״̬�ͷ�����Ϣ������
	//enum class ö���� -> ����ö�ٱ����LMStatus���޶���
	//unsigned char ����ö����� ���ݴ�С
	enum class CommonDLLAPI AZMStatus :unsigned char;

	CommonDLLAPI std::string GetStatusDesc(AZMStatus status);
	CommonDLLAPI std::string GetStatusHelp(AZMStatus status);
}


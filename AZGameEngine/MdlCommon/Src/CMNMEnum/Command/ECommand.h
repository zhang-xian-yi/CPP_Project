#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //������
namespace MdlCommonNS
{
	//ö��ģ������
	enum class ECommand :unsigned char
	{
		E_InitAllFunction,//��ʼ�����еĹ���ģ��
		E_DestoryAllFunction,//�������еĹ���ģ��
	};

	//ģ��ö��ֵ����չ����
	class MdlCommonDLLAPI EnumCommandExtend
	{
	public:
		//��ȡ��������(����)
		std::string GetCmdCnDesc(ECommand mdl)const;
		//��ȡ�������
		std::string GetMdlCode(ECommand mdl)const;
	};
}
#pragma once
#include <string>
namespace MdlCommonNS
{
	//״̬��
	enum class AZMStatus :unsigned char;

	/// <summary>
	/// Լ��ÿ����Ϣ�������Ľṹ
	/// </summary>
	typedef struct __SInformationBean
	{
		bool IsSuccess;//�Ƿ�ɹ��ı��
		AZMStatus StatusCode;//״̬��
		std::string Message;//��Ϣ����
	}MsgBean;
}



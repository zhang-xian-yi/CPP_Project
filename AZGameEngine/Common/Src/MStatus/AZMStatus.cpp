#include "AZMStatus.h"
#include <map>
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

	//����ÿ��ö�ٵ���ϸ��Ϣ
	struct SEnumDetailNode
	{
		std::string m_enumStr;
		std::string m_descStr;
		std::string m_helpStr;
	};

	template<typename T>
	struct SEnumDetail
	{
		static const std::map<T,SEnumDetailNode> DetailMap;
	};

	//���徲̬�����ľ�̬��������ʼ��ö��
	static const std::map<AZMStatus, SEnumDetailNode>& initStatusInfo()
	{
		
		return SEnumDetail<AZMStatus>::DetailMap;
	}
	///���ⶨ��static ����
	const std::map<AZMStatus, SEnumDetailNode> SEnumDetail<AZMStatus>::DetailMap = initStatusInfo();


	std::string GetStatusDesc(AZMStatus status)
	{
		std::map<AZMStatus, SEnumDetailNode>::const_iterator finditem = SEnumDetail<AZMStatus>::DetailMap.find(status);
		//�������
		if (SEnumDetail<AZMStatus>::DetailMap.end() != finditem)
		{
			SEnumDetailNode node = (*finditem).second;
			return node.m_descStr;
		}
		return  std::string();
	}

	std::string GetStatusHelp(AZMStatus status)
	{
		std::map<AZMStatus, SEnumDetailNode>::const_iterator finditem = SEnumDetail<AZMStatus>::DetailMap.find(status);
		//�������
		if (SEnumDetail<AZMStatus>::DetailMap.end() != finditem)
		{
			SEnumDetailNode node = (*finditem).second;
			return node.m_helpStr;
		}
		return  std::string();
	}



}

#pragma once
// �������й���ģ�����ʵ�ֵ�ģ��������ֹͣ�ӿ�
#include <any>
#include "MdlCommon/Src/CMNMacro/CMNExpMarcoDefine.h" //������


namespace MdlCommonNS
{
	//��־ģ���ģ��
	class MdlCommonDLLAPI IMdlOperat
	{
	public:
		virtual ~IMdlOperat() = 0;
	public:
		//����ģ��
		virtual bool ConstructModule() = 0;
		//����ģ��
		virtual bool DestoryModule() = 0;
		//��ȡģ��״̬
		virtual bool IsUse() const = 0;
	};

}
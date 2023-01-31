#pragma once

//�������й���ģ���ҵ���߼�ִ�����
#include <any>
#include <CMNMacro/CMNExpMarcoDefine.h> //������

namespace MdlCommonNS
{
	//ģ��ҵ���߼��ӿ�
	class MdlCommonDLLAPI IMdlService
	{
	public:
		virtual ~IMdlService() = 0;
	public:
		//������ָ�붯̬ת��Ϊģ��Ľӿ�ָ��
		template<typename T>
		T ConvertType()
		{
			return dynamic_cast<T>(this);
		}
	};
}
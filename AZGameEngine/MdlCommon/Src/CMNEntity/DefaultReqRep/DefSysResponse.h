#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //������
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//ǰ������ ��cpp��ʵ��- ��װһ���ֹ��������ʹ��stdģ���������ֵ�4251����
	class DefSysResponsePrivate;

	//�ӿ�ʵ����
	class MdlCommonDLLAPI DefSysResponse :public ISysResponse
	{
	public:
		DefSysResponse();
		~DefSysResponse();
	public:
		bool GetIsSuccess()const;
		const std::string& GetMessage()const;
		//��������
		void SetIsSuccess(const bool falg);
		void SetMessage(const std::string& message);
		//�Ϸ����
		virtual bool IsValid() const override;
	private:
		DefSysResponsePrivate* m_pService;
	};
}


#pragma once

namespace Log4CppNS
{
	//ǰ������ ö��
	enum class LMStatus :unsigned char;

	//��־ģ�����ò��� ǰ������
	struct LogSettingPara;


	//��־ģ���ģ��
	class ILModule
	{
	public:
		//��ʼ����־ģ��
		virtual LMStatus InitModule(LogSettingPara& para) = 0;
		//ֹͣ��־ģ��
		virtual LMStatus StopModule() = 0;
	private:
		bool m_bIsUse;//ģ���Ƿ����
		bool m_bIsInit;//ģ���Ƿ��ʼ��
	};
}
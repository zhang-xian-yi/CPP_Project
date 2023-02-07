#pragma once
#include "MACommon/CoreMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace WindowsNS
{
	class IWindow;//���ڽӿ�
}

namespace EventCommonNS
{
	class ISysEvent; //�¼��ӿ�
}

namespace AZGameMainApp
{
	class EventService; //�¼��ӿ�
}

namespace AZGameMainApp
{
	/// <summary>
	/// ��Ϸ�����򣬸������ĳ�ʼ��,������ֹͣ����Դ�ͷ�
	/// ����ģʽ
	/// </summary>
	class MainApplication
	{
		//ִ�е���
		SingletonDefaultConstruct(MainApplication)
	public:
		void InitApp();//��ʼ������
		void Run();//��������
		void StopApp();//ֹͣ����
	private:
		bool OnEvent(EventCommonNS::ISysEvent& e);
	private:
		void InitOpenGLWindows();//��ʼ������
		void InitMember();//��ʼ����Զ
		bool InitAllFunction();//��ʼ�����еĹ���ģ�鲢ע��
		bool StopAllFunction();//ֹͣ���еĹ���ģ�鲢ȡ��ע��
	private:
		AZGameMainApp::EventService* m_pEveS;
		WindowsNS::IWindow* m_pWindow; //����
		bool m_bRunning;//�����Ƿ�����
	};

}


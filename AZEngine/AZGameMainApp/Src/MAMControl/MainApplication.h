#pragma once
#include "MACommon/CoreMacroDef.h"
#include "MdlCommon/Src/CMNMacro/CoreMacroDef.h"
namespace WindowsNS
{
	class IWindow;//���ڽӿ�
}

namespace LayerCommonNS
{
	class ISysEvent; //�¼��ӿ�
	class WindowCloseEvent;
	class WindowResizeEvent;

}

namespace AZGameMainApp
{
	class EventService; //�¼��ӿ�
	class LayersStack;
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
		bool OnEvent(LayerCommonNS::ISysEvent& e);
	private:
		void InitOpenGLWindows();//��ʼ������
		void InitMember();//��ʼ����Զ
		bool InitAllFunction();//��ʼ�����еĹ���ģ�鲢ע��
		bool StopAllFunction();//ֹͣ���еĹ���ģ�鲢ȡ��ע��
	//�¼���Ӧ
	private:
		bool OnWindowCloseEvent(LayerCommonNS::WindowCloseEvent& eve);
		bool OnWindowResizeEvent(LayerCommonNS::WindowResizeEvent& eve);
	private:
		AZGameMainApp::EventService* m_pEveS;
		WindowsNS::IWindow* m_pWindow; //����
		LayersStack* m_pLayersStack;
		bool m_bRunning;//�����Ƿ�����
	};

}


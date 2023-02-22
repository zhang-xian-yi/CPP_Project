#include "WindowLayer.h"

namespace WindowsNS
{
	WindowLayer::WindowLayer(OpenGLWindows* win)
		:m_pWin(win)
	{

	}
	WindowLayer::~WindowLayer()
	{
		//��ָ��Ϊ���ù�ϵΪ�ⲿ���룬�������ͷ�
		m_pWin = nullptr;
	}
	void WindowLayer::OnAttach()
	{
		m_pWin->Show();//��ʼ�����ڲ���ʾ
	}
	void WindowLayer::OnDetach()
	{
		m_pWin->Shutdown();
	}

	bool WindowLayer::OnEvent(LayerCommonNS::ISysEvent& e)
	{
		return true;
	}

	void WindowLayer::OnRender()
	{

	}

	void WindowLayer::OnUpdate()
	{
		m_pWin->OnUpdate();
	}
	void WindowLayer::Begin()
	{

	}
	void WindowLayer::End()
	{
	}
	void WindowLayer::SetDarkThemeColors()
	{
	}
}
#include "WindowLayer.h"

namespace WindowsNS
{
	WindowLayer::WindowLayer(OpenGLWindows* win)
		:m_pWin(win)
	{

	}
	WindowLayer::~WindowLayer()
	{
		//此指针为引用关系为外部传入，不负责释放
		m_pWin = nullptr;
	}
	void WindowLayer::OnAttach()
	{
		m_pWin->Show();//初始化窗口并显示
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
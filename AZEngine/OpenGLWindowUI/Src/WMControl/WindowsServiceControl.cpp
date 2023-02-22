#include "WindowsServiceControl.h"
#include "WLogicService/OpenGLWindows.h"
#include "WLogicService/WindowLayer.h"
namespace WindowsNS
{

	WindowsServiceControl::WindowsServiceControl()
		:m_pWin(new OpenGLWindows(WindowProps("AZ Engine"))),
		 m_pLayer(nullptr)
	{

	}

	WindowsServiceControl::~WindowsServiceControl()
	{
		if (m_pWin)
		{
			delete m_pWin;
			m_pWin = nullptr;
		}
		if (m_pLayer)
		{
			delete m_pLayer;
			m_pLayer = nullptr;
		}
	}

	LayerCommonNS::ILayer* WindowsServiceControl::GetOpenGLWindowLayer()
	{
		if (m_pLayer == nullptr)
		{
			m_pLayer = new WindowLayer(m_pWin);
		}
		return m_pLayer;
	}

	unsigned int WindowsServiceControl::GetWidth() const
	{
		return 	m_pWin->GetWidth();
	}

	unsigned int WindowsServiceControl::GetHeight() const
	{
		return 	m_pWin->GetHeight();
	}
	//´°¿ÚÏÔÊ¾
	void WindowsServiceControl::Show()
	{
		m_pWin->Show();
	}

	void WindowsServiceControl::SetEventCallback(const EventCallbackFn& callback)
	{
		m_pWin->SetEventCallback(callback);
	}

	void* WindowsServiceControl::GetNativeWindow() const
	{
		return	m_pWin->GetNativeWindow();
	}

}
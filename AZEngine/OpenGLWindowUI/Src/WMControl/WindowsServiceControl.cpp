#include "WindowsServiceControl.h"
#include "OpenGLWindowUI/Src/WLogicService/OpenGLWindows.h"
namespace WindowsNS
{
	MdlCommonNS::Scope<IWindow> IWindow::Create(const WindowProps& props)
	{
		return MdlCommonNS::CreateScope<OpenGLWindows>(props);
	}


	WindowsServiceControl::WindowsServiceControl()
		:m_pWin(IWindow::Create(WindowProps("AZ Engine")))
	{

	}

	WindowsServiceControl::~WindowsServiceControl()
	{
		
	}

	void WindowsServiceControl::OnUpdate()
	{
		m_pWin->OnUpdate();
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

	void WindowsServiceControl::SetVSync(bool enabled)
	{
		m_pWin->SetVSync(enabled);
	}

	bool WindowsServiceControl::IsVSync() const
	{
		return	m_pWin->IsVSync();
	}

	void* WindowsServiceControl::GetNativeWindow() const
	{
		return	m_pWin->GetNativeWindow();
	}

}
#include "OpenGLWindows.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"//模块类型
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"
#include "OpenGLWindowUI/Src/IWindow.h"
#include "Logger/Src/ILogger.h"
#include "Glad/glad.h"
#include "GLFW/glfw3.h"

namespace WindowsNS
{
	static uint8_t s_GLFWWindowCount = 0;

	OpenGLWindows::OpenGLWindows(const WindowProps& props)
		:m_pWinS(new GLWindowService()),
		 m_pSysEventS(new SystemEventsService())
	{
		m_Data.WinPros = props;
	}

	OpenGLWindows::~OpenGLWindows()
	{
		Shutdown();
	}

	void OpenGLWindows::Show()
	{
		MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV, "Creating window ", m_Data.WinPros.Title, ", ", std::to_string(m_Data.WinPros.Width), ", ", std::to_string(m_Data.WinPros.Height));

		
		if (s_GLFWWindowCount == 0)
		{
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV,"glfwInit");
			auto success = m_pWinS->initWinEnvir(m_Data.WinPros);
			MdlCommonNS::LogMsg(LoggerNS::ELogLevel::E_Info_LV," initialize GLFW :", std::to_string(success) );
			
		}
		auto GLWin = m_pWinS->GetGLFWindowsHandle();
		//设置窗口的用户自定义数据
		glfwSetWindowUserPointer(GLWin, &m_Data);
		SetVSync(true);
		//初始化事件相应
		m_pSysEventS->InitSysEventRegister(GLWin);
	}

	void OpenGLWindows::Shutdown()
	{
		glfwDestroyWindow(m_pWinS->GetGLFWindowsHandle());
		--s_GLFWWindowCount;

		//删除窗口
		if (s_GLFWWindowCount == 0 && m_pWinS)
		{
			delete m_pWinS;
			delete m_pSysEventS;
		}
	}

	//刷新窗口
	void OpenGLWindows::OnUpdate()
	{
		m_pWinS->FlushWindow();
	}

	void OpenGLWindows::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool OpenGLWindows::IsVSync() const
	{
		return m_Data.VSync;
	}
}
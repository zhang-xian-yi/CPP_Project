#pragma once

//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

namespace EnvirmentNS
{
	/// <summary>
	/// 对GL窗口 的控制工具
	/// </summary>
	class GLWindowService
	{
	public:
		GLWindowService();
		~GLWindowService();

		//初始化允许环境
		int initWinEnvir(int width, int height);
		//刷新窗口交换区域
		int FlushWindow();
		//关闭窗口
		int StopWindows();
		//返回窗口句柄
		GLFWwindow* GetGLFWindowsHandle()const;
	private:
		int initWindows(int width, int height);
		//初始化其他的所有配置信息
		int initWindowsConfig();
	private:
		//GL 的窗口句柄
		GLFWwindow* _pWindow = nullptr;
	};
}



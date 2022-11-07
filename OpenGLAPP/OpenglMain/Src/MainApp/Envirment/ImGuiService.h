#pragma once

//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

namespace EnvirmentNS
{
	class ImGuiService
	{
	public:
		ImGuiService();
		~ImGuiService();

		//初始化允许环境
		int initEnvir(int width, int height);
		//开始允许
		int runWindow();
		//关闭窗口
		int stopWindows();
	private:
		//初始化窗口
		int initWindows(GLFWwindow* window);
		//初始化上下文
		int initContext();
		//初始化其他的所有配置信息
		int initOtherConfig();
	private:
		//GL 的窗口句柄
		GLFWwindow* _pWindow;
	};
}



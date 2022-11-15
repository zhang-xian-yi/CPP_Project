#pragma once
//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

namespace EnvirmentNS
{
	class FrameworkService
	{
	public:
		FrameworkService();
		~FrameworkService();

		//初始化允许环境
		int initEnvir(GLFWwindow* window);
		//刷新开始
		int FlushFrameStart();
		//刷新结束
		int FlushFrameEnd();
		//关闭窗口
		int EndFrameworkService();
	private:
		int initImGUI();
	private:
		//GL 的窗口句柄
		GLFWwindow* m_pWindow = nullptr;
	};
}



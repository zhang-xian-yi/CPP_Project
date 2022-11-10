#pragma once

//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

namespace EntityNS
{
	class RenderObj;//渲染对象参数
}

namespace EnvirmentNS
{
	class ImGuiService
	{
	public:
		ImGuiService();
		~ImGuiService();

		//初始化允许环境
		int initEnvir(GLFWwindow* window);
		//开始允许
		int FlushFrame(EntityNS::RenderObj& renderObj);
		//关闭窗口
		int EndIMGUIService();
	private:
		//初始化上下文
		int initContext(GLFWwindow* window);
	private:
		//窗口句柄
		GLFWwindow* m_pWindow = nullptr;
	};
}



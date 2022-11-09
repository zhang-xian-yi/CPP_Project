#pragma once

//前置声明 
namespace EnvirmentNS
{
	class OpenGLUIService;//Opengl 测试业务
	class ImGuiService;//ImGUI 业务
	class GLWindowService;// 窗口业务
}

namespace EnvirmentNS
{
	/// <summary>
	/// opengl 的测试APP程序
	/// </summary>
	class Application
	{
	public:
		Application();
		~Application();

		//初始化允许环境
		int InitAPPEnvir(int width, int height);
		//开始允许
		int RunAPP();
		//关闭窗口
		int StopAPP();

	private:
		//初始化窗口
		int InitAPPContext(int width, int height);
	private:
		//数据加载引擎
		EnvirmentNS::OpenGLUIService* m_pOpenGLUIS;//OpengGL 的UI业务
		EnvirmentNS::ImGuiService* m_pIMGUIS;//ImGUI 的业务
		EnvirmentNS::GLWindowService* m_pWinS;//
	};
}

/*注意

	将数据填充，转载，初始化，重新类化，减少APP的私有变量数量。
*/

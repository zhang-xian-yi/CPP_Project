#pragma once

//前置声明 
namespace EnvirmentNS
{
	class GLWindowService;//Opengl 测试业务
	class FrameworkService;//ImGUI 业务
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
		//窗口业务
		EnvirmentNS::GLWindowService* m_pWinS;//
		EnvirmentNS::FrameworkService* m_pFrameTestS;//框架测试业务
	};
}

/*注意

	将数据填充，转载，初始化，重新类化，减少APP的私有变量数量。
*/

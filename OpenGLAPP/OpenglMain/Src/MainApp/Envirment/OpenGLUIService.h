#pragma once

//前置声明 
struct GLFWwindow;//from  glew第三方库， 不能将此声明放入命名空间中

namespace EngineNS
{
	class DataLoadEngine;//数据加载引擎
}

namespace ShaderNS
{
	class ShaderManager;//着色器管理业务
}

namespace RenderNS
{
	class RendererEngine;//渲染器引擎
	class TextureService;//纹理
}


namespace EnvirmentNS
{
	/// <summary>
	/// opengl 的测试APP程序
	/// </summary>
	class OpenGLUIService
	{
	public:
		OpenGLUIService();
		~OpenGLUIService();

		//初始化允许环境
		int initEnvir(int width, int height);
		//开始允许
		int runWindow();
		//关闭窗口
		int stopWindows();

		//设置数据加载引擎
		void SetEngineRes(EngineNS::DataLoadEngine* pDLEngine, ShaderNS::ShaderManager* pShader, RenderNS::RendererEngine* pRender);
	private:
		//初始化窗口
		int initWindows(int width, int height);
		//初始化上下文
		int initContext();
		//初始化其他的所有配置信息
		int initOtherConfig();
	private:
		//GL 的窗口句柄
		GLFWwindow* _pWindow;
		//数据加载引擎
		EngineNS::DataLoadEngine* m_pDataLoadEngine;//数据加载
		ShaderNS::ShaderManager* m_pShaderMag;		//着色器
		RenderNS::RendererEngine* m_pRenderEngine; //渲染器
		RenderNS::TextureService* m_pTextureService;
	};
}

/*注意

	将数据填充，转载，初始化，重新类化，减少APP的私有变量数量。
*/

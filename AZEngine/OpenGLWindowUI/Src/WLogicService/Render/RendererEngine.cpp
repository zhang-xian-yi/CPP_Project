#include "RendererEngine.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//错误检查
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "OpenGLWindowUI/Src/WLogicService/Engine/Buffers/IndexBuffer.h"
#include "OpenGLWindowUI/Src/WLogicService/Engine/DataSrc/VertexArray.h"
#include "OpenGLWindowUI/Src/WLogicService/Engine/DataLoadEnginePrivate.h"
#include "OpenGLWindowUI/Src/WLogicService/Shader/ShaderManager.h"


namespace WindowsNS
{

	RendererEngine::RendererEngine()
	{
	}

	RendererEngine::~RendererEngine()
	{
	}

	void RendererEngine::Clear()
	{
		GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
	}

	/// <summary>
	/// 绘制数据加载引擎中绑定的数据
	/// </summary>
	/// <param name="m_pDataloadEngine"></param>
	/// <param name="shader"></param>
	void RendererEngine::RendererDraw(const DataLoadEnginePrivate* m_pDataloadEngine, const ShaderManager* shader)
	{
		//通过常量指针，换取常引用
		const VertexArray& VArray = *(m_pDataloadEngine->GetVertexArrayPointer());
		const IndexBuffer& IBuf = *(m_pDataloadEngine->GetIndexBufferPointer());
		//绘制
		RendererDraw(VArray, IBuf, *shader);
	}

	void RendererEngine::RendererDraw(const VertexArray& vArray, const IndexBuffer& iBuf, const ShaderManager& shader)
	{
		vArray.Bind();
		iBuf.Bind();
		shader.Bind();
		//画一个顶点数组的三角形
		//glDrawArrays(GL_TRIANGLES, 0, _VertexCount);
		//画一个索引了顶点数组的三角形 这里是故意错误从而引发GLCallWarn宏定义的效果
		//GLCallWarn(glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr));
		//正确示例
		GLCallWarn(glDrawElements(GL_TRIANGLES, iBuf.GetCount(), GL_UNSIGNED_INT, nullptr));
	}
}


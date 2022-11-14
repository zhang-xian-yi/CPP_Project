#include "RendererEngine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Engines/Buffers/IndexBuffer.h"
#include "Engines/DataSrc/VertexArray.h"
#include "Engines/DataLoadEngine.h"
#include "Shader/ShaderManager.h"
#include "Error/ErrorMacroDefie.h"
RenderNS::RendererEngine::RendererEngine()
{
}

RenderNS::RendererEngine::~RendererEngine()
{
}

void RenderNS::RendererEngine::Clear()
{
	GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
}

/// <summary>
/// 绘制数据加载引擎中绑定的数据
/// </summary>
/// <param name="m_pDataloadEngine"></param>
/// <param name="shader"></param>
void RenderNS::RendererEngine::RendererDraw(const EngineNS::DataLoadEngine* m_pDataloadEngine, const ShaderNS::ShaderManager* shader)
{
	const DataSrcNS::VertexArray& VArray = m_pDataloadEngine->GetVArray();
	const BuffersNS::IndexBuffer& IBuf = m_pDataloadEngine->GetIndexBuffer();
	//绘制
	RendererDraw(VArray, IBuf, *shader);
}

void RenderNS::RendererEngine::RendererDraw(const DataSrcNS::VertexArray& vArray, const BuffersNS::IndexBuffer& iBuf, const ShaderNS::ShaderManager& shader)
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

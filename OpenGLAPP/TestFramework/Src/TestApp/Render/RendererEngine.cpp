#include "RendererEngine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Engines/Buffers/IndexBuffer.h"
#include "Engines/DataSrc/VertexArray.h"
#include "Engines/DataLoadEnginePrivate.h"
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
/// �������ݼ��������а󶨵�����
/// </summary>
/// <param name="m_pDataloadEngine"></param>
/// <param name="shader"></param>
void RenderNS::RendererEngine::RendererDraw(const EngineNS::DataLoadEnginePrivate* m_pDataloadEngine, const ShaderNS::ShaderManager* shader)
{
	//ͨ������ָ�룬��ȡ������
	const DataSrcNS::VertexArray& VArray = *( m_pDataloadEngine->GetVertexArrayPointer());
	const BuffersNS::IndexBuffer& IBuf = *( m_pDataloadEngine->GetIndexBufferPointer() );
	//����
	RendererDraw(VArray, IBuf, *shader);
}

void RenderNS::RendererEngine::RendererDraw(const DataSrcNS::VertexArray& vArray, const BuffersNS::IndexBuffer& iBuf, const ShaderNS::ShaderManager& shader)
{
	vArray.Bind();
	iBuf.Bind();
	shader.Bind();
    //��һ�����������������
	//glDrawArrays(GL_TRIANGLES, 0, _VertexCount);
	//��һ�������˶�������������� �����ǹ������Ӷ�����GLCallWarn�궨���Ч��
	//GLCallWarn(glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr));
	//��ȷʾ��
	GLCallWarn(glDrawElements(GL_TRIANGLES, iBuf.GetCount(), GL_UNSIGNED_INT, nullptr));
}

#include "RendererEngine.h"
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//������
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
	/// �������ݼ��������а󶨵�����
	/// </summary>
	/// <param name="m_pDataloadEngine"></param>
	/// <param name="shader"></param>
	void RendererEngine::RendererDraw(const DataLoadEnginePrivate* m_pDataloadEngine, const ShaderManager* shader)
	{
		//ͨ������ָ�룬��ȡ������
		const VertexArray& VArray = *(m_pDataloadEngine->GetVertexArrayPointer());
		const IndexBuffer& IBuf = *(m_pDataloadEngine->GetIndexBufferPointer());
		//����
		RendererDraw(VArray, IBuf, *shader);
	}

	void RendererEngine::RendererDraw(const VertexArray& vArray, const IndexBuffer& iBuf, const ShaderManager& shader)
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
}


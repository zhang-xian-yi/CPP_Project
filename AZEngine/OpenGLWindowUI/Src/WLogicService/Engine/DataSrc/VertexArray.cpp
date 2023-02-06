#include "VertexArray.h"
#include "OpenGLWindowUI/Src/WLogicService/Engine/Buffers/VertexBuffer.h"//VertexBuffer
#include "OpenGLWindowUI/Src/WLogicService/Engine/Layout/VLayoutElement.h"
#include "OpenGLWindowUI/Src/WLogicService/Engine/Layout/VertexBufferLayout.h"//VertexBufferLayout
#include "OpenGLWindowUI/Src/WCommon/WGLMacroDef.h"//������
#include "GL/glew.h"

namespace WindowsNS
{
	VertexArray::VertexArray()
	{
		GLCallWarn(glGenVertexArrays(1, &m_RenderID));
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_RenderID);
	}

	void VertexArray::Bind() const
	{
		//�󶨶�������
		GLCallWarn(glBindVertexArray(m_RenderID));
	}

	void VertexArray::UnBind() const
	{
		//��󶥵�����
		GLCallWarn(glBindVertexArray(0));
	}

	void VertexArray::BindVBuffAndVLayout(const WindowsNS::VertexBuffer& VBuf, const WindowsNS::VertexBufferLayout& VLayout)
	{
		this->Bind();
		VBuf.Bind();
		//ע�ⳣ������ó�����
		const auto& elements = VLayout.GetElements();
		unsigned int offset = 0;
		//�������еĲ���Ԫ�ض���
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			//��ȡ��ʱi����
			const auto& ele = elements[i];
			//������������0
			GLCallWarn(glEnableVertexAttribArray(i));
			//���ö�������ָ�룬�������н�������λ����Ϣ����������ֻ��һ��
			//i == �󶨶����������� ��glEnableVertexAttribArray(i)��i����
			//2 == ��������float ��
			//GL_FLOAT ÿ�������Ǹ�����
			// false ��һ�� �Ƿ� ���� 0~255 ����ֵͬ����һ��0~1
			// 2 * sizeof(float) ÿ������֮��Ĳ���
			// 0 ��ʾ������ֵ��С��ƫ���� 
			GLCallWarn(glVertexAttribPointer(i, ele.GetCount(), ele.GetType(), ele.GetNormalized(), VLayout.GetStepLen(), ((const void*)offset)));
			//����ƫ���� ����ĵ�λ���ֽڣ� ����һ��folat���ֽ�����4 �����ݸ�����˵õ���������ڶ������ʼ��ַ�ֽ���
			offset += ele.GetCount() * WindowsNS::VLayoutElement::GetSizeOfType(ele.GetType());

			//
		}
	}

}

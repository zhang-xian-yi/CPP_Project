#include "VertexArray.h"
#include "../Buffers/VertexBuffer.h"//VertexBuffer
#include "../Layout/VLayoutElement.h"
#include "../Layout/VertexBufferLayout.h"//VertexBufferLayout
#include "GL/glew.h"

DataSrcNS::VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RenderID);
}

DataSrcNS::VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RenderID);
}

void DataSrcNS::VertexArray::Bind() const
{
    //�󶨶�������
    glBindVertexArray(m_RenderID);
}

void DataSrcNS::VertexArray::UnBind() const
{
    //��󶥵�����
    glBindVertexArray(0);
}

void DataSrcNS::VertexArray::BindVBuffAndVLayout(const BuffersNS::VertexBuffer& VBuf, const LayoutNS::VertexBufferLayout& VLayout)
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
        glEnableVertexAttribArray(i);
        //���ö�������ָ�룬�������н�������λ����Ϣ����������ֻ��һ��
        //i == ��i��ʼ �󶨶�������
        //2 == ��������float ��
        //GL_FLOAT ÿ�������Ǹ�����
        // false ��һ�� �Ƿ� ���� 0~255 ����ֵͬ����һ��0~1
        // 2 * sizeof(float) ÿ������֮��Ĳ���
        // 0 ��ʾ������ֵ��С��ƫ���� 
        glVertexAttribPointer(i, ele.GetCount(), ele.GetType(), ele.GetNormalized(), VLayout.GetStepLen(), (const void*)offset);
        //����ƫ����
        offset += ele.GetCount() * LayoutNS::VLayoutElement::GetSizeOfType(ele.GetType());
	}
}

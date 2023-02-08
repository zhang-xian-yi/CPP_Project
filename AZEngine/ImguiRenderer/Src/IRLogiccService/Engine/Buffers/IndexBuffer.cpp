#include "IndexBuffer.h"
#include "ImguiRenderer/Src/IRCommon/IRGLMacroDef.h"//������
#include "Glad/glad.h"

namespace ImguiRendererNS
{
    IndexBuffer::IndexBuffer()
        :m_Count(0),m_RenderID(0)
    {
    }

    IndexBuffer::~IndexBuffer()
    {
        //ɾ��������
        ReleaseBuffer();
    }

    /// <summary>
    /// ���ö������ݼ��ϵ�
    /// </summary>
    /// <param name="pArray">����ָ��</param>
    /// <param name="size">����ռ��С������Ԫ�ظ�����</param>
    void IndexBuffer::SetIndexData(const unsigned int* pArray, unsigned int count)
    {
        m_Count = count;//����Ԫ������
        //��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����
        //����һ������������
        GLCallWarn(glGenBuffers(1, &m_RenderID));
        //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
        //�����0��ʾȡ���� ʵ��ֵΪ_tmpIndicatID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
        //��ǰ�󶨵�target�Ļ��������󴴽�һ���µ����ݴ洢
        /*
        target:ָ��Ŀ�껺�������� ���ų�������ΪGL_ARRAY_BUFFER��GL_ELEMENT_ARRAY_BUFFER��
        size:ָ������������������ݴ洢�Ĵ�С�����ֽ�Ϊ��λ����
        data:ָ�������Ƶ����ݴ洢���Խ��г�ʼ�������ݵ�ָ�룬������������ݣ���ָ��NULL��
        usage:ָ�����ݴ洢��Ԥ��ʹ��ģʽ�� ���ų�������Ϊ
        GL_STREAM_DRAW:���ݴ洢���ݽ����޸�һ�β����ʹ�ü���
        GL_STATIC_DRAW:���ݴ洢���ݽ����޸�һ�β����ʹ��
        GL_DYNAMIC_DRAW:���ݴ洢���ݽ����ظ��޸Ĳ����ʹ�á�
        */
        //��ȷָ��GLUintΪ����������
        GLCallWarn(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), pArray, GL_STATIC_DRAW));
    }

    void IndexBuffer::Bind()const
    {
        //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
        //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
    }

    void IndexBuffer::UnBind()const
    {
        //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
        //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    void IndexBuffer::ReleaseBuffer()
    {
        UnBind();
        //ɾ��������
        glDeleteBuffers(1, &m_RenderID);
    }

}
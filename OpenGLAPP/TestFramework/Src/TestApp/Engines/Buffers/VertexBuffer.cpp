#include "VertexBuffer.h"
#include "GL/glew.h"
#include "Error/ErrorMacroDefie.h"//������
BuffersNS::VertexBuffer::VertexBuffer()
{
}

BuffersNS::VertexBuffer::~VertexBuffer()
{
    ReleaseBuffer();
}

/// <summary>
/// ���ö������ݼ��ϵ�
/// </summary>
/// <param name="pArray">����ָ��</param>
/// <param name="size">����ռ��С������Ԫ�ظ�����</param>
void BuffersNS::VertexBuffer::SetStaticVertexData(const void* pArray, unsigned int size)
{  
    //��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����
    //����һ������������
    GLCallWarn(glGenBuffers(1, &m_RenderID));
    //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
    //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
    GLCallWarn(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
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
    GLCallWarn(glBufferData(GL_ARRAY_BUFFER, size, pArray, GL_STATIC_DRAW));
}

void BuffersNS::VertexBuffer::SetDynamicVertexData(const void* pArray, unsigned int size)
{
    //��һ��������Ҫ���ɵĻ��������������ڶ�����Ҫ���������洢����������Ƶ�����
    //����һ������������
    GLCallWarn(glGenBuffers(1, &m_RenderID));
    //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
    //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
    GLCallWarn(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
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
    GLCallWarn(glBufferData(GL_ARRAY_BUFFER, size, pArray, GL_DYNAMIC_DRAW));

}

void BuffersNS::VertexBuffer::Bind()const
{
    //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
    //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
    GLCallWarn(glBindBuffer(GL_ARRAY_BUFFER, m_RenderID));
}

void BuffersNS::VertexBuffer::UnBind()const
{
    //��һ�����������󣬴˻������е����ݻ��Զ����뻺����������
    //�����0 ��ʾȡ����ʵ��ֵӦ��Ϊ_tmpVertexID
    GLCallWarn(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

/// <summary>
/// �ͷŻ��幦����
/// </summary>
void BuffersNS::VertexBuffer::ReleaseBuffer()
{
    UnBind();
    //ɾ��������
    glDeleteBuffers(1, &m_RenderID);
}

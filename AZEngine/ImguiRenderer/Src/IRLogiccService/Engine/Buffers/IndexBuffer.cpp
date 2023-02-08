#include "IndexBuffer.h"
#include "ImguiRenderer/Src/IRCommon/IRGLMacroDef.h"//错误检查
#include "Glad/glad.h"

namespace ImguiRendererNS
{
    IndexBuffer::IndexBuffer()
        :m_Count(0),m_RenderID(0)
    {
    }

    IndexBuffer::~IndexBuffer()
    {
        //删除缓冲区
        ReleaseBuffer();
    }

    /// <summary>
    /// 设置顶点数据集合的
    /// </summary>
    /// <param name="pArray">数组指针</param>
    /// <param name="size">数组空间大小（不是元素个数）</param>
    void IndexBuffer::SetIndexData(const unsigned int* pArray, unsigned int count)
    {
        m_Count = count;//保存元素数量
        //第一个参数是要生成的缓冲对象的数量，第二个是要输入用来存储缓冲对象名称的数组
        //生成一个缓冲区对象
        GLCallWarn(glGenBuffers(1, &m_RenderID));
        //绑定一个缓冲区对象，此缓冲区中的数据会自动进入缓冲区对象中
        //这里的0表示取消绑定 实际值为_tmpIndicatID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
        //当前绑定到target的缓冲区对象创建一个新的数据存储
        /*
        target:指定目标缓冲区对象。 符号常量必须为GL_ARRAY_BUFFER或GL_ELEMENT_ARRAY_BUFFER。
        size:指定缓冲区对象的新数据存储的大小（以字节为单位）。
        data:指定将复制到数据存储区以进行初始化的数据的指针，如果不复制数据，则指定NULL。
        usage:指定数据存储的预期使用模式。 符号常量必须为
        GL_STREAM_DRAW:数据存储内容将被修改一次并最多使用几次
        GL_STATIC_DRAW:数据存储内容将被修改一次并多次使用
        GL_DYNAMIC_DRAW:数据存储内容将被重复修改并多次使用。
        */
        //明确指定GLUint为索引的类型
        GLCallWarn(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), pArray, GL_STATIC_DRAW));
    }

    void IndexBuffer::Bind()const
    {
        //绑定一个缓冲区对象，此缓冲区中的数据会自动进入缓冲区对象中
        //这里的0 表示取消绑定实际值应该为_tmpVertexID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID));
    }

    void IndexBuffer::UnBind()const
    {
        //绑定一个缓冲区对象，此缓冲区中的数据会自动进入缓冲区对象中
        //这里的0 表示取消绑定实际值应该为_tmpVertexID
        GLCallWarn(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    void IndexBuffer::ReleaseBuffer()
    {
        UnBind();
        //删除缓冲区
        glDeleteBuffers(1, &m_RenderID);
    }

}
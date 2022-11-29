#include "VertexArray.h"
#include "Engines/Buffers/VertexBuffer.h"//VertexBuffer
#include "Engines/Layout/VLayoutElement.h"
#include "Engines/Layout/VertexBufferLayout.h"//VertexBufferLayout
#include "Error/ErrorMacroDefie.h"//错误检查
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
    //绑定顶点数组
    GLCallWarn(glBindVertexArray(m_RenderID));
}

void DataSrcNS::VertexArray::UnBind() const
{
    //解绑顶点数组
    GLCallWarn(glBindVertexArray(0));
}

void DataSrcNS::VertexArray::BindVBuffAndVLayout(const BuffersNS::VertexBuffer& VBuf, const LayoutNS::VertexBufferLayout& VLayout)
{
    this->Bind();
	VBuf.Bind();
	//注意常对象调用常函数
	const auto& elements = VLayout.GetElements();
    unsigned int offset = 0;
	//遍历所有的布局元素对象
	for (unsigned int i = 0; i < elements.size(); i++)
	{
        //获取临时i对象
        const auto& ele = elements[i];
        //启用属性数组0
        GLCallWarn(glEnableVertexAttribArray(i));
        //设置顶点属性指针，数据域中仅仅包含位置信息，所以属性只有一个
        //i == 绑定顶点数组的序号 和glEnableVertexAttribArray(i)的i关联
        //2 == 存在两个float 数
        //GL_FLOAT 每个数都是浮点数
        // false 归一化 是否将 类型 0~255 的数值同步归一到0~1
        // 2 * sizeof(float) 每个顶点之间的步长
        // 0 表示属性数值大小的偏移量 
        GLCallWarn(glVertexAttribPointer(i, ele.GetCount(), ele.GetType(), ele.GetNormalized(), VLayout.GetStepLen(), (const void*)offset));
        //设置偏移量 这里的单位是字节， 例如一个folat的字节数是4 与数据个数相乘得到属性相对于顶点的起始地址字节数
        offset += ele.GetCount() * LayoutNS::VLayoutElement::GetSizeOfType(ele.GetType());
	
        //
    }
}

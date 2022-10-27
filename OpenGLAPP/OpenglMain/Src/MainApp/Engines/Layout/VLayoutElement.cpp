#include "VLayoutElement.h"
//注意debugbreak() 是一个调试中断的函数
//该宏定义意味着一旦出现x为false 则启动调试中断
//只在MSVC中存在， 不出现在CLang或者GCC中
#define MacroDefAssert(x) if(!(x)) __debugbreak();//可能引发重定义问题,此定义一再error中被定义
//定义openggl中的部分常量
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_UNSIGNED_BYTE 0x1401

LayoutNS::VLayoutElement::VLayoutElement()
{
}

LayoutNS::VLayoutElement::VLayoutElement(unsigned int type, unsigned int count, bool normalized)
    :m_count(count),m_type(type),m_normalized(normalized)
{
    
}

LayoutNS::VLayoutElement::~VLayoutElement()
{
}

unsigned int LayoutNS::VLayoutElement::GetType() const
{
    return m_type;
}

unsigned int LayoutNS::VLayoutElement::GetCount() const
{
    return m_count;
}

bool LayoutNS::VLayoutElement::GetNormalized() const
{
    return m_normalized;
}

void LayoutNS::VLayoutElement::SetType(unsigned int type) 
{
    this->m_type = type;
}

void LayoutNS::VLayoutElement::SetCount(unsigned int count) 
{
    this->m_count = count;
}

void LayoutNS::VLayoutElement::SetNormalized(bool normalized) 
{
    this->m_normalized = normalized;
}

unsigned int LayoutNS::VLayoutElement::GetSizeOfType(unsigned int type)
{
    switch (type)
    {
        case GL_UNSIGNED_INT: return 4;
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
        default:break;        
    }
    //类型转换失败，此处中断
    MacroDefAssert(false);
    return 0;
}

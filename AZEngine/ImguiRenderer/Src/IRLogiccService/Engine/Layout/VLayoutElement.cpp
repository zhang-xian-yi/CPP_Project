#include "VLayoutElement.h"
#include "ImguiRenderer/Src/IRCommon/IRGLMacroDef.h"//错误检查


#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_UNSIGNED_BYTE 0x1401
namespace ImguiRendererNS
{
	VLayoutElement::VLayoutElement()
	{
	}

	VLayoutElement::VLayoutElement(unsigned int type, unsigned int count, bool normalized)
		:m_count(count), m_type(type), m_normalized(normalized)
	{

	}

	VLayoutElement::~VLayoutElement()
	{
	}

	unsigned int VLayoutElement::GetType() const
	{
		return m_type;
	}

	unsigned int VLayoutElement::GetCount() const
	{
		return m_count;
	}

	bool VLayoutElement::GetNormalized() const
	{
		return m_normalized;
	}

	void VLayoutElement::SetType(unsigned int type)
	{
		this->m_type = type;
	}

	void VLayoutElement::SetCount(unsigned int count)
	{
		this->m_count = count;
	}

	void VLayoutElement::SetNormalized(bool normalized)
	{
		this->m_normalized = normalized;
	}

	unsigned int VLayoutElement::GetSizeOfType(unsigned int type)
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
}


#pragma once

#include <vector>
#include "VLayoutElement.h"
//定义openggl中的部分常量
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_UNSIGNED_BYTE 0x1401
#define GL_FALSE 0
#define GL_TRUE 1
namespace LayoutNS
{
	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() :m_Stride(0) {}
		~VertexBufferLayout() {}
		//返回布局元素集合
		inline const std::vector<LayoutNS::VLayoutElement>& GetElements()const
		{
			return m_Elements;
		}
		//返回步长
		inline unsigned int GetStepLen()const { return m_Stride; }

		template<class T>
		void Push(unsigned int count)
		{
			//触发一个断言
			static_assert(false);
		}
		//模板的特化，指定模板转换的类型
		template<>
		void Push<float>(unsigned int count)
		{
			LayoutNS::VLayoutElement obj(GL_FLOAT,count,false);
			m_Elements.push_back(obj);
			//步长计算
			m_Stride += count * VLayoutElement::GetSizeOfType(GL_FLOAT);
		}
		template<>
		void Push<unsigned int>(unsigned int count)
		{
			LayoutNS::VLayoutElement obj(GL_UNSIGNED_INT, count, false);
			m_Elements.push_back(obj);
			m_Stride += count * VLayoutElement::GetSizeOfType(GL_UNSIGNED_INT);
		}
		template<>
		void Push<unsigned char>(unsigned int count)
		{
			//这里归一化为true 表示 字符串类型的传递需要转换为0~1的folat类型
			LayoutNS::VLayoutElement obj(GL_UNSIGNED_BYTE, count, true);
			m_Elements.push_back(obj);
			m_Stride += count * VLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE);
		}
	private:
		//布局元素的向量集合
		std::vector<LayoutNS::VLayoutElement> m_Elements;
		unsigned int m_Stride;//每个顶点之间的距离==步长
	};
}

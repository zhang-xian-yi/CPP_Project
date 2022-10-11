#pragma once

#include <vector>
#include "VLayoutElement.h"
//����openggl�еĲ��ֳ���
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
		//���ز���Ԫ�ؼ���
		inline const std::vector<LayoutNS::VLayoutElement>& GetElements()const
		{
			return m_Elements;
		}
		//���ز���
		inline unsigned int GetStepLen()const { return m_Stride; }

		template<class T>
		void Push(unsigned int count)
		{
			//����һ������
			static_assert(false);
		}
		//ģ����ػ���ָ��ģ��ת��������
		template<>
		void Push<float>(unsigned int count)
		{
			LayoutNS::VLayoutElement obj(GL_FLOAT,count,false);
			m_Elements.push_back(obj);
			//��������
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
			//�����һ��Ϊtrue ��ʾ �ַ������͵Ĵ�����Ҫת��Ϊ0~1��folat����
			LayoutNS::VLayoutElement obj(GL_UNSIGNED_BYTE, count, true);
			m_Elements.push_back(obj);
			m_Stride += count * VLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE);
		}
	private:
		//����Ԫ�ص���������
		std::vector<LayoutNS::VLayoutElement> m_Elements;
		unsigned int m_Stride;//ÿ������֮��ľ���==����
	};
}

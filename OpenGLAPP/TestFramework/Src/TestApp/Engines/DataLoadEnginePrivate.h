#pragma once
#include <string>
//ǰ������
namespace BuffersNS
{
	class VertexBuffer;
	class IndexBuffer;
}

namespace DataSrcNS
{
	class VertexArray;
}

namespace LayoutNS
{
	class VertexBufferLayout;
}
//��������������ռ�
namespace EngineNS
{
	/// <summary>
	/// �������ݼ��ص�����
	/// </summary>
	class DataLoadEnginePrivate
	{
	public:
		DataLoadEnginePrivate();
		~DataLoadEnginePrivate();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		//���붥������
		void SetVertexData(const void* pArray, unsigned int size);
		//���ز��ֶ��㻺����
		LayoutNS::VertexBufferLayout* GetVBufLayoutPointer()const;
		//��ȡ���������ָ��
		DataSrcNS::VertexArray* GetVertexArrayPointer()const;
		//��ȡ������������ָ��
		BuffersNS::IndexBuffer* GetIndexBufferPointer()const;
		//��ȡ������������ָ��
		BuffersNS::VertexBuffer* GetVertexBufferPointer()const;
		//�󶨶��㻺�����Ͷ��㲼�ֵĹ�ϵ
		void BindVBuffAndVLayout();
		//�ͷ���Դ
		void ReleaseSrc();
	private:
		//����
		BuffersNS::IndexBuffer* m_pIndexBufferS;
		BuffersNS::VertexBuffer* m_pVertexBufferS;
		LayoutNS::VertexBufferLayout* m_pVBufLayout;//���㻺�������ֶ���
		//ע��˴��Ķ��������������� һ�����������ϵĶ���
		//����һ��������԰��� ���򣬴�С���Ƕȣ��¶ȵȣ������ж�����Ϣ�ļ���
		DataSrcNS::VertexArray* m_pVArray;//������������
	};

}

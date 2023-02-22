#pragma once
#include <string>
//ǰ������
namespace ImguiRendererNS
{
	class VertexBuffer;
	class IndexBuffer;
	class VertexBufferLayout;
	class VertexArray;
}

//��������������ռ�
namespace ImguiRendererNS
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
		VertexBufferLayout* GetVBufLayoutPointer()const;
		//��ȡ���������ָ��
		VertexArray* GetVertexArrayPointer()const;
		//��ȡ������������ָ��
		IndexBuffer* GetIndexBufferPointer()const;
		//��ȡ������������ָ��
		VertexBuffer* GetVertexBufferPointer()const;
		//�󶨶��㻺�����Ͷ��㲼�ֵĹ�ϵ
		void BindVBuffAndVLayout();
		//�ͷ���Դ
		void ReleaseSrc();
	private:
		//����
		IndexBuffer* m_pIndexBufferS;
		VertexBuffer* m_pVertexBufferS;
		VertexBufferLayout* m_pVBufLayout;//���㻺�������ֶ���
		//ע��˴��Ķ��������������� һ�����������ϵĶ���
		//����һ��������԰��� ���򣬴�С���Ƕȣ��¶ȵȣ������ж�����Ϣ�ļ���
		VertexArray* m_pVArray;//������������
	};

}

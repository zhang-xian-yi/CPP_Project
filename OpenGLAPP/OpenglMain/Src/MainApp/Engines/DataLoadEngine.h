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
	class DataLoadEngine
	{
	public:
		DataLoadEngine();
		~DataLoadEngine();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		const BuffersNS::IndexBuffer& GetIndexBuffer()const;
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		//���붥������
		void SetVertexData(const void* pArray, unsigned int size);
		const DataSrcNS::VertexArray& GetVArray()const;
		//��ʼ�����ݻ���
		void InitDataEnvir();
		//�ͷ���Դ
		void ReleaseSrc();
	private:
		//����
		BuffersNS::IndexBuffer* m_pIndexBufferS;
		BuffersNS::VertexBuffer* m_pVertexBufferS;
		LayoutNS::VertexBufferLayout* m_pVBufLayout;//���㻺�������ֶ���
		DataSrcNS::VertexArray* m_pVArray;//������������
	};

}

#pragma once

namespace ImguiRendererNS
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray,unsigned int count);
		void Bind()const;//���������幦����
		void UnBind()const;//����������幦����
		void ReleaseBuffer();//�ͷŻ�����
		//���� ��ȡ��Ա�����ĺ���
		inline unsigned int GetCount()const { return m_Count; }
	private:
		//��Ⱦ��ID
		unsigned int m_RenderID;
		//��������
		unsigned int m_Count;
	};

}

#pragma once

namespace ImguiRendererNS
{
	/// <summary>
	/// ���㻺�幦������ҵ���߼�
	/// </summary>
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		void SetStaticVertexData(const void* pArray,unsigned int size);
		void SetDynamicVertexData(const void* pArray, unsigned int size);
		void Bind()const;
		void UnBind()const;
		void ReleaseBuffer();//�ͷŻ�����
	private:
		//��Ⱦ��ID
		unsigned int m_RenderID;
	};

}

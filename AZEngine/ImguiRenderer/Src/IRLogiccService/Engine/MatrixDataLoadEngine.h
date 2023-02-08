#pragma once
#include <string>

//ǰ������
namespace ImguiRendererNS
{
	class DataLoadEnginePrivate;
}

//��������������ռ�
namespace ImguiRendererNS
{
	/// <summary>
	/// �������ݼ��ص�����
	/// </summary>
	class MatrixDataLoadEngine
	{
	public:
		MatrixDataLoadEngine();
		~MatrixDataLoadEngine();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		//���붥������
		void SetVertexData(const void* pArray, unsigned int size);
		//�������ݼ��������ָ��
		ImguiRendererNS::DataLoadEnginePrivate* GetDataLoadEnginePointer()const;
	private:
		//˽�д����߼�
		ImguiRendererNS::DataLoadEnginePrivate* m_pDLEPrivate;
	};

}

#pragma once
#include <string>

//ǰ������
namespace WindowsNS
{
	class DataLoadEnginePrivate;
}

//��������������ռ�
namespace WindowsNS
{
	/// <summary>
	/// �������ݼ��ص�����
	/// </summary>
	class RectangleDataLoadEngine
	{
	public:
		RectangleDataLoadEngine();
		~RectangleDataLoadEngine();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		//���붥������
		void SetVertexData(const void* pArray, unsigned int size);
		//�������ݼ��������ָ��
		WindowsNS::DataLoadEnginePrivate* GetDataLoadEnginePointer()const;
	private:
		//˽�д����߼�
		WindowsNS::DataLoadEnginePrivate* m_pDLEPrivate;
	};

}

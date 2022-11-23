#pragma once
#include <string>
//ǰ������
namespace EngineNS
{
	class DataLoadEnginePrivate;
}
//��������������ռ�
namespace EngineNS
{
	/// <summary>
	/// �������ݼ��ص�����
	/// </summary>
	class TextureDataLoadEngine
	{
	public:
		TextureDataLoadEngine();
		~TextureDataLoadEngine();
		//����������������ַ�Լ�Ԫ�ظ�������ָ������Ϊint
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//ע����Ϊ���ڸı䶥��ռ�Ŀ��ܣ����Դ���Ķ������ݿռ��ڴ治�ܴ������
		//���붥������
		void SetVertexData(const void* pArray, unsigned int size);
		//��ʼ��������
		void InitTextureEnvir();
		//�������ݼ��������ָ��
		EngineNS::DataLoadEnginePrivate* GetDataLoadEnginePointer()const;
	private:
		//˽�д����߼�
		EngineNS::DataLoadEnginePrivate* m_pDLEPrivate;
	};

}

#pragma once
namespace LayoutNS
{
	/// <summary>
	/// ��������Ԫ�صĹؼ���Ϣ
	/// </summary>
	class VLayoutElement
	{
	public:
		VLayoutElement();
		VLayoutElement(unsigned int type, unsigned int count,bool normalized);
		~VLayoutElement();

		unsigned int GetType()const;//��ȡ��Ա����
		unsigned int GetCount()const;//
		bool GetNormalized()const;

		void SetType(unsigned int type);//���ó�Ա����
		void SetCount(unsigned int count);//
		void SetNormalized(bool normalized);

		static unsigned int GetSizeOfType(unsigned int type);
	private:
		unsigned int m_type;//����
		unsigned int m_count;//����
		bool		 m_normalized; //�Ƿ��һ��
	};
}



#pragma once

namespace SerializationToolNS
{
	//��Ϸ�����ģ�������
	class SerializationToolMdlControl
	{
	public:
		SerializationToolMdlControl();
		~SerializationToolMdlControl();
	public:
		//����ģ��
		virtual bool ConstructModule();
		//����ģ��
		virtual bool DestoryModule();
		//��ȡģ��״̬
		virtual bool IsUse()const;
	private:
		bool m_bIsUse;//ģ���Ƿ����
	};
}



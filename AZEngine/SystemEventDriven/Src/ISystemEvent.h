#pragma once

namespace SysEventDNS
{
	//ȷ���¼���Ψһ����
	enum class ESysEventId:unsigned int
	{
		None = 0,
		KeyBoardPress= 100,
		KeyBoardRelease,
		MouseMove = 200, 
		MousePress, MouseRelease, MouseScroll,WindowResize, WindowMove, WindowClose, 
		ApplicationUpdate = 500, 
		ApplicationRender
	};

	//�����¼�������̳еĸ���
	class IEvent
	{

	protected:
		bool m_isHandle;//�Ƿ���--�����¼��Ƿ��������
		ESysEventId m_eId;//�����¼���˭����
	};

	/// <summary>
	/// ���������¼�ID���¼�������
	/// </summary>
	class IConnect
	{
	public:
		virtual bool Connect();
	};


}
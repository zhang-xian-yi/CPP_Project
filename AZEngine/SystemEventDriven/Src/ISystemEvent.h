#pragma once

namespace SysEventDNS
{
	/// <summary>
	/// ȷ���¼��ĵ��ú���һ��     
	/// </summary>
	enum class ESysEventType :unsigned short
	{
		None = 0,
		KeyBoardTyoe    =  127, //�������� Լ����Χ[1,127)
		MouseMoveType   =  255, //��������¼� Լ����Χ[128,255)
		WindowsType     =  511, //���������¼� Լ����Χ[256,511)
		ApplicationType =  1023,	    //Ӧ�ó��������¼� Լ����Χ[1024,--)
	};

	//ȷ���¼���Ψһ����
	enum class ESysEventId:unsigned int
	{
		None = 0,
		KeyBoardPress = 1,
		KeyBoardRelease,
		MouseMove = 256, 
		MousePress, MouseRelease, MouseScroll,WindowResize, WindowMove, WindowClose, 
		ApplicationUpdate = 513, 
		ApplicationRender
	};





}
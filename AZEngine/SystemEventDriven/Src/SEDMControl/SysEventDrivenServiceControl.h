#pragma once
#include "CMNInterface/IMdlService.h"

namespace SysEventDNS
{
	/// <summary>
	/// ��Ϸ�����ҵ���߼�������
	/// </summary>
	class SysEventDrivenServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		SysEventDrivenServiceControl();
		~SysEventDrivenServiceControl();
	};

}


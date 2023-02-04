#pragma once
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

namespace WindowsNS
{
	class WindowsServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		WindowsServiceControl();
		~WindowsServiceControl();
	};

}


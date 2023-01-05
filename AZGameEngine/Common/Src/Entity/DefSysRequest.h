#pragma once
#include "Interface/ISysRequest.h"
namespace CommonNS
{
	class CommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		virtual bool IsValid()const override;
	};
}



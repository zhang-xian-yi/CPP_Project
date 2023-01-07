#pragma once
#include <CMNCommon/CMNExpMarcoDefine.h> //µ¼³öºê
#include <CMNInterface/ISysRequest.h>
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



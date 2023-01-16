#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //µ¼³öºê
#include <CMNInterface/ISysRequest.h>
namespace MdlCommonNS
{
	class MdlCommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		virtual bool IsValid()const override;
	};
}



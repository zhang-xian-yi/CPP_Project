#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //������
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



#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysRequest.h>
#include <any>
namespace MdlCommonNS
{
	class MdlCommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		//设置指定数据，并且该类直接控制any对象的内存
		void SetData(std::any& data);
		//获取指定数据，从接口处继承
		virtual std::any& GetData()const override;
	private:
		std::any* m_pData;
	};
}



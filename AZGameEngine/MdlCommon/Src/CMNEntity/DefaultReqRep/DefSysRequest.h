#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysRequest.h>
namespace MdlCommonNS
{
	/*
	约定  Any对象必须在堆上申请内存，且申请之后被设置进入请求，内存移交请求管理
	*/
	class Any;

	class MdlCommonDLLAPI DefSysRequest:public ISysRequest
	{
	public:
		DefSysRequest();
		~DefSysRequest();
	public:
		//设置指定数据，并且该类直接控制any对象的内存
		void SetData(Any& data);
		//获取指定数据，从接口处继承
		virtual Any& GetData()const override;
	private:
		Any* m_pData;
	};
}



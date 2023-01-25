#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysResponse.h>

namespace MdlCommonNS
{
	//接口实现类
	class MdlCommonDLLAPI DefSysResponse :public ISysResponse
	{
	public:
		DefSysResponse();
		DefSysResponse(std::any& data);
		~DefSysResponse();
	public:
		//设置指定数据，并且该类直接控制any对象的内存
		void SetData(std::any& data);
		//获取指定数据，从接口处继承
		virtual std::any& GetData()const override;
	private:
		std::any* m_pData;
	};
}


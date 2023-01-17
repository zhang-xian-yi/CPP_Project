#pragma once

namespace MdlCommonNS
{
	//前置声明
	enum class EModuleType:unsigned char;
	class IMdlFactory;
}
//
namespace MdlScheduleNS
{
	/// <summary>
	/// 模块调度的控制器实现私有逻辑
	/// </summary>
	class MdlScheduleControlPrivate
	{
	public:
		//注册所有笑话你ImdlService接口的功能模块
		void InitAndRegisterAllService();
	private:
		//根据工厂对象创建与注册指定实例
		void InitAndRegisterService(MdlCommonNS::EModuleType type,MdlCommonNS::IMdlFactory* factory);

	};
}



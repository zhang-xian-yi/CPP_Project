#include "AZMStatus.h"
#include <map>
namespace CommonNS
{
	//注意 枚举类 允许前置声明
	//描述模块状态和返回信息的数据
	//enum class 枚举类 -> 访问枚举必须加LMStatus的限定符
	//unsigned char 限制枚举类的 数据大小
	enum class AZMStatus :unsigned char
	{
		E_ModuleInit_Succ,//模块初始化成功
		E_ModuleInit_Failed,//模块初始化失败
		E_ModuleRunning,//模块正在运行
		E_ModuleNotInit,//模块没有初始化
		E_ModuleNotUse,//模块不可用
	};

	//描述每个枚举的详细信息
	struct SEnumDetailNode
	{
		std::string m_enumStr;
		std::string m_descStr;
		std::string m_helpStr;
	};

	template<typename T>
	struct SEnumDetail
	{
		static const std::map<T,SEnumDetailNode> DetailMap;
	};

	//定义静态变量的静态函数，初始化枚举
	static const std::map<AZMStatus, SEnumDetailNode>& initStatusInfo()
	{
		
		return SEnumDetail<AZMStatus>::DetailMap;
	}
	///类外定义static 变量
	const std::map<AZMStatus, SEnumDetailNode> SEnumDetail<AZMStatus>::DetailMap = initStatusInfo();


	std::string GetStatusDesc(AZMStatus status)
	{
		std::map<AZMStatus, SEnumDetailNode>::const_iterator finditem = SEnumDetail<AZMStatus>::DetailMap.find(status);
		//如果包含
		if (SEnumDetail<AZMStatus>::DetailMap.end() != finditem)
		{
			SEnumDetailNode node = (*finditem).second;
			return node.m_descStr;
		}
		return  std::string();
	}

	std::string GetStatusHelp(AZMStatus status)
	{
		std::map<AZMStatus, SEnumDetailNode>::const_iterator finditem = SEnumDetail<AZMStatus>::DetailMap.find(status);
		//如果包含
		if (SEnumDetail<AZMStatus>::DetailMap.end() != finditem)
		{
			SEnumDetailNode node = (*finditem).second;
			return node.m_helpStr;
		}
		return  std::string();
	}



}

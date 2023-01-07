#include "AZMStatus.h"
#include <map>
namespace CommonNS
{
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

#pragma once
#include <string>
namespace MdlCommonNS
{
	//状态码
	enum class AZMStatus :unsigned char;

	/// <summary>
	/// 约定每次信息所产生的结构
	/// </summary>
	typedef struct __SInformationBean
	{
		bool IsSuccess;//是否成功的标记
		AZMStatus StatusCode;//状态码
		std::string Message;//消息描述
	}MsgBean;
}



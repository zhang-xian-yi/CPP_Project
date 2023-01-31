#include "IMdlOperat.h"
#include "IMdlService.h"
#include "ISysRequest.h"
#include "ISysResponse.h"
#include "IMdlFactory.h"
//此文件主要为了定义抽象接口的纯虚析构函数的实现

namespace MdlCommonNS
{
	/// <summary>
	/// 模块操作析构
	/// </summary>
	IMdlOperat::~IMdlOperat()
	{

	}
	/// <summary>
	/// 业务逻辑纯虚析构函数实现
	/// </summary>
	IMdlService::~IMdlService()
	{

	}
	/// <summary>
	/// 请求纯虚析构函数实现
	/// </summary>
	ISysRequest::~ISysRequest()
	{

	}
	/// <summary>
	/// 响应纯虚析构函数实现
	/// </summary>
	ISysResponse::~ISysResponse()
	{

	}

	/// <summary>
	/// 工厂纯虚析构函数实现
	/// </summary>
	IMdlFactory::~IMdlFactory()
	{

	}
}
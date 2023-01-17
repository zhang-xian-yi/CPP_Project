#include "OpenGLUIServiceControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

namespace OpenGLUINS
{
	OpenGLUIServiceControl::OpenGLUIServiceControl()
	{
	}

	OpenGLUIServiceControl::~OpenGLUIServiceControl()
	{
	}
	/// <summary>
/// 进行业务逻辑处理
/// </summary>
/// <param name="para"></param>
/// <returns></returns>
	std::unique_ptr<MdlCommonNS::ISysResponse> OpenGLUIServiceControl::DoService(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}
}
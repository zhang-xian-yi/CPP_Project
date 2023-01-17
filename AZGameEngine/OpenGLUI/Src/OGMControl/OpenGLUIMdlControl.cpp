#include "OpenGLUIMdlControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"
namespace OpenGLUINS
{
	OpenGLUIMdlControl::OpenGLUIMdlControl()
		:m_bIsUse(false)
	{
	}
	OpenGLUIMdlControl::~OpenGLUIMdlControl()
	{
	}

	std::unique_ptr<MdlCommonNS::ISysResponse> OpenGLUIMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	std::unique_ptr<MdlCommonNS::ISysResponse> OpenGLUIMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
	}

	//»ñÈ¡Ä£¿é×´Ì¬
	bool OpenGLUIMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
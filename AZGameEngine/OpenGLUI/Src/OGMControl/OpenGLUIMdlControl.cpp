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

	MdlCommonNS::ISysResponse* OpenGLUIMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}

	MdlCommonNS::ISysResponse* OpenGLUIMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{
		auto pResult = new MdlCommonNS::DefSysResponse();

		return pResult;
	}

	//»ñÈ¡Ä£¿é×´Ì¬
	bool OpenGLUIMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
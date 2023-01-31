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

	bool OpenGLUIMdlControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}

	bool OpenGLUIMdlControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
	{


		return true;
	}

	//»ñÈ¡Ä£¿é×´Ì¬
	bool OpenGLUIMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
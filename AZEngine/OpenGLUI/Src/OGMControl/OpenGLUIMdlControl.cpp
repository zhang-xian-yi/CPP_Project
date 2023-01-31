#include "OpenGLUIMdlControl.h"
namespace OpenGLUINS
{
	OpenGLUIMdlControl::OpenGLUIMdlControl()
		:m_bIsUse(false)
	{
	}
	OpenGLUIMdlControl::~OpenGLUIMdlControl()
	{
	}

	bool OpenGLUIMdlControl::ConstructModule()
	{


		return true;
	}

	bool OpenGLUIMdlControl::DestoryModule()
	{


		return true;
	}

	//»ñÈ¡Ä£¿é×´Ì¬
	bool OpenGLUIMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
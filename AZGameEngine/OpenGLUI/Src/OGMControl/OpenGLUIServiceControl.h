#pragma once
#include "CMNInterface/IMdlService.h"
#include "CMNInterface/ISysRequest.h"
#include "CMNInterface/ISysResponse.h"

namespace OpenGLUINS
{
	class OpenGLUIServiceControl :public MdlCommonNS::IMdlService
	{
	public:
		OpenGLUIServiceControl();
		~OpenGLUIServiceControl();
	public:
		virtual std::unique_ptr<MdlCommonNS::ISysResponse> DoService(const std::unique_ptr<MdlCommonNS::ISysRequest>& para = nullptr) override;
	};

}


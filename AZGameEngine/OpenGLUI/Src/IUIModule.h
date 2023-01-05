#pragma once
#include "Common/MarcoDefine.h"

namespace OpenGLUINS
{
	//前置声明 枚举
	enum class LMStatus :unsigned char;


	//日志模块的模块
	class OpenGLUIAPI IUIModule
	{
	public:
		//初始化日志模块
		virtual LMStatus InitModule() = 0;
		//停止日志模块
		virtual LMStatus StopModule() = 0;
	};
}
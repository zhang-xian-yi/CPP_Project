#pragma once
#include <string>
#include <CMNCommon/CMNExpMarcoDefine.h> //������

namespace CommonNS
{
	enum class EModuleType:unsigned char
	{
	};

	//��ȡģ������
	CommonDLLAPI std::string GetModuleName(EModuleType mdl);
}


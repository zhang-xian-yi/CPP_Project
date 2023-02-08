#include "SerializationTool/Src/STCommon/CoreMacroDef.h"
#include "SerializationTool/Src/STCommon/STExpMarcoDefine.h"
namespace SerializationToolNS
{
	//前置声明
	class ISerialization;
}

namespace SerializationToolNS
{
	//日志模块的工厂
	class SerializationToolNSAPI SerializationToolFactory
	{
		//禁止反复定义工厂，禁止delelte 工厂对象
		SingletonDefaultConstruct(SerializationToolFactory)

	public:
		ISerialization* CreateServiceInstance();
	};
}

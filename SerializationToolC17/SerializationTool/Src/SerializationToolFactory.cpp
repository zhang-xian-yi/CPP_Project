#include "SerializationToolFactory.h"
#include "SerializationTool/Src/ISerialization.h"
#include "STMControl/SerializationToolServiceControl.h"
namespace SerializationToolNS
{
	/// <summary>
	/// ÒµÎñÊµÀý
	/// </summary>
	/// <returns></returns>
	ISerialization* SerializationToolFactory::CreateServiceInstance()
	{
		return new SerializationToolServiceControl();
	}

}
#include "SerializationToolFactory.h"
#include "SerializationTool/Src/ISerialization.h"
#include "STMControl/SerializationToolServiceControl.h"
namespace SerializationToolNS
{
	/// <summary>
	/// ҵ��ʵ��
	/// </summary>
	/// <returns></returns>
	ISerialization* SerializationToolFactory::CreateServiceInstance()
	{
		return new SerializationToolServiceControl();
	}

}
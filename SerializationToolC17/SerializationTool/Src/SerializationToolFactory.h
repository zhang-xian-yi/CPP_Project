#include "SerializationTool/Src/STCommon/CoreMacroDef.h"
#include "SerializationTool/Src/STCommon/STExpMarcoDefine.h"
namespace SerializationToolNS
{
	//ǰ������
	class ISerialization;
}

namespace SerializationToolNS
{
	//��־ģ��Ĺ���
	class SerializationToolNSAPI SerializationToolFactory
	{
		//��ֹ�������幤������ֹdelelte ��������
		SingletonDefaultConstruct(SerializationToolFactory)

	public:
		ISerialization* CreateServiceInstance();
	};
}

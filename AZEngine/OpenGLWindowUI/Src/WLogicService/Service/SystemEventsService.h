#pragma once
#include "EventDrivenSystem/Src/ISystemEvent.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h" //����ģ������
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���
namespace EventDrivenSysNS
{

	struct EventHandler;//�¼�����Ľṹ��
}

namespace EventCommonNS
{
	enum class ESysEventId :unsigned short;//ϵͳ�¼�id
}

namespace WindowsNS
{
	/// <summary>
	/// ϵͳ�¼�����
	/// </summary>
	class SystemEventsService
	{
	public:
		SystemEventsService() = default;
		~SystemEventsService() = default;

	public:
		//ע��Glfw ��openggl�����ʼ���¼���׽
		void InitSysEventRegister(GLFWwindow* pGLWin);
	};
}
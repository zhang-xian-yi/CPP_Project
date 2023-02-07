#pragma once


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
		//���¼��������
		void BindEventResponse(EventCommonNS::ESysEventId eid, EventDrivenSysNS::EventHandler& handle_t);
	};
}
#pragma once


//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

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
		//��ʼ��ϵͳ�¼���Ӧ
		void InitSysEventRegister(GLFWwindow* pGLWin);

	};
}
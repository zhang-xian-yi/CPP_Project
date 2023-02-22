#pragma once
#include "IWindow.h"

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace WindowsNS
{
	/// <summary>
	/// ��GL���� �Ŀ��ƹ���
	/// </summary>
	class GLWindowService
	{
	public:
		GLWindowService();
		~GLWindowService();

		//��ʼ��������
		int initWinEnvir(WindowProps& pros);
		//ˢ�´��ڽ�������
		int FlushWindow();
		//����Ĭ�ϵĴ��ڱ���
		void DefaultWindowBackground();
		//�رմ���
		int StopWindows();
		//���ش��ھ��
		GLFWwindow* GetGLFWindowsHandle()const;
	private:
		int initWindows(WindowProps& pros);
		//��ʼ������������������Ϣ
		int initWindowsConfig();
	private:
		//GL �Ĵ��ھ��
		GLFWwindow* _pWindow = nullptr;
	};
}



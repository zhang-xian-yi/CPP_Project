#pragma once

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace EnvirmentNS
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
		int initWinEnvir(int width, int height);
		//ˢ�´��ڽ�������
		int FlushWindow();
		//����Ĭ�ϵĴ��ڱ���
		void DefaultWindowBackground();
		//�رմ���
		int StopWindows();
		//���ش��ھ��
		GLFWwindow* GetGLFWindowsHandle()const;
	private:
		int initWindows(int width, int height);
		//��ʼ������������������Ϣ
		int initWindowsConfig();
	private:
		//GL �Ĵ��ھ��
		GLFWwindow* _pWindow = nullptr;
	};
}



#pragma once

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace EnvirmentNS
{
	class ImGuiService
	{
	public:
		ImGuiService();
		~ImGuiService();

		//��ʼ��������
		int initEnvir(int width, int height);
		//��ʼ����
		int runWindow();
		//�رմ���
		int stopWindows();
	private:
		//��ʼ������
		int initWindows(GLFWwindow* window);
		//��ʼ��������
		int initContext();
		//��ʼ������������������Ϣ
		int initOtherConfig();
	private:
		//GL �Ĵ��ھ��
		GLFWwindow* _pWindow;
	};
}



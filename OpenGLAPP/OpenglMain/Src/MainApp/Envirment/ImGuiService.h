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
		int initEnvir(GLFWwindow* window);
		//��ʼ����
		int FlushFrame();
		//�رմ���
		int EndIMGUIService();
	private:
		//��ʼ��������
		int initContext(GLFWwindow* window);
	private:
		//���ھ��
		GLFWwindow* m_pWindow = nullptr;
	};
}



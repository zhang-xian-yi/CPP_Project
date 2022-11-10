#pragma once

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace EntityNS
{
	class RenderObj;//��Ⱦ�������
}

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
		int FlushFrame(EntityNS::RenderObj& renderObj);
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



#pragma once
//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace EnvirmentNS
{
	class FrameworkService
	{
	public:
		FrameworkService();
		~FrameworkService();

		//��ʼ��������
		int initEnvir(GLFWwindow* window);
		//ˢ�¿�ʼ
		int FlushFrameStart();
		//ˢ�½���
		int FlushFrameEnd();
		//�رմ���
		int EndFrameworkService();
	private:
		int initImGUI();
	private:
		//GL �Ĵ��ھ��
		GLFWwindow* m_pWindow = nullptr;
	};
}



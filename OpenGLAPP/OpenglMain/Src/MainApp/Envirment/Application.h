#pragma once

//ǰ������ 
namespace EnvirmentNS
{
	class OpenGLUIService;//Opengl ���Դ���ҵ��
	class ImGuiService;//ImGUI ���Դ���ҵ��
}

namespace EnvirmentNS
{
	/// <summary>
	/// opengl �Ĳ���APP����
	/// </summary>
	class Application
	{
	public:
		Application();
		~Application();

		//��ʼ��������
		int initEnvir(int width, int height);
		//��ʼ����
		int runWindow();
		//�رմ���
		int stopWindows();

	private:
		//��ʼ������
		int initWindows(int width, int height);
		//��ʼ��������
		int initContext();
		//��ʼ������������������Ϣ
		int initOtherConfig();
	private:
		//���ݼ�������
		EnvirmentNS::OpenGLUIService* m_pOpenGLWinS;//���ݼ���
		EnvirmentNS::ImGuiService* m_pIMGUIWinS;//���ݼ���
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

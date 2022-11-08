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
		int InitAPPEnvir(int width, int height);
		//��ʼ����
		int runWindow();
		//�رմ���
		int stopWindows();

	private:
		//��ʼ������
		int initChildWindows(int width, int height);
	private:
		//���ݼ�������
		EnvirmentNS::OpenGLUIService* m_pOpenGLWinS;//���ݼ���
		EnvirmentNS::ImGuiService* m_pIMGUIWinS;//���ݼ���
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

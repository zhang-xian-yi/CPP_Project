#pragma once

//ǰ������ 
namespace EnvirmentNS
{
	class OpenGLUIService;//Opengl ����ҵ��
	class ImGuiService;//ImGUI ҵ��
	class GLWindowService;// ����ҵ��
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
		int RunAPP();
		//�رմ���
		int StopAPP();

	private:
		//��ʼ������
		int InitAPPContext(int width, int height);
	private:
		//���ݼ�������
		EnvirmentNS::OpenGLUIService* m_pOpenGLUIS;//OpengGL ��UIҵ��
		EnvirmentNS::ImGuiService* m_pIMGUIS;//ImGUI ��ҵ��
		EnvirmentNS::GLWindowService* m_pWinS;//
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

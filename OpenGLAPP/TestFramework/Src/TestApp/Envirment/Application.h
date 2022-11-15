#pragma once

//ǰ������ 
namespace EnvirmentNS
{
	class GLWindowService;//Opengl ����ҵ��
	class FrameworkService;//ImGUI ҵ��
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
		//����ҵ��
		EnvirmentNS::GLWindowService* m_pWinS;//
		EnvirmentNS::FrameworkService* m_pFrameTestS;//��ܲ���ҵ��
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

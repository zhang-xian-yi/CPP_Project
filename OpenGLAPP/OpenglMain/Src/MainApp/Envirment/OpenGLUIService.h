#pragma once

//ǰ������ 
struct GLFWwindow;//from  glew�������⣬ ���ܽ����������������ռ���

namespace EngineNS
{
	class DataLoadEngine;//���ݼ�������
}

namespace ShaderNS
{
	class ShaderManager;//��ɫ������ҵ��
}

namespace RenderNS
{
	class RendererEngine;//��Ⱦ������
	class TextureService;//����
}


namespace EnvirmentNS
{
	/// <summary>
	/// opengl �Ĳ���APP����
	/// </summary>
	class OpenGLUIService
	{
	public:
		OpenGLUIService();
		~OpenGLUIService();

		//��ʼ��������
		int initEnvir(int width, int height);
		//��ʼ����
		int runWindow();
		//�رմ���
		int stopWindows();

		//�������ݼ�������
		void SetEngineRes(EngineNS::DataLoadEngine* pDLEngine, ShaderNS::ShaderManager* pShader, RenderNS::RendererEngine* pRender);
	private:
		//��ʼ������
		int initWindows(int width, int height);
		//��ʼ��������
		int initContext();
		//��ʼ������������������Ϣ
		int initOtherConfig();
	private:
		//GL �Ĵ��ھ��
		GLFWwindow* _pWindow;
		//���ݼ�������
		EngineNS::DataLoadEngine* m_pDataLoadEngine;//���ݼ���
		ShaderNS::ShaderManager* m_pShaderMag;		//��ɫ��
		RenderNS::RendererEngine* m_pRenderEngine; //��Ⱦ��
		RenderNS::TextureService* m_pTextureService;
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

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
		int initEnvir(GLFWwindow* glwindow);
		//��ʼ����
		int FlushFrame();
		//������ҵ��ķ���
		int EndOpenGLUIService();

	private:
		//��ʼ��������
		int initContext();
	private:
		//���ݼ�������
		EngineNS::DataLoadEngine* m_pDataLoadEngine;//���ݼ���
		ShaderNS::ShaderManager* m_pShaderMag;		//��ɫ��
		RenderNS::RendererEngine* m_pRenderEngine; //��Ⱦ��
		RenderNS::TextureService* m_pTextureService;//����
	};
}

/*ע��

	��������䣬ת�أ���ʼ���������໯������APP��˽�б���������
*/

#pragma once
#include <string>
/*
������openggl ��صĲ���

*/

namespace ImguiRendererNS
{
	/// <summary>
	/// ö����ɫ��������
	/// </summary>
	enum  EShaderType
	{
		E_VertexShader_Type,
		E_FragmentShader_Type
	};

	class ShaderManageGLPrivate
	{
	public:
		//������ɫ��
		unsigned int ComplieShaderGL(unsigned int type, const std::string& source);
		//���캯��
		ShaderManageGLPrivate();
	private:

	};
}


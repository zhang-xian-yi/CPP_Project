#include "WGLMacroDef.h"
#include <sstream>//�ַ�����
#include "MdlCommon/Src/CMNMacro/LogMacroDef.h"
#include "Logger/Src/ILogger.h"
#include "Glad/glad.h"
#include "GLFW/glfw3.h"

namespace WindowsNS
{
	/// <summary>
	/// ���
	/// </summary>
	void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	/// <summary>
	/// ��ӡ��־�еĴ�����Ϣ
	/// </summary>
	/// <param name="file">const char* ��C++���ú궨������ͣ������ļ���</param>
	/// <param name="line">�ļ���</param>
	/// <param name="func">�ַ���</param>
	/// <returns></returns>
	bool GLLogError(const char* file, int line, const char* func)
	{
		//log ������Ϣ  �����errir �Ǵ����ǣ�
		std::stringstream ss;
		//�����Ǹ�ֵ ��˼�ǽ�����id���Ƹ�error������ �����ж�error����Ϊ0
		//while(0) ������ѭ��������Ϊ�ж��Ƿ񻹴��ڴ�����Ϣ
		while (GLenum error = glGetError())
		{
			ss<< "[OpenGL Error]: (" << error << ")" << "\n�ļ���:" << file
				<< "\n����:" << line << "\n����:" << func << "\n";
			//��ӡ
			MdlCommonNS::LogMsgOSAsync(LoggerNS::ELogLevel::E_Error_LV,ss.str().c_str());
			//�����֧ 
			return false;
		}
		//��ȷ
		return true;
	}
}
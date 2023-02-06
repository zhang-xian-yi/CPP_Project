#include "WGLMacroDef.h"
#include <sstream>//�ַ�����
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Logger/Src/ILogger.h"
#include "MdlCommon/Src/CMNServices/Container/ServiceContainerSingle.h"
#include "MdlCommon/Src/CMNMEnum/ModuelType/EModuleType.h"
#include "MdlCommon/Src/CMNInterface/IMdlService.h"
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
			LogMsgOSAsync(LoggerNS::ELogLevel::E_Error_LV,ss.str().c_str());
			//�����֧ 
			return false;
		}
		//��ȷ
		return true;
	}
	/// <summary>
	/// ����־�д�ӡ�ؼ���Ϣ
	/// </summary>
	/// <param name="msg"></param>
	void LogMsgOSAsync(LoggerNS::ELogLevel logLv,const char* msg)
	{
		auto iLogS = MdlCommonNS::ServiceContainerSingle::GetContainer().GetModuleServiceInterface(MdlCommonNS::EModuleType::E_Logger_Type);
		if (iLogS.has_value())
		{
			auto prunlog = iLogS.value()->ConvertType<LoggerNS::IFileLogger*>();
			prunlog->LogFileMsgAsync(logLv, msg);
			auto pstdoutlog = iLogS.value()->ConvertType<LoggerNS::IStdoutLogger*>();
			pstdoutlog->LogStdoutMsgAsync(logLv, msg);
		}
	}
}
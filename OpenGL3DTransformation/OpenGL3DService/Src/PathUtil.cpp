#include "PathUtil.h"
#include <windows.h>

namespace MdlCommonNS
{
	/// <summary>
	/// ��ȡ��ִ���ļ���·��
	/// </summary>
	/// <returns></returns>
	std::string PathUtil::GetExecutePath()
	{
		char szFilePath[MAX_PATH + 1] = { 0 };
		GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
		(strrchr(szFilePath, '\\'))[0] = 0; // ɾ���ļ�����ֻ���·���ִ�
		//���ض���
		return std::string(szFilePath);
	}
}


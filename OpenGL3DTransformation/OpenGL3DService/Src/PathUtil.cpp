#include "PathUtil.h"
#include <windows.h>

namespace MdlCommonNS
{
	/// <summary>
	/// 获取可执行文件的路径
	/// </summary>
	/// <returns></returns>
	std::string PathUtil::GetExecutePath()
	{
		char szFilePath[MAX_PATH + 1] = { 0 };
		GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
		(strrchr(szFilePath, '\\'))[0] = 0; // 删除文件名，只获得路径字串
		//返回对象
		return std::string(szFilePath);
	}
}


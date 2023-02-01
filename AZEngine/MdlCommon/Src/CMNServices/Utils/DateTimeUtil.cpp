#include "DateTimeUtil.h"
#include <filesystem>
namespace MdlCommonNS
{
	std::string DateTimeUtil::GetDayTime()
	{
		return GetTime("%Y-%m-%d");
	}

	/// <summary>
	/// �ڲ���ȡ�¼���ʽ��ͨ�ú���
	/// </summary>
	/// <param name="pattern"></param>
	/// <returns></returns>
	std::string DateTimeUtil::GetTime(const std::string&& pattern)
	{
		time_t timep;
		time(&timep);
		char tmp[32];
		struct tm CurrT;
		//��ȡ��ǰ�¼�
		localtime_s(&CurrT, &timep);
		//��ʽ��
		strftime(tmp, sizeof(tmp), pattern.c_str(), &CurrT);
		return std::string(tmp);
	}
}


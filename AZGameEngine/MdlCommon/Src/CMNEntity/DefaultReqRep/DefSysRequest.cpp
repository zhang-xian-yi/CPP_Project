#include "DefSysRequest.h"

namespace MdlCommonNS
{
	DefSysRequest::DefSysRequest()
		:m_pData(nullptr)
	{
	}

	//
	DefSysRequest::~DefSysRequest()
	{
		if (m_pData)
		{
			delete m_pData;
			m_pData = nullptr;
		}
	}
	/// <summary>
	/// 设置对应类型的数据
	/// </summary>
	/// <param name="data"></param>
	void DefSysRequest::SetData(std::any& data)
	{
		//赋值,存在拷贝data对象数据，对于性能存在部分影响
		//*m_pData = data;
		//取地址，直接控制对象内存，并在请求销毁时，释放
		m_pData = &data;
	}

	/// <summary>
	/// 获取指定的数据
	/// </summary>
	/// <returns></returns>
	std::any& DefSysRequest::GetData() const
	{
		return *m_pData;
	}
}

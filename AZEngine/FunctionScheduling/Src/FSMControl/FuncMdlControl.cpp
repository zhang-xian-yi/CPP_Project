#include "FuncMdlControl.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//业务容器
namespace FuncScheduleNS
{
	/// <summary>
	/// 构造函数
	/// </summary>
	FuncMdlControl::FuncMdlControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// 析构函数
	/// </summary>
	FuncMdlControl::~FuncMdlControl()
	{

	}

	bool FuncMdlControl::ConstructModule()
	{
		m_bIsUse = true;



		return true;
	}

	bool FuncMdlControl::DestoryModule()
	{


		return true;
	}

	//返回结果
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}
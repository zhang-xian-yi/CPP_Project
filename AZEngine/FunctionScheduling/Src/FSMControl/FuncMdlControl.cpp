#include "FuncMdlControl.h"
#include "CMNServices/Container/ServiceContainerSingle.h"//ҵ������
namespace FuncScheduleNS
{
	/// <summary>
	/// ���캯��
	/// </summary>
	FuncMdlControl::FuncMdlControl()
		:m_bIsUse(false)
	{

	}
	/// <summary>
	/// ��������
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

	//���ؽ��
	bool FuncMdlControl::IsUse() const
	{
		return m_bIsUse;
	}

}
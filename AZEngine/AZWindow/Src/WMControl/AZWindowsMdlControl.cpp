#include "AZWindowsMdlControl.h"
namespace AZWindowsNS
{
	AZWindowsMdlControl::AZWindowsMdlControl()
		:m_bIsUse(false)
	{
	}
	AZWindowsMdlControl::~AZWindowsMdlControl()
	{
	}

	/// <summary>
	/// ����ģ��
	/// </summary>
	/// <returns></returns>
	bool AZWindowsMdlControl::ConstructModule()
	{


		return true;
	}

	/// <summary>
	/// ����ģ��
	/// </summary>
	/// <returns></returns>
	bool AZWindowsMdlControl::DestoryModule()
	{


		return true;
	}

	//��ȡģ��״̬
	bool AZWindowsMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
#include "WindowsMdlControl.h"
namespace WindowsNS
{
	WindowsMdlControl::WindowsMdlControl()
		:m_bIsUse(false)
	{
	}
	WindowsMdlControl::~WindowsMdlControl()
	{
	}

	/// <summary>
	/// ����ģ��
	/// </summary>
	/// <returns></returns>
	bool WindowsMdlControl::ConstructModule()
	{


		return true;
	}

	/// <summary>
	/// ����ģ��
	/// </summary>
	/// <returns></returns>
	bool WindowsMdlControl::DestoryModule()
	{


		return true;
	}

	//��ȡģ��״̬
	bool WindowsMdlControl::IsUse() const
	{
		return m_bIsUse;
	}
}
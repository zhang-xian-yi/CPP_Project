#pragma once

namespace MdlCommonNS
{
	//ǰ������
	enum class EModuleType:unsigned char;
	class IMdlFactory;
}
//
namespace FuncScheduleNS
{
	/// <summary>
	/// ģ����ȵĿ�����ʵ��˽���߼�
	/// </summary>
	class FuncScheduleCtlPrivate
	{
	public:
		//ע������Ц����ImdlService�ӿڵĹ���ģ��
		void InitAndRegisterAllService();
	private:
		//���ݹ������󴴽���ע��ָ��ʵ��
		void InitAndRegisterService(MdlCommonNS::EModuleType type,MdlCommonNS::IMdlFactory* factory);

	};
}



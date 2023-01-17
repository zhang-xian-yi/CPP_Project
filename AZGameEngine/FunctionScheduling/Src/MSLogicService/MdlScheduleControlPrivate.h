#pragma once

namespace MdlCommonNS
{
	//ǰ������
	enum class EModuleType:unsigned char;
	class IMdlFactory;
}
//
namespace MdlScheduleNS
{
	/// <summary>
	/// ģ����ȵĿ�����ʵ��˽���߼�
	/// </summary>
	class MdlScheduleControlPrivate
	{
	public:
		//ע������Ц����ImdlService�ӿڵĹ���ģ��
		void InitAndRegisterAllService();
	private:
		//���ݹ������󴴽���ע��ָ��ʵ��
		void InitAndRegisterService(MdlCommonNS::EModuleType type,MdlCommonNS::IMdlFactory* factory);

	};
}



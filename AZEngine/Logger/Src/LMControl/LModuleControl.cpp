#include "LModuleControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //ʹ�ù�����������ռ�

namespace LoggerNS
{
    LModuleControl::LModuleControl()
        :m_bIsUse(false)
    {

    }
    LModuleControl::~LModuleControl()
    {
    }

    bool LModuleControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = true;
        // TODO: �ڴ˴����� return ���


		return true;
    }

    bool LModuleControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���


		return true;
    }

    //����ģ���Ƿ����
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

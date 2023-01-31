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

    MdlCommonNS::ISysResponse* LModuleControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = true;
        // TODO: �ڴ˴����� return ���
        auto pResult = new MdlCommonNS::DefSysResponse();



        return pResult;
    }

    MdlCommonNS::ISysResponse* LModuleControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���
        auto pResult = new MdlCommonNS::DefSysResponse();

        return pResult;
    }

    //����ģ���Ƿ����
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

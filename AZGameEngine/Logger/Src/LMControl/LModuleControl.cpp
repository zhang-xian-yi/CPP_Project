#include "LModuleControl.h"
#include <LCommon/LoggerGlobal.h>//��ģ���� loggerglobal
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //ʹ�ù�����������ռ�

namespace Log4CppNS
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
        LoggerGlobal* plogGlo = Log4CppNS::LoggerGlobal::GetInstancePointer();
        //plogGlo->SetLogSetting(para);
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

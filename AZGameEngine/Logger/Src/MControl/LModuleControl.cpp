#include "LModuleControl.h"
#include <Common/LoggerGlobal.h>//��ģ���� loggerglobal
#include "Entity/DefSysResponse.h"
#include "Entity/DefSysRequest.h"
namespace Log4CppNS
{
    LModuleControl::LModuleControl()
    {

    }
    LModuleControl::~LModuleControl()
    {
    }
    CommonNS::ISysResponse* LModuleControl::ConstructModule(const CommonNS::ISysRequest& para)
    {
        LoggerGlobal* plogGlo = Log4CppNS::LoggerGlobal::GetInstancePointer();
        //plogGlo->SetLogSetting(para);
        m_bIsUse = true;
        // TODO: �ڴ˴����� return ���
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::RegisterModule(const CommonNS::ISysRequest& para)
    {
        // TODO: �ڴ˴����� return ���
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::DestoryModule(const CommonNS::ISysRequest& para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::UnRegisterModule(const CommonNS::ISysRequest& para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���
        return new CommonNS::DefSysResponse();
    }

    //����ģ���Ƿ����
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

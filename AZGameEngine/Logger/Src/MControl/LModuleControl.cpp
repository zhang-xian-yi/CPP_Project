#include "LModuleControl.h"
#include <Common/LoggerGlobal.h>//本模块内 loggerglobal
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
        // TODO: 在此处插入 return 语句
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::RegisterModule(const CommonNS::ISysRequest& para)
    {
        // TODO: 在此处插入 return 语句
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::DestoryModule(const CommonNS::ISysRequest& para)
    {
        m_bIsUse = false;
        // TODO: 在此处插入 return 语句
        return new CommonNS::DefSysResponse();
    }
    CommonNS::ISysResponse* LModuleControl::UnRegisterModule(const CommonNS::ISysRequest& para)
    {
        m_bIsUse = false;
        // TODO: 在此处插入 return 语句
        return new CommonNS::DefSysResponse();
    }

    //返回模块是否可用
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

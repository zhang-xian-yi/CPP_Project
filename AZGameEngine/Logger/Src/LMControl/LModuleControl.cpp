#include "LModuleControl.h"
#include <LCommon/LoggerGlobal.h>//本模块内 loggerglobal
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

using namespace MdlCommonNS; //使用公共库的命名空间

namespace Log4CppNS
{
    LModuleControl::LModuleControl()
        :m_bIsUse(false)
    {

    }
    LModuleControl::~LModuleControl()
    {
    }

    std::unique_ptr<MdlCommonNS::ISysResponse> LModuleControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        LoggerGlobal* plogGlo = Log4CppNS::LoggerGlobal::GetInstancePointer();
        //plogGlo->SetLogSetting(para);
        m_bIsUse = true;
        // TODO: 在此处插入 return 语句
        auto pResult = new MdlCommonNS::DefSysResponse();



        return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
    }

    std::unique_ptr<MdlCommonNS::ISysResponse> LModuleControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = false;
        // TODO: 在此处插入 return 语句
        auto pResult = new MdlCommonNS::DefSysResponse();

        return std::unique_ptr<MdlCommonNS::ISysResponse>(pResult);
    }

    //返回模块是否可用
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

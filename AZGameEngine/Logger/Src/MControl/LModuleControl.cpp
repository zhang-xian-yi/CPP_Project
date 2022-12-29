#include "LModuleControl.h"
#include "Common/MStatus/LMStatus.h"
#include "Common/MBean/LogSettingPara.h"
#include "Common/LoggerGlobal.h"
namespace Log4CppNS
{
    LMStatus LModuleControl::InitModule(LogSettingPara& para)
    {
        LoggerGlobal* plogGlo =  Log4CppNS::LoggerGlobal::GetInstancePointer();
        plogGlo->SetLogSetting(para);
        m_bIsInit = true;
        m_bIsUse = true;
        return LMStatus::E_ModuleInit_Succ;
    }

    LMStatus LModuleControl::UpdateSetting(LogSettingPara& para)
    {
        //重新初始化module
        return InitModule(para);
    }

    LMStatus LModuleControl::StopModule()
    {
        m_bIsInit = false;
        m_bIsUse = false;
        return LMStatus::E_ModuleNotUse;
    }
    /// <summary>
    /// 获取模块是否可用
    /// </summary>
    /// <returns></returns>
    bool LModuleControl::IsUse()
    {
        if (m_bIsInit && m_bIsUse)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

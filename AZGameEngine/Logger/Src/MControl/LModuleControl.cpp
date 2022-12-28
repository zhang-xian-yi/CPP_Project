#include "LModuleControl.h"
#include "Common/MStatus/LMStatus.h"
#include "Common/MBean/LogSettingPara.h"
namespace Log4CppNS
{
    LMStatus LModuleControl::InitModule(LogSettingPara& para)
    {
        return LMStatus::E_ModuleInit_Succ;
    }

    LMStatus LModuleControl::StopModule()
    {
        return LMStatus::E_ModuleNotUse;
    }
}

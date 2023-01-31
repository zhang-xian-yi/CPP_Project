#include "LModuleControl.h"
#include "LLogicService/LoggerManager.h"//日志管理工具

using namespace MdlCommonNS; //使用公共库的命名空间

namespace LoggerNS
{
    LModuleControl::LModuleControl()
        :m_bIsUse(false)
    {

    }
    LModuleControl::~LModuleControl()
    {
    }

    bool LModuleControl::ConstructModule()
    {
        m_bIsUse = true;
        // TODO: 在此处插入 return 语句
        LoggerManager::GetInstance(); //初始化日志管理

		return true;
    }

    bool LModuleControl::DestoryModule()
    {
        m_bIsUse = false;
        // TODO: 在此处插入 return 语句


		return true;
    }

    //返回模块是否可用
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

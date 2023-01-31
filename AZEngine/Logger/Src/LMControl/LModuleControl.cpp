#include "LModuleControl.h"
#include "CMNEntity/DefaultReqRep/DefSysResponse.h"
#include "CMNEntity/DefaultReqRep/DefSysRequest.h"

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

    bool LModuleControl::ConstructModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
    {
        m_bIsUse = true;
        // TODO: 在此处插入 return 语句


		return true;
    }

    bool LModuleControl::DestoryModule(const std::unique_ptr<MdlCommonNS::ISysRequest> para)
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

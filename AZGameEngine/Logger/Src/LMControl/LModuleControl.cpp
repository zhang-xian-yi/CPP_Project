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

    ISysResponse* LModuleControl::ConstructModule(const ISysRequest* para)
    {
        LoggerGlobal* plogGlo = Log4CppNS::LoggerGlobal::GetInstancePointer();
        //plogGlo->SetLogSetting(para);
        m_bIsUse = true;
        // TODO: �ڴ˴����� return ���
        return new DefSysResponse();
    }
    ISysResponse* LModuleControl::RegisterModule(const ISysRequest* para)
    {
        // TODO: �ڴ˴����� return ���
        return new DefSysResponse();
    }
    ISysResponse* LModuleControl::DestoryModule(const ISysRequest* para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���
        return new DefSysResponse();
    }
    ISysResponse* LModuleControl::UnRegisterModule(const ISysRequest* para)
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���
        return new DefSysResponse();
    }

    //����ģ���Ƿ����
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

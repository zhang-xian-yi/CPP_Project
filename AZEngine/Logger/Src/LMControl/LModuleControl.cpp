#include "LModuleControl.h"
#include "LLogicService/LoggerManager.h"//��־������

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

    bool LModuleControl::ConstructModule()
    {
        m_bIsUse = true;
        // TODO: �ڴ˴����� return ���
        LoggerManager::GetInstance(); //��ʼ����־����

		return true;
    }

    bool LModuleControl::DestoryModule()
    {
        m_bIsUse = false;
        // TODO: �ڴ˴����� return ���


		return true;
    }

    //����ģ���Ƿ����
    bool LModuleControl::IsUse() const
    {
        return m_bIsUse;
    }
}

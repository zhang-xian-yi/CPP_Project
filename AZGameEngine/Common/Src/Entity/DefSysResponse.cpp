#include "DefSysResponse.h"

namespace CommonNS
{
    DefSysResponse::DefSysResponse()
    {
    }
    DefSysResponse::~DefSysResponse()
    {
    }
    bool DefSysResponse::GetIsSuccess() const
    {
        return m_isSucc;
    }

    const std::string& DefSysResponse::GetMessage() const
    {
        // TODO: �ڴ˴����� return ���
        return m_message;
    }

    void DefSysResponse::SetIsSuccess(const bool flag)
    {
        m_isSucc = flag;
    }

    void DefSysResponse::SetMessage(const std::string& message)
    {
        m_message = message;
    }

    bool DefSysResponse::IsValid() const
    {
        return true;
    }
}

#include "DefSysResponse.h"
#include <memory>

namespace CommonNS
{
    //˽���߼� ʵ�־���ҵ���߼�
    class DefSysResponsePrivate
    {
    public:
        DefSysResponsePrivate();
        ~DefSysResponsePrivate();
    public:
        bool GetIsSuccess()const;
        const std::string& GetMessage()const;
        //��������
        void SetIsSuccess(const bool falg);
        void SetMessage(const std::string& message);
        //�Ϸ����
        virtual bool IsValid() const;
    private:
        bool m_isSucc;
        //����Ϊָ���Ǳ������ʱ��4251���棬�˴�ʹ��std::string ���Ͷ���ָ�����Ҫ������Ӧ��stringģ����
        //template class __declspec(dllexport) std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
        std::unique_ptr<std::string> m_pMessage;
    };



    DefSysResponsePrivate::DefSysResponsePrivate()
        :m_pMessage(new std::string()),m_isSucc(false)
    {

    }
    DefSysResponsePrivate::~DefSysResponsePrivate()
    {
        //��Ҫʹ��realse�������÷���ֻ���ͷ�����ָ����Ϊ0��������ά����ָ�뻹����ʹ��
        //��������ָ��ָ��
        m_pMessage.reset();
    }
    bool DefSysResponsePrivate::GetIsSuccess() const
    {
        return m_isSucc;
    }

    const std::string& DefSysResponsePrivate::GetMessage() const
    {
        // TODO: �ڴ˴����� return ���
        return *m_pMessage;
    }

    void DefSysResponsePrivate::SetIsSuccess(const bool flag)
    {
        m_isSucc = flag;
    }

    void DefSysResponsePrivate::SetMessage(const std::string& message)
    {
        *m_pMessage = message;
    }

    bool DefSysResponsePrivate::IsValid() const
    {
        return true;
    }
}



namespace CommonNS
{
    DefSysResponse::DefSysResponse()
        :m_pService(new DefSysResponsePrivate())
    {

    }
    DefSysResponse::~DefSysResponse()
    {
        if (m_pService != nullptr)
        {
            delete m_pService;
            m_pService = nullptr;
        }
    }
    bool DefSysResponse::GetIsSuccess() const
    {
        return m_pService->GetIsSuccess();
    }

    const std::string& DefSysResponse::GetMessage() const
    {
        // TODO: �ڴ˴����� return ���
        return m_pService->GetMessage();
    }

    void DefSysResponse::SetIsSuccess(const bool flag)
    {
        m_pService->SetIsSuccess(flag);
    }

    void DefSysResponse::SetMessage(const std::string& message)
    {
        m_pService->SetMessage(message);
    }

    bool DefSysResponse::IsValid() const
    {
        return m_pService->IsValid();
    }
}

#include "DefSysResponse.h"
#include <memory>

namespace CommonNS
{
    //私有逻辑 实现具体业务逻辑
    class DefSysResponsePrivate
    {
    public:
        DefSysResponsePrivate();
        ~DefSysResponsePrivate();
    public:
        bool GetIsSuccess()const;
        const std::string& GetMessage()const;
        //数据设置
        void SetIsSuccess(const bool falg);
        void SetMessage(const std::string& message);
        //合法检查
        virtual bool IsValid() const;
    private:
        bool m_isSucc;
        //定义为指针是避免编译时报4251警告，此处使用std::string 类型而非指针就需要导出对应的string模板类
        //template class __declspec(dllexport) std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
        std::unique_ptr<std::string> m_pMessage;
    };



    DefSysResponsePrivate::DefSysResponsePrivate()
        :m_pMessage(new std::string()),m_isSucc(false)
    {

    }
    DefSysResponsePrivate::~DefSysResponsePrivate()
    {
        //不要使用realse方法，该方法只是释放智能指针置为0，但是其维护的指针还可以使用
        //主动销毁指向指针
        m_pMessage.reset();
    }
    bool DefSysResponsePrivate::GetIsSuccess() const
    {
        return m_isSucc;
    }

    const std::string& DefSysResponsePrivate::GetMessage() const
    {
        // TODO: 在此处插入 return 语句
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
        // TODO: 在此处插入 return 语句
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

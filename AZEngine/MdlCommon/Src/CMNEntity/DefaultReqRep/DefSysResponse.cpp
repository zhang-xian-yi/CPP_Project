#include "DefSysResponse.h"
#include <memory>

namespace MdlCommonNS
{
    DefSysResponse::DefSysResponse()
        :m_pData(nullptr)
    {

    }
    DefSysResponse::DefSysResponse(std::any& data)
        :m_pData(&data)
    {
    }

    DefSysResponse::~DefSysResponse()
    {
        if (m_pData && m_pData->has_value())
        {
            //delete m_pData;
            m_pData = nullptr;//防止多次释放
        }
    }
    /// <summary>
    /// 设置数据
    /// </summary>
    /// <param name="data"></param>
    void DefSysResponse::SetData(std::any& data)
    {
        //赋值,存在拷贝data对象数据，对于性能存在部分影响
        //*m_pData = data;
        //取地址，直接控制对象内存，并在请求销毁时，释放
        m_pData = &data;
    }

    /// <summary>
    /// 获取数据
    /// </summary>
    /// <returns></returns>
    std::any& DefSysResponse::GetData() const
    {
        // TODO: 在此处插入 return 语句
        return *m_pData;
    }

}

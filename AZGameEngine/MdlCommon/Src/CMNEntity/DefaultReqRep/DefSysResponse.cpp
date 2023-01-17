#include "DefSysResponse.h"
#include <memory>

namespace MdlCommonNS
{
    DefSysResponse::DefSysResponse()
        :m_pData(nullptr)
    {

    }
    DefSysResponse::~DefSysResponse()
    {
        if (m_pData)
        {
            delete m_pData;
            m_pData = nullptr;
        }
    }
    /// <summary>
    /// 设置数据
    /// </summary>
    /// <param name="data"></param>
    void DefSysResponse::SetData(Any& data)
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
    Any& DefSysResponse::GetData() const
    {
        // TODO: 在此处插入 return 语句
        return *m_pData;
    }

}

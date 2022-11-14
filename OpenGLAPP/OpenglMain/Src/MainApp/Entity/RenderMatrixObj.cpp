#include "RenderMatrixObj.h"

EntityNS::RenderObj::RenderObj(RenderMatrixPara* para)
    :m_pRMPara(para)
{

}

EntityNS::RenderObj::~RenderObj()
{


}


glm::mat4 EntityNS::RenderObj::GetProjectMatrix() const
{
    //不为空
    if (m_pRMPara != nullptr)
    {
        //初始化两个对象
        return m_pRMPara->projectMatrix;
    }
    return glm::mat4();
}

glm::mat4 EntityNS::RenderObj::GetViewMatrix() const
{
    //不为空
    if (m_pRMPara != nullptr)
    {
        //初始化两个对象
        return m_pRMPara->viewMatrix;
    }
    return glm::mat4();
}

glm::vec3* EntityNS::RenderObj::GetModelAMatrix() const
{
    //不为空
    if (m_pRMPara != nullptr)
    {
        //初始化两个对象
        return &m_pRMPara->modelAVec3;
    }
    return nullptr;
}

glm::vec3* EntityNS::RenderObj::GetModelBMatrix() const
{
    //不为空
    if (m_pRMPara != nullptr)
    {
        //初始化两个对象
        return &m_pRMPara->modelBVec3;
    }
    return nullptr;
}


/*
glm::vec3& EntityNS::RenderObj::GetModelMatrix(std::string key) const
{
    //不为空
    if (m_pRMPara != nullptr && !m_pRMPara->modelVec3Map.empty())
    {
        //判定集合map是否存在
        if (m_pRMPara->modelVec3Map.find(key) != m_pRMPara->modelVec3Map.end())
        {
            //找到搞对象
            return m_pRMPara->modelVec3Map[key];
        }
    }
    //返回默认的临时对象
    return m_pRMPara->modelVec3Map["ObjDef"];
}
*/
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
    //��Ϊ��
    if (m_pRMPara != nullptr)
    {
        //��ʼ����������
        return m_pRMPara->projectMatrix;
    }
    return glm::mat4();
}

glm::mat4 EntityNS::RenderObj::GetViewMatrix() const
{
    //��Ϊ��
    if (m_pRMPara != nullptr)
    {
        //��ʼ����������
        return m_pRMPara->viewMatrix;
    }
    return glm::mat4();
}

glm::vec3* EntityNS::RenderObj::GetModelAMatrix() const
{
    //��Ϊ��
    if (m_pRMPara != nullptr)
    {
        //��ʼ����������
        return &m_pRMPara->modelAVec3;
    }
    return nullptr;
}

glm::vec3* EntityNS::RenderObj::GetModelBMatrix() const
{
    //��Ϊ��
    if (m_pRMPara != nullptr)
    {
        //��ʼ����������
        return &m_pRMPara->modelBVec3;
    }
    return nullptr;
}


/*
glm::vec3& EntityNS::RenderObj::GetModelMatrix(std::string key) const
{
    //��Ϊ��
    if (m_pRMPara != nullptr && !m_pRMPara->modelVec3Map.empty())
    {
        //�ж�����map�Ƿ����
        if (m_pRMPara->modelVec3Map.find(key) != m_pRMPara->modelVec3Map.end())
        {
            //�ҵ������
            return m_pRMPara->modelVec3Map[key];
        }
    }
    //����Ĭ�ϵ���ʱ����
    return m_pRMPara->modelVec3Map["ObjDef"];
}
*/
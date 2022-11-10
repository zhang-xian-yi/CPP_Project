#include "RenderMatrixObj.h"

EntityNS::RenderObj::RenderObj()
    :m_pRMPara(nullptr)
{
}

EntityNS::RenderObj::~RenderObj()
{


}

EntityNS::RenderMatrixPara* EntityNS::RenderObj::GetMatrixPara() const
{
    return m_pRMPara;
}

void EntityNS::RenderObj::SetMatrixPara(EntityNS::RenderMatrixPara* para)
{
    m_pRMPara = para;
}

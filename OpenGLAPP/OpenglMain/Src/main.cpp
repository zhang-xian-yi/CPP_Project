#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //����һ��APP
    EnvirmentNS::Application app;
    //��������
    float positionArray[8] = {
        -0.5f,-0.5f,
        0.5f,-0.5f,
        0.5f,0.5f,
        -0.5f,0.5f, };

    //����������
    unsigned int indices[6] = {
        0,1,2,
        2,3,0,
    };

    //��ʼ������
    app.initEnvir();

    ShaderNS::ShaderManager ShaderMag;//��ɫ��
    ShaderMag.initShader();
    //����һ������װ������
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 8 * sizeof(float));
    dataLoadEngine.SetIndexData(indices, 6);
    //��ʼ�����ݻ���
    dataLoadEngine.InitDataEnvir();
    RenderNS::RendererEngine RenderEngine;//��Ⱦ��
    
    app.SetEngineRes(&dataLoadEngine,&ShaderMag,&RenderEngine);
    //��������
    app.runWindow();
    //ֹͣ����
    app.stopWindows();
    return 0;
}


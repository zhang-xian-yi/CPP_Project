#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
#include "Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //����һ��APP
    EnvirmentNS::Application app;
    //��������
    float positionArray[] = {
        -0.5f,-0.5f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
        0.5f,-0.5f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
        0.5f,0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.0f,1.0f
    };

    //����������
    unsigned int indices[6] = {
        0,1,2,
        2,3,0,
    };

    //��ʼ������
    app.initEnvir();

    //��������
    RenderNS::TextureService textureService;
    textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.Bind(0);//Ĭ��Ϊ0
    

    ShaderNS::ShaderManager ShaderMag;//��ɫ��
    ShaderMag.initShader();
    //�����0 �����������۵�0 ʱһ�����壬������ɫ��Ҳ��Ҫͳһ������ֵ
    //u_Texture Ϊ��ɫ����GLSL�еı���
    ShaderMag.SetUniform1f("u_Texture", 0);
    //����һ������װ������
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 4*4 * sizeof(float));
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


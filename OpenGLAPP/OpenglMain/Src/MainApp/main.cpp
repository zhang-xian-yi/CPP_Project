#include "Envirment/Application.h"
#include "Envirment/ImGuiService.h"
#include "Envirment/OpenGLUIService.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
#include "Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int testOpenglAPP(int argc, char* argv[])
{
    //����һ��APP
    EnvirmentNS::OpenGLUIService app;
    //��������
    float positionArray[] = {
        -100.0f,-100.0f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
        100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
        100.0f,100.0f,1.0f,1.0f,
        -100.0f,100.0f,0.0f,1.0f
    };

    //����������
    unsigned int indices[] = {
        0,1,2,
        2,3,0,
    };

    //��ʼ������
    app.initEnvir(720, 480);


    ShaderNS::ShaderManager ShaderMag;//��ɫ��
    ShaderMag.initShader();
    ShaderMag.Bind();//������ʹ��gluserprogram �ſ��԰�uniform��������ñ����������

    //��������
    RenderNS::TextureService textureService;
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.InitFileTexture("Resource/Textures/flower.jpeg");
    textureService.Bind(0);//Ĭ��Ϊ0
    ShaderMag.SetUniform1f("u_Texture", 0);

    //����һ������װ������
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 4 * 4 * sizeof(float));
    dataLoadEngine.SetIndexData(indices, 6);
    //��ʼ�����ݻ���
    dataLoadEngine.InitDataEnvir();
    RenderNS::RendererEngine RenderEngine;//��Ⱦ��

    app.SetEngineRes(&dataLoadEngine, &ShaderMag, &RenderEngine);

    int ret = 0;
    while (!ret)
    {
        //��������
        ret = app.runWindow();
    }

    //��ֹͣӦ��֮ǰ ɾ���������������������
    //ֹͣ����
    app.stopWindows();
    return 0;
}

int testImGUIAPP(int argc, char* argv[])
{
    EnvirmentNS::ImGuiService imGUI;

    imGUI.initEnvir(720, 480);

    int ret = 0;
    while (!ret)
    {
        ret = imGUI.runWindow();

    }

    imGUI.stopWindows();

    return 0;
}


int main(int argc, char* argv[])
{

    return testOpenglAPP(argc,argv);
}


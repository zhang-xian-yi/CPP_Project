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
    //定义一个APP
    EnvirmentNS::OpenGLUIService app;
    //顶点数据
    float positionArray[] = {
        -100.0f,-100.0f,0.0f,0.0f,//前两个数为顶点，后两个数为纹理坐标
        100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
        100.0f,100.0f,1.0f,1.0f,
        -100.0f,100.0f,0.0f,1.0f
    };

    //索引缓冲区
    unsigned int indices[] = {
        0,1,2,
        2,3,0,
    };

    //初始化环境
    app.initEnvir(720, 480);


    ShaderNS::ShaderManager ShaderMag;//着色器
    ShaderMag.initShader();
    ShaderMag.Bind();//必须先使用gluserprogram 才可以绑定uniform变量否则该变量不会存在

    //加载纹理
    RenderNS::TextureService textureService;
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.InitFileTexture("Resource/Textures/flower.jpeg");
    textureService.Bind(0);//默认为0
    ShaderMag.SetUniform1f("u_Texture", 0);

    //定义一个数据装载引擎
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 4 * 4 * sizeof(float));
    dataLoadEngine.SetIndexData(indices, 6);
    //初始化数据环境
    dataLoadEngine.InitDataEnvir();
    RenderNS::RendererEngine RenderEngine;//渲染器

    app.SetEngineRes(&dataLoadEngine, &ShaderMag, &RenderEngine);

    int ret = 0;
    while (!ret)
    {
        //启动窗口
        ret = app.runWindow();
    }

    //在停止应用之前 删除顶点数组和索引缓冲区
    //停止窗口
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


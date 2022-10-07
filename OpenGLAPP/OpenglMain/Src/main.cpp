#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //定义一个APP
    EnvirmentNS::Application app;
    //顶点数据
    float positionArray[8] = {
        -0.5f,-0.5f,
        0.5f,-0.5f,
        0.5f,0.5f,
        -0.5f,0.5f, };

    //索引缓冲区
    unsigned int indices[6] = {
        0,1,2,
        2,3,0,
    };

    //初始哈环境
    app.initEnvir();

    ShaderNS::ShaderManager ShaderMag;//着色器
    ShaderMag.initShader();
    //定义一个数据装载引擎
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 8 * sizeof(float));
    dataLoadEngine.SetIndexData(indices, 6);
    //初始化数据环境
    dataLoadEngine.InitDataEnvir();
    RenderNS::RendererEngine RenderEngine;//渲染器
    
    app.SetEngineRes(&dataLoadEngine,&ShaderMag,&RenderEngine);
    //启动窗口
    app.runWindow();
    //停止窗口
    app.stopWindows();
    return 0;
}


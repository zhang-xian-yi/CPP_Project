#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
#include "Shader/ShaderManager.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //定义一个APP
    EnvirmentNS::Application app;
    //顶点数据
    float positionArray[] = {
        -0.5f,-0.5f,0.0f,0.0f,//前两个数为顶点，后两个数为纹理坐标
        0.5f,-0.5f,1.0f,0.0f,//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
        0.5f,0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.0f,1.0f
    };

    //索引缓冲区
    unsigned int indices[6] = {
        0,1,2,
        2,3,0,
    };

    //初始哈环境
    app.initEnvir();

    //加载纹理
    RenderNS::TextureService textureService;
    textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.Bind(0);//默认为0
    

    ShaderNS::ShaderManager ShaderMag;//着色器
    ShaderMag.initShader();
    //这里的0 和上面纹理插槽的0 时一个含义，描述着色器也需要统一变量赋值
    //u_Texture 为着色器的GLSL中的变量
    ShaderMag.SetUniform1f("u_Texture", 0);
    //定义一个数据装载引擎
    EngineNS::DataLoadEngine dataLoadEngine;
    dataLoadEngine.SetVertexData(positionArray, 4*4 * sizeof(float));
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


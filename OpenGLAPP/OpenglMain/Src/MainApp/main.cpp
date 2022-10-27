#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
#include "Shader/ShaderManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// 投影矩阵
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //定义一个APP
    EnvirmentNS::Application app;
    //顶点数据
    float positionArray[] =  {
        -0.5f,-0.5f,0.0f,0.0f,//前两个数为顶点，后两个数为纹理坐标
        0.5f,-0.5f,1.0f,0.0f,//0.0f 0.0f 纹理坐标表示左下角，1.0f,1.0f 表示右上角
        0.5f,0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.0f,1.0f
    };

    //索引缓冲区
    unsigned int indices[] =  {
        0,1,2,
        2,3,0,
    };

    //初始化环境
    app.initEnvir();

    //建立一个投影矩阵
    //从左右上下来看分别时-2，2-1.5，1.5  描述从左到右时 -2 + 2 四个单位宽度
    //从上到下时 1.5+1.5 3各单位的高度的区域
    //ortho产生一个正交矩阵
    glm::mat4 projx = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f,-1.0f,1.0f);
    //用这个矩阵乘以顶点矩阵
   
    ShaderNS::ShaderManager ShaderMag;//着色器
    ShaderMag.initShader();
    ShaderMag.Bind();//必须先使用gluserprogram 才可以绑定uniform变量否则该变量不会存在
    //这里的0 和上面纹理插槽的0 时一个含义，描述着色器也需要统一变量赋值
    //u_Texture 为着色器的GLSL中的变量
    ShaderMag.SetUniformMatrix4f("u_MVP", projx);

    //加载纹理
    RenderNS::TextureService textureService;
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.InitFileTexture("Resource/Textures/flower.jpeg");
    textureService.Bind(0);//默认为0
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

    //在停止应用之前 删除顶点数组和索引缓冲区
    //停止窗口
    app.stopWindows();
    return 0;
}


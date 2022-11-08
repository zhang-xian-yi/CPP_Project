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

    //初始化环境
    app.initEnvir(720, 480);

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

int testAPP(int argc, char* argv[])
{
    EnvirmentNS::Application app;

    app.InitAPPEnvir(720, 480);

    int ret = 0;
    while (!ret)
    {
        //渲染窗口
        ret = app.runWindow();
    }

    app.stopWindows();
    return 0;
}


int main(int argc, char* argv[])
{
     
    return testOpenglAPP(argc,argv);
}


#include "Envirment/Application.h"
#include "Engines/DataLoadEngine.h"
#include "Render/RendererEngine.h"
#include "Render/TextureService.h"
#include "Shader/ShaderManager.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// ͶӰ����
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
    //����һ��APP
    EnvirmentNS::Application app;
    //��������
    float positionArray[] =  {
        -0.5f,-0.5f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
        0.5f,-0.5f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
        0.5f,0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.0f,1.0f
    };

    //����������
    unsigned int indices[] =  {
        0,1,2,
        2,3,0,
    };

    //��ʼ������
    app.initEnvir();

    //����һ��ͶӰ����
    //���������������ֱ�ʱ-2��2-1.5��1.5  ����������ʱ -2 + 2 �ĸ���λ���
    //���ϵ���ʱ 1.5+1.5 3����λ�ĸ߶ȵ�����
    //ortho����һ����������
    glm::mat4 projx = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f,-1.0f,1.0f);
    //�����������Զ������
   
    ShaderNS::ShaderManager ShaderMag;//��ɫ��
    ShaderMag.initShader();
    ShaderMag.Bind();//������ʹ��gluserprogram �ſ��԰�uniform��������ñ����������
    //�����0 �����������۵�0 ʱһ�����壬������ɫ��Ҳ��Ҫͳһ������ֵ
    //u_Texture Ϊ��ɫ����GLSL�еı���
    ShaderMag.SetUniformMatrix4f("u_MVP", projx);

    //��������
    RenderNS::TextureService textureService;
    //textureService.InitFileTexture("Resource/Textures/sky.jpeg");
    textureService.InitFileTexture("Resource/Textures/flower.jpeg");
    textureService.Bind(0);//Ĭ��Ϊ0
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

    //��ֹͣӦ��֮ǰ ɾ���������������������
    //ֹͣ����
    app.stopWindows();
    return 0;
}


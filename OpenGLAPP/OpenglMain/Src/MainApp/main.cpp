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
        -100.0f,-100.0f,0.0f,0.0f,//ǰ������Ϊ���㣬��������Ϊ��������
        100.0f,-100.0f,1.0f,0.0f,//0.0f 0.0f ���������ʾ���½ǣ�1.0f,1.0f ��ʾ���Ͻ�
        100.0f,100.0f,1.0f,1.0f,
        -100.0f,100.0f,0.0f,1.0f
    };

    //����������
    unsigned int indices[] =  {
        0,1,2,
        2,3,0,
    };

    //��ʼ������
    app.initEnvir(720, 480);
    //����һ��ͶӰ����,ortho����һ����������
    //���������������ֱ�ʱ-2��2-1.5��1.5  ����������ʱ -2 + 2 �ĸ���λ���
    //���ϵ���ʱ 1.5+1.5 3����λ�ĸ߶ȵ�����
    glm::mat4 projx = glm::ortho(-360.0f, 360.0f, -240.0f, 240.0f,-1.0f,1.0f);
    //ģ����ͼ����������� ��ζ�߶�������
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100.0f,0.0f,0.0f));
    //ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 100, 0));

    ShaderNS::ShaderManager ShaderMag;//��ɫ��
    ShaderMag.initShader();
    ShaderMag.Bind();//������ʹ��gluserprogram �ſ��԰�uniform��������ñ����������
    //�����0 �����������۵�0 ʱһ�����壬������ɫ��Ҳ��Ҫͳһ������ֵ
    //u_Texture Ϊ��ɫ����GLSL�еı���
    ShaderMag.SetUniformMatrix4f("u_MVP", projx*view*model);

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


#version 330 core 

//�˴������������Ƕ��������У���layout push<float> �����������
//�ĸ�folat���֣� ǰ����������Ϊ�������꣬������������Ϊ��������
layout(location = 0) in vec4 postion;//��������
layout(location = 1) in vec2 texcoord;//��������

//���������������Ƭ����ɫ����
out vec2 v_Texcoord;

void main()
{
    gl_Position = postion;
    //��ֵ����������������
    v_Texcoord = texcoord;
};
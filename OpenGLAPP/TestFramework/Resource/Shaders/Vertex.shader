#version 330 core 

//�˴������������Ƕ��������У���layout push<float> �����������
layout(location = 0) in vec4 postion;//��������

void main()
{
    //������������Ⱦ��ָ��λ��
    gl_Position =  postion;
};
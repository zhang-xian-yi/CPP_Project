#version 330 core 

//�˴������������Ƕ��������У���layout push<float> �����������
//�� ���ֹ����е� glEnableVertexAttribArray ����������
layout(location = 0) in vec4 a_postion;//��������
layout(location = 1) in vec4 a_color;//������ɫ

//��Ƭ����ɫ������Ķ�����ɫ��Ϣ
out vec4 v_OColor;

void main()
{
    v_OColor = a_color;//
    //������������Ⱦ��ָ��λ��
    gl_Position =  a_postion;
};
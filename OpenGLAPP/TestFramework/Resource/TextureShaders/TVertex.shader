#version 330 core 

//�˴������������Ƕ��������У���layout push<float> �����������
//�ĸ�folat���֣� ǰ����������Ϊ�������꣬������������Ϊ��������
layout(location = 0) in vec4 postion;//��������
layout(location = 1) in vec2 texcoord;//��������

//���������������Ƭ����ɫ����
out vec2 v_Texcoord;

//����ȫ��ͳһ������������任ֵ����/ ͶӰ����
uniform mat4 u_MVP;

void main()
{
    //ͶӰ���� �Ͷ��������ˣ��������ƶ���ָ��������
    //����ʹ������ͶӰ�ķ�ʽ��֪��Ϊʲô������ʾ�����޷����
    gl_Position = u_MVP * postion;
    //��ֵ����������������
    v_Texcoord = texcoord;
};
#version 330 core 

//�˴������������Ƕ��������У���layout push<float> �����������
//�� ���ֹ����е� glEnableVertexAttribArray ����������
layout(location = 0) in vec4 a_postion;//��������
layout(location = 1) in vec4 a_color;//������ɫ
layout(location = 2) in vec2 a_textureCoord;//������ɫ
layout(location = 3) in float a_texSoltIndex;//������ɫ
//��Ƭ����ɫ������Ķ�����ɫ��Ϣ
out vec2 v_TextureCoord;
out float v_TexSoltIndex;
void main()
{
    v_TexSoltIndex = a_texSoltIndex;
    v_TextureCoord = a_textureCoord;
    //������������Ⱦ��ָ��λ��
    gl_Position =  a_postion;
};
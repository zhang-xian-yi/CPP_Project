#version 330 core 

layout(location = 0) out vec4 color;

in vec4 v_OColor;//���ܴӶ�����ɫ�����������ɫ��Ϣ out / in ���ֱ���һ��

void main()
{
	//�������ص���ɫ
	color = v_OColor;
};
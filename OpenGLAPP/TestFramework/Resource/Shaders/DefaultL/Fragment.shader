#version 330 core 

layout(location = 0) out vec4 color;

//u_ ��ͷ��������ͳһ����
uniform vec4 u_Color;

void main()
{
	//�������ص���ɫ
	color = u_Color;
};
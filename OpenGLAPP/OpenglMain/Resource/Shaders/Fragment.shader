#version 330 core 

layout(location = 0) out vec4 color;

//u_ ��ͷ��������ͳһ����
uniform vec4 u_Color;

void main()
{
	//�������ص���ɫ
	//color = vec4(0.5,0.0,0.0,0.1);
	//����ͼ�λ�����ÿһ�����ص�ÿ��Ƭ�ε�ɫ�ʶ��� u_Color
	color = u_Color;
};
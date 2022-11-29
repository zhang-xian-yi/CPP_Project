#version 330 core 

layout(location = 0) out vec4 color;

//���ܶ�����ɫ���������������
in vec2 v_Texcoord;

uniform sampler2D u_Texture;

void main()
{
	//�������������ص�,����������в���
	vec4 texColor = texture(u_Texture,v_Texcoord);
	//����ͼ�λ�����ÿһ�����ص�ÿ��Ƭ�ε�ɫ�ʶ��� u_Color
	color =  texColor ;
};
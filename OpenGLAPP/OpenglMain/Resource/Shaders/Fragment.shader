#version 330 core 

layout(location = 0) out vec4 color;

//���ܶ�����ɫ���������������
in vec2 v_Texcoord;

//u_ ��ͷ��������ͳһ����
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	//�������������ص�
	vec4 texColor = texture(u_Texture,v_Texcoord);
	//�������ص���ɫ
	//color = u_Color;
	//����ͼ�λ�����ÿһ�����ص�ÿ��Ƭ�ε�ɫ�ʶ��� u_Color
	color = u_Color * texColor;
};
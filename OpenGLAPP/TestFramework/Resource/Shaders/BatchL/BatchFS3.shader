#version 330 core 

layout(location = 0) out vec4 color;

in vec4 v_Color;//���ܴӶ�����ɫ�����������ɫ��Ϣ out / in ���ֱ���һ��
in vec2 v_TextureCoord;
in float v_TexSoltIndex;

uniform sampler2D u_Textures[2];//uniform �������������ۺ�����

void main()
{
	int texInx = int(v_TexSoltIndex);
	color = texture(u_Textures[texInx],v_TextureCoord);
	//�������ص���ɫ
	//color = vec4(v_OTextureCoord,0.0,1.0);
};
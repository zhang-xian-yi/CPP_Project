#version 330 core 

layout(location = 0) out vec4 color;

in vec4 v_Color;//接受从顶点着色器中输入的颜色信息 out / in 名字必须一致
in vec2 v_TextureCoord;
in float v_TexSoltIndex;

uniform sampler2D u_Textures[2];//uniform 传入的两个纹理槽号索引

void main()
{
	int texInx = int(v_TexSoltIndex);
	color = texture(u_Textures[texInx],v_TextureCoord);
	//描述像素的颜色
	//color = vec4(v_OTextureCoord,0.0,1.0);
};
#version 330 core 

layout(location = 0) out vec4 color;

//接受顶点着色器输出的纹理坐标
in vec2 v_Texcoord;

uniform sampler2D u_Texture;

void main()
{
	//计算出纹理的像素点,即对纹理进行采样
	vec4 texColor = texture(u_Texture,v_Texcoord);
	//设置图形画出的每一个像素的每个片段的色彩都是 u_Color
	color =  texColor ;
};
#version 330 core 

layout(location = 0) out vec4 color;

//接受顶点着色器输出的纹理坐标
in vec2 v_Texcoord;

//u_ 开头描述的是统一变量
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	//计算出纹理的像素点
	vec4 texColor = texture(u_Texture,v_Texcoord);
	//描述像素的颜色
	//color = u_Color;
	//设置图形画出的每一个像素的每个片段的色彩都是 u_Color
	color = u_Color * texColor;
};
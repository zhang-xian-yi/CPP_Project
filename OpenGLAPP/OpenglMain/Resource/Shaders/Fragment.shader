#version 330 core 

layout(location = 0) out vec4 color;

//u_ 开头描述的是统一变量
uniform vec4 u_Color;

void main()
{
	//描述像素的颜色
	//color = vec4(0.5,0.0,0.0,0.1);
	//设置图形画出的每一个像素的每个片段的色彩都是 u_Color
	color = u_Color;
};
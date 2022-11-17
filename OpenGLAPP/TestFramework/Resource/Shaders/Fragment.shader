#version 330 core 

layout(location = 0) out vec4 color;

//u_ 开头描述的是统一变量
uniform vec4 u_Color;

void main()
{
	//描述像素的颜色
	color = u_Color;
};
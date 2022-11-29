#version 330 core 

layout(location = 0) out vec4 color;

in vec4 v_OColor;//接受从顶点着色器中输入的颜色信息 out / in 名字必须一致

void main()
{
	//描述像素的颜色
	color = v_OColor;
};
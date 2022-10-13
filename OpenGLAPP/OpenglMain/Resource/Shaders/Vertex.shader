#version 330 core 

//此处布局描述的是顶点数组中，被layout push<float> 的两个坐标点
//四个folat数字， 前两个被解释为顶点桌标，后两个被解释为纹理桌标
layout(location = 0) in vec4 postion;//顶点坐标
layout(location = 1) in vec2 texcoord;//纹理坐标

//将纹理坐标输出到片段着色器中
out vec2 v_Texcoord;

void main()
{
    gl_Position = postion;
    //赋值输出的纹理坐标采样
    v_Texcoord = texcoord;
};
#version 330 core 

//此处布局描述的是顶点数组中，被layout push<float> 的两个坐标点
layout(location = 0) in vec4 postion;//顶点坐标

void main()
{
    //将顶点数据渲染到指定位置
    gl_Position =  postion;
};
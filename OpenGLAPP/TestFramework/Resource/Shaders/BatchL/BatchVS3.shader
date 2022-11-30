#version 330 core 

//此处布局描述的是顶点数组中，被layout push<float> 的两个坐标点
//与 布局管理中的 glEnableVertexAttribArray 的序号相关联
layout(location = 0) in vec4 a_postion;//顶点坐标
layout(location = 1) in vec4 a_color;//顶点颜色
layout(location = 2) in vec2 a_textureCoord;//顶点颜色
layout(location = 3) in float a_texSoltIndex;//顶点颜色
//像片段着色器输出的顶点颜色信息
out vec2 v_TextureCoord;
out float v_TexSoltIndex;
void main()
{
    v_TexSoltIndex = a_texSoltIndex;
    v_TextureCoord = a_textureCoord;
    //将顶点数据渲染到指定位置
    gl_Position =  a_postion;
};
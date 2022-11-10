#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// 投影矩阵

namespace EntityNS
{
	//渲染的矩阵参数
	struct RenderMatrixPara
	{
		//建立一个投影矩阵,ortho产生一个正交矩阵
		//从左右上下来看分别时-2，2-1.5，1.5  描述从左到右时 -2 + 2 四个单位宽度
		//从上到下时 1.5+1.5 3各单位的高度的区域
		glm::mat4 projectMatrix = glm::ortho(0.0f, 720.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		//模拟视图矩阵：相机左移 意味者对象右移
		glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		//模型矩阵，xyz 三轴，x轴正向200，Y轴正向100单位，Z轴上不同
		glm::vec3 modelVec3 = glm::vec3(0, 0, 0);
	};


	//渲染的对象
	class RenderObj
	{
	public:
		RenderObj();
		~RenderObj();

		RenderMatrixPara* GetMatrixPara()const;
		void SetMatrixPara(RenderMatrixPara* para);
	private:
		RenderMatrixPara* m_pRMPara;// 渲染的对象所需要的矩阵参数
	}; 
}



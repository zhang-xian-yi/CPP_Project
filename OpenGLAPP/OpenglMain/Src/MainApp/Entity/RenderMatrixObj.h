#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"// ͶӰ����

namespace EntityNS
{
	//��Ⱦ�ľ������
	struct RenderMatrixPara
	{
		//����һ��ͶӰ����,ortho����һ����������
		//���������������ֱ�ʱ-2��2-1.5��1.5  ����������ʱ -2 + 2 �ĸ���λ���
		//���ϵ���ʱ 1.5+1.5 3����λ�ĸ߶ȵ�����
		glm::mat4 projectMatrix = glm::ortho(0.0f, 720.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		//ģ����ͼ����������� ��ζ�߶�������
		glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		//ģ�;���xyz ���ᣬx������200��Y������100��λ��Z���ϲ�ͬ
		glm::vec3 modelVec3 = glm::vec3(0, 0, 0);
	};


	//��Ⱦ�Ķ���
	class RenderObj
	{
	public:
		RenderObj();
		~RenderObj();

		RenderMatrixPara* GetMatrixPara()const;
		void SetMatrixPara(RenderMatrixPara* para);
	private:
		RenderMatrixPara* m_pRMPara;// ��Ⱦ�Ķ�������Ҫ�ľ������
	}; 
}



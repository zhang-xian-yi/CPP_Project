#pragma once

#include "TestBase.h"

namespace TestResNS
{
	//IMGUI ����ɫ����
	class TestImGUIBGColor:public TestNS::TestBase
	{
	public:
		TestImGUIBGColor();
		~TestImGUIBGColor();

		//����
		void onUpdate(float deltatime) override;
		void onRender() override;
		void onImGUIRender() override;
	private:
		//�����ĸ���ֵ����������ɫ �ֱ���RGBZ
		float m_ColorFList[4];
	};
}
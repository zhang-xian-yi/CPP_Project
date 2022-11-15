#pragma once

#include "TestBase.h"

namespace TestResNS
{
	//IMGUI 的颜色测试
	class TestImGUIBGColor:public TestNS::TestBase
	{
	public:
		TestImGUIBGColor();
		~TestImGUIBGColor();

		//更新
		void onUpdate(float deltatime) override;
		void onRender() override;
		void onImGUIRender() override;
	private:
		//保存四个数值描述背景颜色 分别是RGBZ
		float m_ColorFList[4];
	};
}
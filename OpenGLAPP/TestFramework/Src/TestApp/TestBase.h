#pragma once

namespace TestNS
{
	//所有测试类的接口
	class TestBase
	{
	public:
		TestBase() {};
		virtual ~TestBase() {}; 

		//需要让图片元素移动起来TODO
		virtual void onUpdate(float deltatime) {};
		//需要在屏幕上显示图片或者元素TODO
		virtual void onRender() {};
		//需要控制或者响应GUITODO
		virtual void onImGUIRender() {};
	};
}




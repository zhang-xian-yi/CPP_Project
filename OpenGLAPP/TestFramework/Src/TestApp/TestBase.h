#pragma once

namespace TestNS
{
	//所有测试类的接口
	class TestBase
	{
	public:
		TestBase() {};
		virtual ~TestBase() {}; 

		//更新
		virtual void onUpdate(float deltatime) {};
		virtual void onRender() {};
		virtual void onImGUIRender() {};
	};
}




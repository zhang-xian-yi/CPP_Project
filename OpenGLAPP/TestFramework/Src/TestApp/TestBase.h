#pragma once

namespace TestNS
{
	//���в�����Ľӿ�
	class TestBase
	{
	public:
		TestBase() {};
		virtual ~TestBase() {}; 

		//����
		virtual void onUpdate(float deltatime) {};
		virtual void onRender() {};
		virtual void onImGUIRender() {};
	};
}




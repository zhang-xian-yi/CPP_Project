#include "TestUIMenu.h"
#include "imGui/imgui.h"

namespace TestResNS
{
	//构造测试对象
	TestUIMenu::TestUIMenu(TestNS::TestBase*& pCurrTest)
		:m_pCurrTest(pCurrTest)
	{
	}

	//初始化测试菜单
	void TestUIMenu::onImGUIRender()
	{
		//
		for (auto& test:m_TestVector)
		{
			//渲染一个button 
			if (ImGui::Button(test.first.c_str()))
			{
				//构件当前测试样例
				m_pCurrTest = test.second();
			}
		}

	}
}
#include "TestUIMenu.h"
#include "imGui/imgui.h"

namespace TestResNS
{
	//������Զ���
	TestUIMenu::TestUIMenu(TestNS::TestBase*& pCurrTest)
		:m_pCurrTest(pCurrTest)
	{
	}

	//��ʼ�����Բ˵�
	void TestUIMenu::onImGUIRender()
	{
		//
		for (auto& test:m_TestVector)
		{
			//��Ⱦһ��button 
			if (ImGui::Button(test.first.c_str()))
			{
				//������ǰ��������
				m_pCurrTest = test.second();
			}
		}

	}
}
#pragma once

#include <vector>
#include <string>
#include <iostream>//Cout
#include <functional>//lamba
#include "TestBase.h"

namespace TestResNS
{
	class TestUIMenu :public TestNS::TestBase
	{
	public:
		TestUIMenu(TestNS::TestBase*& pCurrTest);

		//����UI
		void onImGUIRender() override;

		//ע����Խӿ�
		template<class T>
		void RegisterTest(const std::string& name)
		{
			//ע�����ʵ��
			std::cout << "Register Test Instance" << name << std::endl;
			//lamba ���ʽ�� [] ��׽�� () ������  ����������������ָ�����͵�ʵ��ָ��
			m_TestVector.push_back(std::make_pair(name, []() {return new T(); }));
		}
	private:
		TestBase*& m_pCurrTest; //��ǰ�Ĳ���ʵ��
		//���浱ǰ����ʵ�����������ļ���
		//ע��TestBase*() ���ƺ���ָ�룬����һ������testbase* �ĺ���
		std::vector<std::pair<std::string, std::function<TestBase*()>>> m_TestVector;
	};
}




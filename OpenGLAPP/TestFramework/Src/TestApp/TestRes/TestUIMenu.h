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

		//更新UI
		void onImGUIRender() override;

		//注册测试接口
		template<class T>
		void RegisterTest(const std::string& name)
		{
			//注册测试实例
			std::cout << "Register Test Instance" << name << std::endl;
			//lamba 表达式： [] 捕捉域 () 参数表  描述匿名函数返回指定类型的实例指针
			m_TestVector.push_back(std::make_pair(name, []() {return new T(); }));
		}
	private:
		TestBase*& m_pCurrTest; //当前的测试实例
		//保存当前测试实例创建函数的集合
		//注意TestBase*() 类似函数指针，描述一个返回testbase* 的函数
		std::vector<std::pair<std::string, std::function<TestBase*()>>> m_TestVector;
	};
}




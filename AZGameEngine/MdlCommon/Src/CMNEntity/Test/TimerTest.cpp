#include "TimerTest.h"
#include <iostream>
#include <memory>
namespace MdlCommonNS
{
	//构造函数
	TimerTest::TimerTest()
	{
		//构造时
		m_startTimepoint = std::chrono::high_resolution_clock::now();
	}
	//析构函数
	TimerTest::~TimerTest()
	{
		//停止
		stop();
	}

	/// <summary>
	/// 停止
	/// </summary>
	void TimerTest::stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		//计算相差时间
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = (end - start);
		auto usDuration = duration * 0.001;
		//打印
		std::cout << duration << "us" << "(" << usDuration << " ms )" << std::endl;
	}
}
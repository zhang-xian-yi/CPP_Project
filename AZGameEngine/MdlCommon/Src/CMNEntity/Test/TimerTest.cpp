#include "TimerTest.h"
#include <iostream>
#include <memory>
namespace MdlCommonNS
{
	//���캯��
	TimerTest::TimerTest()
	{
		//����ʱ
		m_startTimepoint = std::chrono::high_resolution_clock::now();
	}
	//��������
	TimerTest::~TimerTest()
	{
		//ֹͣ
		stop();
	}

	/// <summary>
	/// ֹͣ
	/// </summary>
	void TimerTest::stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		//�������ʱ��
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = (end - start);
		auto usDuration = duration * 0.001;
		//��ӡ
		std::cout << duration << "us" << "(" << usDuration << " ms )" << std::endl;
	}
}
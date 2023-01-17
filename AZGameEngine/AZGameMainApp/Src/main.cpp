#include <iostream>
#include <thread>
bool isFinish = false;
void doWork()
{
	using namespace std::literals::chrono_literals;

	std::cout <<"curr thread id:" << std::this_thread::get_id() << std::endl;
	while (!isFinish)
	{
		std::cout << "working" << std::endl;
		std::this_thread::sleep_for(1s);
	}

	std::cout << "end" << std::endl;
}

void testThread()
{
	//线程测试
	std::thread td(doWork);//线程启动

	//主线程继续执行等待用户输入
	std::cin.get();
	isFinish = true;

	td.join();//等待线程结束

}

#include "TimerTest/TimerTest.h"
void TimerTestFunc()
{
	TestCommonNS::TimerTest test;
	std::cout << "Welcome to zhangxianyi AZGame Engine Project" << std::endl;
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}

#include "MdlScheduleFactory.h"

int main(int argc, char* argv[])
{
	auto factory = MdlScheduleNS::MdlScheduleFactory::GetFactory();
	factory->GetModuleInstance();

	
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	std::cin.get();
	return 0;
}


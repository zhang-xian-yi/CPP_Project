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
	//�̲߳���
	std::thread td(doWork);//�߳�����

	//���̼߳���ִ�еȴ��û�����
	std::cin.get();
	isFinish = true;

	td.join();//�ȴ��߳̽���

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


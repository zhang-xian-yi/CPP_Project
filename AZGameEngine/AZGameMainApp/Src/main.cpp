#include <iostream>
#include <thread>
namespace AZGameEngineNS
{
	__declspec(dllimport) void printinfo();
}



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
	//������������
	AZGameEngineNS::printinfo();
	printf("\nXXXXX\n");
}


int main(int argc, char* argv[])
{
	TimerTestFunc();

	std::cin.get();
	return 0;
}


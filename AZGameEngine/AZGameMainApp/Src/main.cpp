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

#include "CMNEntity/Test/TimerTest.h"
int main(int argc, char* argv[])
{
	{
		MdlCommonNS::TimerTest test;
		//������������
		AZGameEngineNS::printinfo();
		printf("\nXXXXX\n");
	}

	std::cin.get();
	return 0;
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
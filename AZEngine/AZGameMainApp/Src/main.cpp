#include "MAMControl/MainApplication.h"
#include <iostream>

int main(int argc, char* argv[])
{
	AZGameMainApp::MainApplication& app = AZGameMainApp::MainApplication::GetInstance();
	//��ʼ������
	app.InitRunEnvirment();



	app.StopRunEnvirment();//�ͷ���Դ
	std::cin.get();
	return 0;
}

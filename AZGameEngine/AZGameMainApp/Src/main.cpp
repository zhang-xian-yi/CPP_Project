#include "MAMControl/MainApplication.h"
#include <iostream>

int main(int argc, char* argv[])
{
	AZGameMainApp::MainApplication& app = AZGameMainApp::MainApplication::GetInstance();
	//初始化环境
	app.InitRunEnvirment();



	std::cin.get();
	return 0;
}


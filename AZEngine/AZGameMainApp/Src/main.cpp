#include "MAMControl/MainApplication.h"
#include <iostream>

int main(int argc, char* argv[])
{
	AZGameMainApp::MainApplication& app = AZGameMainApp::MainApplication::GetInstance();
	//初始化环境
	app.InitApp();

	app.Run();

	app.StopApp();//释放资源
	std::cin.get();
	return 0;
}


#include "MAMControl/MainApplication.h"

int main(int argc, char* argv[])
{
	AZGameMainApp::MainApplication& app = AZGameMainApp::MainApplication::GetInstance();
	//��ʼ������
	app.InitApp();

	app.Run();

	app.StopApp();//�ͷ���Դ
	system("pause");
	return 0;
}


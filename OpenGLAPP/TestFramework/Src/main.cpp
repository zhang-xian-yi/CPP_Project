#include "TestApp/Envirment/Application.h"

int TestAPP(int argc, char* argv[])
{
    EnvirmentNS::Application app;

    app.InitAPPEnvir(1080, 720);

    app.RunAPP();

    app.StopAPP();

    return 0;
}


int main(int argc, char* argv[])
{
     
    return TestAPP(argc,argv);
}


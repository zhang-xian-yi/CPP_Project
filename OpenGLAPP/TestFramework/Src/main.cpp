#include "TestApp/Envirment/Application.h"

int TestAPP(int argc, char* argv[])
{
    EnvirmentNS::Application app;

    app.InitAPPEnvir(720, 480);

    app.RunAPP();

    app.StopAPP();

    return 0;
}


int main(int argc, char* argv[])
{
     
    return TestAPP(argc,argv);
}


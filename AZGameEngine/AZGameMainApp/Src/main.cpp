#include <iostream>
namespace AZGameEngineNS
{
	__declspec(dllimport) void printinfo();
}

int main(int argc, char* argv[])
{
	//������������
	AZGameEngineNS::printinfo();


	std::cin.get();
	return 0;
}

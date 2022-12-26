#include <iostream>
namespace AZGameEngineNS
{
	__declspec(dllimport) void printinfo();
}

int main(int argc, char* argv[])
{
	//第三方库引用
	AZGameEngineNS::printinfo();


	std::cin.get();
	return 0;
}

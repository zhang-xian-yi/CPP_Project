
namespace AZGameEngineNS
{
	__declspec(dllimport) void printinfo();
}

int main(int argc, char* argv[])
{
	//第三方库引用
	AZGameEngineNS::printinfo();


	return 0;
}

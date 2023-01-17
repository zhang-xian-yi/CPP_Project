#include <iostream>
#include "MdlScheduleFactory.h"

int main(int argc, char* argv[])
{
	auto factory = MdlScheduleNS::MdlScheduleFactory::GetFactory();
	auto pMdlScheduleCtl = factory->CreateModuleInstance();

	{
		//构造所有的功能
		auto tmpRep = pMdlScheduleCtl->ConstructModule(nullptr);
	}


	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	std::cin.get();

	pMdlScheduleCtl->DestoryModule();
	std::cin.get();
	return 0;
}


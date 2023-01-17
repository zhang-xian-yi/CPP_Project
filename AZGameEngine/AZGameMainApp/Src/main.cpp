#include <iostream>
#include "MdlScheduleFactory.h"

int main(int argc, char* argv[])
{
	auto factory = MdlScheduleNS::MdlScheduleFactory::GetFactory();
	auto pMdlScheduleCtl = factory->CreateModuleInstance();

	{
		//�������еĹ���
		auto tmpRep = pMdlScheduleCtl->ConstructModule(nullptr);
	}


	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	std::cin.get();

	pMdlScheduleCtl->DestoryModule();
	std::cin.get();
	return 0;
}


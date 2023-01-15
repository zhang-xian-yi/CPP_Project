#pragma once
//用于创建执行时间测试的类，将该类定义到函数执行前，
//等到函数执行完毕，对象销毁时自动打印执行时间，仅在测试时使用，且必须移植出Common模块
#include <CMNMacro/CMNExpMarcoDefine.h>
#include<chrono>//时间相关

namespace CommonNS
{
	//用于创建某个作用域的具体执行时间
	class CommonDLLAPI TimerTest
	{
	public:
		TimerTest();
		~TimerTest();
	private:
		void stop();//停止
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
	};
}


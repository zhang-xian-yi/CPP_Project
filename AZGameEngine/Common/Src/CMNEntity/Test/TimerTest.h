#pragma once
//���ڴ���ִ��ʱ����Ե��࣬�����ඨ�嵽����ִ��ǰ��
//�ȵ�����ִ����ϣ���������ʱ�Զ���ӡִ��ʱ�䣬���ڲ���ʱʹ�ã��ұ�����ֲ��Commonģ��
#include <CMNMacro/CMNExpMarcoDefine.h>
#include<chrono>//ʱ�����

namespace CommonNS
{
	//���ڴ���ĳ��������ľ���ִ��ʱ��
	class CommonDLLAPI TimerTest
	{
	public:
		TimerTest();
		~TimerTest();
	private:
		void stop();//ֹͣ
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
	};
}


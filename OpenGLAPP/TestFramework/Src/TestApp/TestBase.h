#pragma once

namespace TestNS
{
	//���в�����Ľӿ�
	class TestBase
	{
	public:
		TestBase() {};
		virtual ~TestBase() {}; 

		//��Ҫ��ͼƬԪ���ƶ�����TODO
		virtual void onUpdate(float deltatime) {};
		//��Ҫ����Ļ����ʾͼƬ����Ԫ��TODO
		virtual void onRender() {};
		//��Ҫ���ƻ�����ӦGUITODO
		virtual void onImGUIRender() {};
	};
}




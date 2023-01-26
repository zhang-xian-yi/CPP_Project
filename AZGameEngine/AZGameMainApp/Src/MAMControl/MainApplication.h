#pragma once

namespace AZGameMainApp
{
	/// <summary>
	/// 游戏主程序，负责程序的初始化,启动、停止、资源释放
	/// 单例模式
	/// </summary>
	class MainApplication
	{
	public:
		static MainApplication& GetInstance()
		{
			static MainApplication instance;
			return instance;
		}
	public:
		void InitRunEnvirment();
		void StopRunEnvirment();
	private:
		bool InitAllFunction();//初始化所有的功能模块并注册
		bool StopAllFunction();//停止所有的功能模块并取消注册
	private:
		//禁止反复定义工厂，禁止delelte 工厂对象
		MainApplication();
		~MainApplication();
		MainApplication(MainApplication& instance) = delete;
		MainApplication& operator=(const MainApplication& instance) = delete;
	};

}


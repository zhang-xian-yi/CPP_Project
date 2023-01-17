#pragma once

namespace AZGameMainApp
{
	/// <summary>
	/// ��Ϸ�����򣬸������ĳ�ʼ��,������ֹͣ����Դ�ͷ�
	/// ����ģʽ
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

	private:
		bool& InitAllFunction();//��ʼ�����еĹ���ģ�鲢ע��

	private:
		//��ֹ�������幤������ֹdelelte ��������
		MainApplication();
		~MainApplication();
		MainApplication(MainApplication& instance) = delete;
		MainApplication& operator=(const MainApplication& instance) = delete;
	};

}


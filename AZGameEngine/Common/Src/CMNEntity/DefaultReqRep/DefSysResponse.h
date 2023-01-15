#pragma once
#include <string>
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏
#include <CMNInterface/ISysResponse.h>

namespace CommonNS
{
	//前置声明 在cpp中实现- 封装一层防止导出类中使用std模板类编译出现的4251警告
	class DefSysResponsePrivate;

	//接口实现类
	class CommonDLLAPI DefSysResponse :public ISysResponse
	{
	public:
		DefSysResponse();
		~DefSysResponse();
	public:
		bool GetIsSuccess()const;
		const std::string& GetMessage()const;
		//数据设置
		void SetIsSuccess(const bool falg);
		void SetMessage(const std::string& message);
		//合法检查
		virtual bool IsValid() const override;
	private:
		DefSysResponsePrivate* m_pService;
	};
}


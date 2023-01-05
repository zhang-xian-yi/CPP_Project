#pragma once
#include <string>
#include <Common/ExportMarcoDefine.h>
#include <Interface/ISysResponse.h>

namespace CommonNS
{
	class CommonDLLAPI DefSysResponse :public ISysResponse
	{
	public:
		DefSysResponse();
		~DefSysResponse();
	public:
		bool GetIsSuccess()const;
		const std::string& GetMessage()const;

		void SetIsSuccess(const bool falg);
		void SetMessage(const std::string& message);

		virtual bool IsValid() const override;
	private:
		bool m_isSucc;
		std::string m_message;
	};
}


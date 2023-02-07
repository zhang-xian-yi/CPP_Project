#pragma once
#include <string>
#include <functional>
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"

//前置声明
namespace EventCommonNS
{
	class IEvent;
}

namespace WindowsNS
{
	/// <summary>
	/// 窗口配置信息
	/// </summary>
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "AZ Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//事件回调函数
	using EventCallbackFn = std::function<bool(EventCommonNS::IEvent&)>;

	// Interface representing a desktop system based Window
	/// <summary>
	/// 约定窗口类的必要操作
	/// </summary>
	class IWindow
	{
	public:
		//析构函数
		virtual ~IWindow() = default;
		//窗口更新函数
		virtual void OnUpdate() = 0;
		//窗口
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		//窗口显示
		virtual void Show() = 0;
		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		//这里返回GFWindows 的窗口指针
		virtual void* GetNativeWindow() const = 0;
		//默认创建一个1000 X 900 且名称为AZ Engine 的窗口
		static MdlCommonNS::Scope<IWindow> Create(const WindowProps & props = WindowProps());
	};
}
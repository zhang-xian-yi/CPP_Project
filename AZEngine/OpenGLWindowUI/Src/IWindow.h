#pragma once
#include <string>
#include <functional>
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"

//前置声明
namespace LayerCommonNS
{
	class ISysEvent;
	class ILayer;
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
	using EventCallbackFn = std::function<bool(LayerCommonNS::ISysEvent&)>;

	// Interface representing a desktop system based Window
	/// <summary>
	/// 约定窗口类的必要操作
	/// </summary>
	class IWindow
	{
	public:
		//析构函数
		virtual ~IWindow() = default;
		//获取窗口层的操作指针
		virtual LayerCommonNS::ILayer* GetOpenGLWindowLayer() = 0;
		//窗口
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		//窗口显示
		virtual void Show() = 0;
		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		//这里返回GFWindows 的窗口指针
		virtual void* GetNativeWindow() const = 0;
	};
}
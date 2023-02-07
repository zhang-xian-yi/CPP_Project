#pragma once
#include <string>
#include <functional>
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"

//ǰ������
namespace EventCommonNS
{
	class IEvent;
}

namespace WindowsNS
{
	/// <summary>
	/// ����������Ϣ
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

	//�¼��ص�����
	using EventCallbackFn = std::function<bool(EventCommonNS::IEvent&)>;

	// Interface representing a desktop system based Window
	/// <summary>
	/// Լ��������ı�Ҫ����
	/// </summary>
	class IWindow
	{
	public:
		//��������
		virtual ~IWindow() = default;
		//���ڸ��º���
		virtual void OnUpdate() = 0;
		//����
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		//������ʾ
		virtual void Show() = 0;
		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		//���ﷵ��GFWindows �Ĵ���ָ��
		virtual void* GetNativeWindow() const = 0;
		//Ĭ�ϴ���һ��1000 X 900 ������ΪAZ Engine �Ĵ���
		static MdlCommonNS::Scope<IWindow> Create(const WindowProps & props = WindowProps());
	};
}
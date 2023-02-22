#pragma once
#include <string>
#include <functional>
#include "MdlCommon/Src/CMNMacro/TypeMacroDef.h"

//ǰ������
namespace LayerCommonNS
{
	class ISysEvent;
	class ILayer;
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
	using EventCallbackFn = std::function<bool(LayerCommonNS::ISysEvent&)>;

	// Interface representing a desktop system based Window
	/// <summary>
	/// Լ��������ı�Ҫ����
	/// </summary>
	class IWindow
	{
	public:
		//��������
		virtual ~IWindow() = default;
		//��ȡ���ڲ�Ĳ���ָ��
		virtual LayerCommonNS::ILayer* GetOpenGLWindowLayer() = 0;
		//����
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		//������ʾ
		virtual void Show() = 0;
		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		//���ﷵ��GFWindows �Ĵ���ָ��
		virtual void* GetNativeWindow() const = 0;
	};
}
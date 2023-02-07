#pragma once

namespace WindowsNS
{
	//窗口数据
	struct WindowData
	{
		WindowProps WinPros;//窗口属性
		bool VSync;
		EventCallbackFn EventCallback;
	};
}

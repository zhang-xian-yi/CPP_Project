#pragma once

namespace WindowsNS
{
	//��������
	struct WindowData
	{
		WindowProps WinPros;//��������
		bool VSync;
		EventCallbackFn EventCallback;
	};
}

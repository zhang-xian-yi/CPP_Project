#pragma once
//模块接口，抽象渲染器的外部操作

namespace ImguiRendererNS
{
	class IImguiRenderer
	{
	public:
		virtual ~IImguiRenderer() = 0;//虚析构函数
	};
}
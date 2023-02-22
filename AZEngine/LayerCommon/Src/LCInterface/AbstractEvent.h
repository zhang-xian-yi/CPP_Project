#pragma once

namespace LayerCommonNS
{
	//层数的接口
	class AbstractEvent
	{
	public:
		AbstractEvent() = default;
		~AbstractEvent() = default;
	public:
		virtual bool IsHandle() = 0;
	};
}
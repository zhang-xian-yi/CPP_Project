#pragma once

namespace LayerCommonNS
{
	//�����Ľӿ�
	class AbstractEvent
	{
	public:
		AbstractEvent() = default;
		~AbstractEvent() = default;
	public:
		virtual bool IsHandle() = 0;
	};
}
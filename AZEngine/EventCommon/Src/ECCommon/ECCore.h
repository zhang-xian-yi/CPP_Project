#pragma once
namespace EventCommonNS
{
//左移
#define LBit1(x)						(1 << x)

///定义事件之子类的类型
#define DEF_EVENT_TYPE(type)			static ESysEventId GetStaticId() { return ESysEventId::type; }\
										virtual ESysEventId GetEventId() const override { return GetStaticId(); }

//定义事件子类的
#define DEF_EVENT_CATEGORY(category)    virtual int GetCategoryFlags() const override { return category; }
}
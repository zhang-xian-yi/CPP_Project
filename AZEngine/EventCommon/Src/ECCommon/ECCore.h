#pragma once
namespace EventCommonNS
{
//����
#define LBit1(x)						(1 << x)

///�����¼�֮���������
#define DEF_EVENT_TYPE(type)			static ESysEventId GetStaticId() { return ESysEventId::type; }\
										virtual ESysEventId GetEventId() const override { return GetStaticId(); }

//�����¼������
#define DEF_EVENT_CATEGORY(category)    virtual int GetCategoryFlags() const override { return category; }
}
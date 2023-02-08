#pragma once
namespace LayerCommonNS
{
//����
#define LBit1(x)						(1 << x)

///�����¼�֮���������
#define DEF_EVENT_TYPE(type)			static ESysEventId GetStaticId() { return ESysEventId::type; }\
										virtual ESysEventId GetEventId() const override { return GetStaticId(); }\
										virtual const char* GetName() const override { return #type; }

//�����¼������
#define DEF_EVENT_CATEGORY(category)    virtual int GetCategoryFlags() const override { return category; }

//���¼��ĺ궨��
#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
}
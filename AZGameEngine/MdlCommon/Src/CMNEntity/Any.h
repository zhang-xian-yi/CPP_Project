#pragma once
#include <CMNMacro/CMNExpMarcoDefine.h> //导出宏

namespace MdlCommonNS
{
	//前置声明
	class BaseHolder;

	/// <summary>
	/// 任意类型的数据，一般用作返回值
	/// </summary>
	class MdlCommonDLLAPI Any
	{
	public:
		//模板的任意类型构造函数
		template<typename ValueType>
		Any(const ValueType& value);
		//拷贝构造函数
		Any(const Any& any);
		//析构函数
		~Any();
		//赋值运算符
		template<typename ValueType>
		Any& operator=(const ValueType& value);
	public:
		//值类型的指针转换
		template<typename ValueType>
		ValueType* anyPointCast();
		//值类型的引用转换
		template<typename ValueType>
		ValueType& anyRefCast();
	public:
		/*Get and Set  方法一般是函数内部调用，但必须公开，所以外部尽量不调用该方法  ********************************/
		//获取私有成员value的指针
		BaseHolder* GetHolderPointer()const;
		//设置私有成员value的指针
		void SetHolderPointer(BaseHolder* pointer);
	private:
		BaseHolder* m_pValue;
	};

}


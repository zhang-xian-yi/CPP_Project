#pragma once
namespace LayoutNS
{
	/// <summary>
	/// 描述布局元素的关键信息
	/// </summary>
	class VLayoutElement
	{
	public:
		VLayoutElement();
		VLayoutElement(unsigned int type, unsigned int count,bool normalized);
		~VLayoutElement();

		unsigned int GetType()const;//获取成员变量
		unsigned int GetCount()const;//
		bool GetNormalized()const;

		void SetType(unsigned int type);//设置成员变量
		void SetCount(unsigned int count);//
		void SetNormalized(bool normalized);

		static unsigned int GetSizeOfType(unsigned int type);
	private:
		unsigned int m_type;//类型
		unsigned int m_count;//个数
		bool		 m_normalized; //是否归一化
	};
}



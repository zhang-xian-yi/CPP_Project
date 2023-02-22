#pragma once

namespace ImguiRendererNS
{
	class IndexBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();
		//设置索引缓冲区地址以及元素个数，并指定索引为int
		void SetIndexData(const unsigned int* pArray,unsigned int count);
		void Bind()const;//绑定索引缓冲功能区
		void UnBind()const;//解绑索引缓冲功能区
		void ReleaseBuffer();//释放缓冲区
		//内联 获取成员变量的函数
		inline unsigned int GetCount()const { return m_Count; }
	private:
		//渲染的ID
		unsigned int m_RenderID;
		//索引个数
		unsigned int m_Count;
	};

}

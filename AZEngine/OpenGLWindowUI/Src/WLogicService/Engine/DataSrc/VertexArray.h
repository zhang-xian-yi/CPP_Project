#pragma once

//前置声明
namespace WindowsNS {
	class VertexBufferLayout;
	class VertexBuffer;
}

//数据源的空间
namespace WindowsNS
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void Bind()const;
		void UnBind()const;

		void BindVBuffAndVLayout(const WindowsNS::VertexBuffer& VBuf, const WindowsNS::VertexBufferLayout& VLayout);;
	private:
		unsigned int m_RenderID;
	};
}
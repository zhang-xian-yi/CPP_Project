#pragma once

//前置声明
namespace LayoutNS {
	class VertexBufferLayout;
}
namespace BuffersNS {
	class VertexBuffer;
}

//数据源的空间
namespace DataSrcNS
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void Bind()const;
		void UnBind()const;

		void BindVBuffAndVLayout(const BuffersNS::VertexBuffer& VBuf, const LayoutNS::VertexBufferLayout& VLayout);;
	private:
		unsigned int m_RenderID;
	};
}
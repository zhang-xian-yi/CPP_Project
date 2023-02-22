#pragma once

//前置声明
namespace ImguiRendererNS {
	class VertexBufferLayout;
	class VertexBuffer;
}

//数据源的空间
namespace ImguiRendererNS
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void Bind()const;
		void UnBind()const;

		void BindVBuffAndVLayout(const ImguiRendererNS::VertexBuffer& VBuf, const ImguiRendererNS::VertexBufferLayout& VLayout);;
	private:
		unsigned int m_RenderID;
	};
}
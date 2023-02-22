#pragma once

//ǰ������
namespace ImguiRendererNS {
	class VertexBufferLayout;
	class VertexBuffer;
}

//����Դ�Ŀռ�
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
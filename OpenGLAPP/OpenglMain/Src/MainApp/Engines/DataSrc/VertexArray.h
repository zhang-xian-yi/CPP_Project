#pragma once

//ǰ������
namespace LayoutNS {
	class VertexBufferLayout;
}
namespace BuffersNS {
	class VertexBuffer;
}

//����Դ�Ŀռ�
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
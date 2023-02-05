#pragma once

//ǰ������
namespace WindowsNS {
	class VertexBufferLayout;
	class VertexBuffer;
}

//����Դ�Ŀռ�
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
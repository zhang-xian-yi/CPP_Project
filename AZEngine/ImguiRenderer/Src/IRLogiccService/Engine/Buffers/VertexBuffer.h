#pragma once

namespace ImguiRendererNS
{
	/// <summary>
	/// 顶点缓冲功能区的业务逻辑
	/// </summary>
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();
		//注意因为存在改变顶点空间的可能，所以传入的顶点数据空间内存不受此类管理
		void SetStaticVertexData(const void* pArray,unsigned int size);
		void SetDynamicVertexData(const void* pArray, unsigned int size);
		void Bind()const;
		void UnBind()const;
		void ReleaseBuffer();//释放缓冲区
	private:
		//渲染的ID
		unsigned int m_RenderID;
	};

}

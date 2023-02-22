#pragma once
#include <string>
//前置声明
namespace ImguiRendererNS
{
	class VertexBuffer;
	class IndexBuffer;
	class VertexBufferLayout;
	class VertexArray;
}

//设置引擎的命名空间
namespace ImguiRendererNS
{
	/// <summary>
	/// 管理数据加载的引擎
	/// </summary>
	class DataLoadEnginePrivate
	{
	public:
		DataLoadEnginePrivate();
		~DataLoadEnginePrivate();
		//设置索引缓冲区地址以及元素个数，并指定索引为int
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//注意因为存在改变顶点空间的可能，所以传入的顶点数据空间内存不受此类管理
		//传入顶点数据
		void SetVertexData(const void* pArray, unsigned int size);
		//返回布局顶点缓冲区
		VertexBufferLayout* GetVBufLayoutPointer()const;
		//获取顶点数组的指针
		VertexArray* GetVertexArrayPointer()const;
		//获取索引缓冲区的指针
		IndexBuffer* GetIndexBufferPointer()const;
		//获取索引缓冲区的指针
		VertexBuffer* GetVertexBufferPointer()const;
		//绑定顶点缓冲区和顶点布局的关系
		void BindVBuffAndVLayout();
		//释放资源
		void ReleaseSrc();
	private:
		//声明
		IndexBuffer* m_pIndexBufferS;
		VertexBuffer* m_pVertexBufferS;
		VertexBufferLayout* m_pVBufLayout;//顶点缓冲区布局定义
		//注意此处的顶点数组描述的是 一个完整意义上的顶点
		//例如一个顶点可以包含 方向，大小，角度，温度等，是所有顶点信息的集合
		VertexArray* m_pVArray;//顶点数据数组
	};

}

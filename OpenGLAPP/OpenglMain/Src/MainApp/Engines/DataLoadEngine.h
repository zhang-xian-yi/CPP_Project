#pragma once
#include <string>
//前置声明
namespace BuffersNS
{
	class VertexBuffer;
	class IndexBuffer;
}

namespace DataSrcNS
{
	class VertexArray;
}

namespace LayoutNS
{
	class VertexBufferLayout;
}
//设置引擎的命名空间
namespace EngineNS
{
	/// <summary>
	/// 管理数据加载的引擎
	/// </summary>
	class DataLoadEngine
	{
	public:
		DataLoadEngine();
		~DataLoadEngine();
		//设置索引缓冲区地址以及元素个数，并指定索引为int
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		const BuffersNS::IndexBuffer& GetIndexBuffer()const;
		//注意因为存在改变顶点空间的可能，所以传入的顶点数据空间内存不受此类管理
		//传入顶点数据
		void SetVertexData(const void* pArray, unsigned int size);
		const DataSrcNS::VertexArray& GetVArray()const;
		//初始化数据环境
		void InitDataEnvir();
		//释放资源
		void ReleaseSrc();
	private:
		//声明
		BuffersNS::IndexBuffer* m_pIndexBufferS;
		BuffersNS::VertexBuffer* m_pVertexBufferS;
		LayoutNS::VertexBufferLayout* m_pVBufLayout;//顶点缓冲区布局定义
		DataSrcNS::VertexArray* m_pVArray;//顶点数据数组
	};

}

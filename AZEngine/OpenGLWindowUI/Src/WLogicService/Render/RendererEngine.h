#pragma once
//前置声明
namespace WindowsNS
{
	class IndexBuffer;
	class VertexArray;
	class ShaderManager;//着色器管理业务
	class DataLoadEnginePrivate;//数据加载引擎
}

namespace WindowsNS
{
	/// <summary>
	/// 渲染器的引擎
	/// </summary>
	class RendererEngine
	{
	public:
		RendererEngine();
		~RendererEngine();
		//清楚
		void Clear();
		//根据顶点数组，索引缓冲区，着色器进行渲染工作
		void RendererDraw(const DataLoadEnginePrivate* m_pDataloadEngine,const ShaderManager* shader);
		void RendererDraw(const VertexArray& vArray, const IndexBuffer& iBuf, const ShaderManager& shader);
	private:

	};
}



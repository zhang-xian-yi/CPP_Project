#pragma once
//前置声明
namespace BuffersNS
{
	class IndexBuffer;
}

namespace DataSrcNS
{
	class VertexArray;
}

namespace ShaderNS
{
	class ShaderManager;//着色器管理业务
}

namespace EngineNS
{
	class DataLoadEnginePrivate;//数据加载引擎
}

namespace RenderNS
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
		void RendererDraw(const EngineNS::DataLoadEnginePrivate* m_pDataloadEngine,const ShaderNS::ShaderManager* shader);
		void RendererDraw(const DataSrcNS::VertexArray& vArray, const BuffersNS::IndexBuffer& iBuf, const ShaderNS::ShaderManager& shader);
	private:

	};
}



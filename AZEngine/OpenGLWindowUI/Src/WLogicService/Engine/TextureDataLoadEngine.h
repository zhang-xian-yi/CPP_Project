#pragma once
#include <string>
//前置声明
namespace WindowsNS
{
	class DataLoadEnginePrivate;
}
//设置引擎的命名空间
namespace WindowsNS
{
	/// <summary>
	/// 管理数据加载的引擎
	/// </summary>
	class TextureDataLoadEngine
	{
	public:
		TextureDataLoadEngine();
		~TextureDataLoadEngine();
		//设置索引缓冲区地址以及元素个数，并指定索引为int
		void SetIndexData(const unsigned int* pArray, unsigned int count);
		//注意因为存在改变顶点空间的可能，所以传入的顶点数据空间内存不受此类管理
		//传入顶点数据
		void SetVertexData(const void* pArray, unsigned int size);
		//初始化纹理环境
		void InitTextureEnvir();
		//数据数据加载引擎的指针
		WindowsNS::DataLoadEnginePrivate* GetDataLoadEnginePointer()const;
	private:
		//私有处理逻辑
		WindowsNS::DataLoadEnginePrivate* m_pDLEPrivate;
	};

}

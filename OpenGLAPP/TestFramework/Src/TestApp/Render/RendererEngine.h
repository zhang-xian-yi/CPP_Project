#pragma once
//ǰ������
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
	class ShaderManager;//��ɫ������ҵ��
}

namespace EngineNS
{
	class DataLoadEnginePrivate;//���ݼ�������
}

namespace RenderNS
{
	/// <summary>
	/// ��Ⱦ��������
	/// </summary>
	class RendererEngine
	{
	public:
		RendererEngine();
		~RendererEngine();
		//���
		void Clear();
		//���ݶ������飬��������������ɫ��������Ⱦ����
		void RendererDraw(const EngineNS::DataLoadEnginePrivate* m_pDataloadEngine,const ShaderNS::ShaderManager* shader);
		void RendererDraw(const DataSrcNS::VertexArray& vArray, const BuffersNS::IndexBuffer& iBuf, const ShaderNS::ShaderManager& shader);
	private:

	};
}



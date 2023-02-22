#pragma once
//ǰ������
namespace ImguiRendererNS
{
	class IndexBuffer;
	class VertexArray;
	class ShaderManager;//��ɫ������ҵ��
	class DataLoadEnginePrivate;//���ݼ�������
}

namespace ImguiRendererNS
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
		void RendererDraw(const DataLoadEnginePrivate* m_pDataloadEngine,const ShaderManager* shader);
		void RendererDraw(const VertexArray& vArray, const IndexBuffer& iBuf, const ShaderManager& shader);
	private:

	};
}



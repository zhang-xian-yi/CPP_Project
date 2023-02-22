#pragma once
#include <string>

namespace ImguiRendererNS
{
	/// <summary>
	/// ʵ�������ҵ��
	/// </summary>
	class TextureService
	{
	public:
		TextureService();
		~TextureService();

		//���ļ�������������
		int LoadFileTexture(const std::string& path);
		
		int GetWidth()const { return m_width; }
		int GetHeight() const { return m_height; }

		//����һ�ΰ󶨶�������λ��һ��GPU�ж�������λ
		void Bind(unsigned int solt = 0);
		void UnBind();
	private:
		unsigned int m_rendererId;//��ȾID
		std::string m_filePath;//ͼƬ�ļ�·��
		unsigned char* m_localBuf;//ͼƬ���ػ�����
		int m_width;
		int m_height;
		int m_BPP;//ʵ�������ÿ����λ
	};
}


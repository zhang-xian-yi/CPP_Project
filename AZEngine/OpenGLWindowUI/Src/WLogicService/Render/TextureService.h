#pragma once
#include <string>

namespace ImguiRendererNS
{
	/// <summary>
	/// 实现纹理的业务
	/// </summary>
	class TextureService
	{
	public:
		TextureService();
		~TextureService();

		//对文件进行纹理设置
		int LoadFileTexture(const std::string& path);
		
		int GetWidth()const { return m_width; }
		int GetHeight() const { return m_height; }

		//可以一次绑定多个纹理槽位，一般GPU有多个纹理槽位
		void Bind(unsigned int solt = 0);
		void UnBind();
	private:
		unsigned int m_rendererId;//渲染ID
		std::string m_filePath;//图片文件路径
		unsigned char* m_localBuf;//图片像素缓冲区
		int m_width;
		int m_height;
		int m_BPP;//实际纹理的每像素位
	};
}


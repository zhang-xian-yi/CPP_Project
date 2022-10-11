#include "TextureService.h"
//
#include "RendererEngine.h"
#include "GL/glew.h"
#include "../../_00ThirdPartSrc/stb_image/stb_image.h"//文件加载工具

RenderNS::TextureService::TextureService()
	:m_rendererId(0), m_width(0), m_height(0), m_BPP(0),
	 m_filePath(""), m_localBuf(nullptr)
{
}

RenderNS::TextureService::~TextureService()
{
	//释放图片资源
	if (m_localBuf != nullptr)
	{
		stbi_image_free(m_localBuf);
		m_localBuf = nullptr;
	}
	//删除GPU纹理
	glDeleteTextures(1, &m_rendererId);

}

int RenderNS::TextureService::InitFileTexture(const std::string& path)
{
	//图像是认定左上角位坐标0,0点，opengl希望左下角是坐标0，0点
	//为了关联双方，将图片颠倒读取
	stbi_set_flip_vertically_on_load(1);
	//从文件中加载指定图片，传入长宽高，每像素点的指针，方便函数写入图片的数值
	//4 描述了RGBA 4个通道
	m_localBuf = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
	//创建一个纹理缓冲区并绑定
	glGenTextures(1, &m_rendererId);
	glBindTexture(GL_TEXTURE_2D, m_rendererId);

	//GL_TEXTURE_MIN_FILTER 缩小过滤器，保存纹理，比实际图片的纹理小
	// GL_TEXTURE_MAG_FILTER 方法过滤器，纹理比实际图片更大，区域
	//GL_LINEAR 线性重新取样
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//之地给你嵌入模式-- 也就是图片如何环绕 
	//GL_CLAMP 不扩展实际大小，选择平铺
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//注意必须指定以上纹理的四个参数，否则纹理就是黑色

	//GL_RGBA8 不是图片格式，是我们希望opengl用何种格式处理图片,并指定每个通道有多少位
	//GL_RGBA 描述图片格式，就是提供的文件格式
	//GL_UNSIGNED_BYTE 描述数据的类型
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuf);;
	glBindTexture(GL_TEXTURE_2D, 0);//解绑纹理缓冲功能区
	
	return 0;
}

void RenderNS::TextureService::Bind(unsigned int solt = 0)
{
	//激活指定的纹理卡槽， 一般需要查询GPU型号支持多少个卡槽
	//通常激活纹理卡槽也意味着将要绑定纹理卡槽和缓冲区
	glActiveTexture(GL_TEXTURE0 + solt);
	glBindTexture(GL_TEXTURE_2D, m_rendererId);//解绑纹理缓冲功能区
}

void RenderNS::TextureService::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);//解绑纹理缓冲功能区
}

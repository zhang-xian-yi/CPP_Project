#include "TextureService.h"
//
#include "RendererEngine.h"
#include "GL/glew.h"
#include "../../_00ThirdPartSrc/stb_image/stb_image.h"//�ļ����ع���

RenderNS::TextureService::TextureService()
	:m_rendererId(0), m_width(0), m_height(0), m_BPP(0),
	 m_filePath(""), m_localBuf(nullptr)
{
}

RenderNS::TextureService::~TextureService()
{
	//�ͷ�ͼƬ��Դ
	if (m_localBuf != nullptr)
	{
		stbi_image_free(m_localBuf);
		m_localBuf = nullptr;
	}
	//ɾ��GPU����
	glDeleteTextures(1, &m_rendererId);

}

int RenderNS::TextureService::InitFileTexture(const std::string& path)
{
	//ͼ�����϶����Ͻ�λ����0,0�㣬openglϣ�����½�������0��0��
	//Ϊ�˹���˫������ͼƬ�ߵ���ȡ
	stbi_set_flip_vertically_on_load(1);
	//���ļ��м���ָ��ͼƬ�����볤��ߣ�ÿ���ص��ָ�룬���㺯��д��ͼƬ����ֵ
	//4 ������RGBA 4��ͨ��
	m_localBuf = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);
	//����һ��������������
	glGenTextures(1, &m_rendererId);
	glBindTexture(GL_TEXTURE_2D, m_rendererId);

	//GL_TEXTURE_MIN_FILTER ��С������������������ʵ��ͼƬ������С
	// GL_TEXTURE_MAG_FILTER �����������������ʵ��ͼƬ��������
	//GL_LINEAR ��������ȡ��
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//֮�ظ���Ƕ��ģʽ-- Ҳ����ͼƬ��λ��� 
	//GL_CLAMP ����չʵ�ʴ�С��ѡ��ƽ��
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//ע�����ָ������������ĸ�����������������Ǻ�ɫ

	//GL_RGBA8 ����ͼƬ��ʽ��������ϣ��opengl�ú��ָ�ʽ����ͼƬ,��ָ��ÿ��ͨ���ж���λ
	//GL_RGBA ����ͼƬ��ʽ�������ṩ���ļ���ʽ
	//GL_UNSIGNED_BYTE �������ݵ�����
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_localBuf);;
	glBindTexture(GL_TEXTURE_2D, 0);//��������幦����
	
	return 0;
}

void RenderNS::TextureService::Bind(unsigned int solt = 0)
{
	//����ָ���������ۣ� һ����Ҫ��ѯGPU�ͺ�֧�ֶ��ٸ�����
	//ͨ������������Ҳ��ζ�Ž�Ҫ�������ۺͻ�����
	glActiveTexture(GL_TEXTURE0 + solt);
	glBindTexture(GL_TEXTURE_2D, m_rendererId);//��������幦����
}

void RenderNS::TextureService::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);//��������幦����
}

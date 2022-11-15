#include "TestImGUIBGColor.h"
#include "Error/ErrorMacroDefie.h"// ����
#include "imGui/imgui.h"
namespace TestResNS
{
	//���캯��
	TestImGUIBGColor::TestImGUIBGColor()
		:m_ColorFList{0.1f,0.3f,0.8f,1.0f}
	{
	}

	//�鹹����
	TestImGUIBGColor::~TestImGUIBGColor()
	{
	}
	//����
	void TestImGUIBGColor::onUpdate(float deltatime)
	{

	}
	//��Ⱦ
	void TestImGUIBGColor::onRender()
	{
		//��Ⱦ��ɫ
		GLCallWarn(glClearColor(m_ColorFList[0], m_ColorFList[1], m_ColorFList[2], m_ColorFList[3]));
		GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
	}

	//������Ⱦ
	void TestImGUIBGColor::onImGUIRender()
	{
		ImGui::ColorEdit4("Color Edit 4",m_ColorFList);
	}
}
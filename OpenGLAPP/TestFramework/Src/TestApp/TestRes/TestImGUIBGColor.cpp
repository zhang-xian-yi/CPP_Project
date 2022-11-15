#include "TestImGUIBGColor.h"
#include "Error/ErrorMacroDefie.h"// 错误
#include "imGui/imgui.h"
namespace TestResNS
{
	//构造函数
	TestImGUIBGColor::TestImGUIBGColor()
		:m_ColorFList{0.1f,0.3f,0.8f,1.0f}
	{
	}

	//虚构函数
	TestImGUIBGColor::~TestImGUIBGColor()
	{
	}
	//更新
	void TestImGUIBGColor::onUpdate(float deltatime)
	{

	}
	//渲染
	void TestImGUIBGColor::onRender()
	{
		//渲染颜色
		GLCallWarn(glClearColor(m_ColorFList[0], m_ColorFList[1], m_ColorFList[2], m_ColorFList[3]));
		GLCallWarn(glClear(GL_COLOR_BUFFER_BIT));
	}

	//界面渲染
	void TestImGUIBGColor::onImGUIRender()
	{
		ImGui::ColorEdit4("Color Edit 4",m_ColorFList);
	}
}
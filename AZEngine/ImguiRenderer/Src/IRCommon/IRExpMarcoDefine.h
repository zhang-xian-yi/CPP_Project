#pragma once

//ImguiRenderer ģ��һ���ᶨ�� IMGUI_RENDERER_NS_Export Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef IMGUI_RENDERER_NS_Export

#define ImguiRendererNSAPI __declspec(dllexport)

#else

#define ImguiRendererNSAPI __declspec(dllimport)

#endif // IMGUI_RENDERER_NS_Export



#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef WINDOW_NS_EXPORT

#define WindowsNSDLLAPI __declspec(dllexport)

#else

#define WindowsNSDLLAPI __declspec(dllimport)

#endif // OPENGL_UI_EXPORT





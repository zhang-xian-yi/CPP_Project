#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef OPENGL_UI_EXPORT

#define OpenGLUIAPI __declspec(dllexport)

#else

#define OpenGLUIAPI __declspec(dllimport)

#endif // OPENGL_UI_EXPORT





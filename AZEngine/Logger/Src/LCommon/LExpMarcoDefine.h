#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef LOGGER_EXPORT

#define LogerDLLAPI __declspec(dllexport)

#else

#define LogerDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT



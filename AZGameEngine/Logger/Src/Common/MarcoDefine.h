#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef LOGGER_EXPORT

#define LogerAPI __declspec(dllexport)

#else

#define LogerAPI __declspec(dllimport)

#endif // LOGGER_EXPORT

#ifdef STATIC_LIBRARY   //������̬��

#define LogerAPIST 

#else                   //������̬��

#define LogerAPIST extern "C" int

#endif // LOGGER_EXPORT



#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef COMMON_EXPORT_DLL

#define CommonDLLAPI __declspec(dllexport)

#else

#define CommonDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT

#ifdef COMMON_EXPORT_STATICLIB   //������̬��

#define CommonLibAPI 

#else                   //������̬��

#define CommonLibAPI //extern "C" int

#endif // LOGGER_EXPORT




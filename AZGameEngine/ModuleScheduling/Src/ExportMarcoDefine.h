#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef MDL_SCHEDULING_EXPORT_DLL

#define MdlScheduleDLLAPI __declspec(dllexport)

#else

#define MdlScheduleDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT

#ifdef MDL_SCHEDULING_EXPORT_STATICLIB   //������̬��

#define MdlScheduleLibAPI 

#else                   //������̬��

#define MdlScheduleLibAPI //extern "C" int

#endif // MDL_SCHEDULING_EXPORT_STATICLIB



#pragma once

//Common ģ��һ���ᶨ�� Common Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef COMMON_EXPORT_DLL

#define MdlCommonDLLAPI __declspec(dllexport)

#else

#define MdlCommonDLLAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





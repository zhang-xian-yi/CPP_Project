#pragma once

//Common ģ��һ���ᶨ�� Common Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef TEST_COMMON_EXPORT_DLL

#define TestCommonDLLAPI __declspec(dllexport)

#else

#define TestCommonDLLAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





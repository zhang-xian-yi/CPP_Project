#pragma once

//Common ģ��һ���ᶨ�� Common Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef SERIALIZATION_TOOL_NS_DLL

#define SerializationToolNSAPI __declspec(dllexport)

#else

#define SerializationToolNSAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





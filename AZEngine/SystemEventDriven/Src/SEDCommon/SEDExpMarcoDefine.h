#pragma once

//SystemEventDriven ģ��һ���ᶨ�� SysEventNS_Export Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef SysEventNS_Export

#define SysEventNSAPI __declspec(dllexport)

#else

#define SysEventNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



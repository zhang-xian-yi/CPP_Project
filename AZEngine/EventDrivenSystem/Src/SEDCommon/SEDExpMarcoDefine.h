#pragma once

//SystemEventDriven ģ��һ���ᶨ�� SysEventNS_Export Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef EventDrivenNS_Export

#define EventDrivenSysNSAPI __declspec(dllexport)

#else

#define EventDrivenSysNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



#pragma once

//SystemEventDriven ģ��һ���ᶨ�� SysEventNS_Export Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef EVENT_COMMON_NSExport

#define EventCMNNSAPI __declspec(dllexport)

#else

#define EventCMNNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



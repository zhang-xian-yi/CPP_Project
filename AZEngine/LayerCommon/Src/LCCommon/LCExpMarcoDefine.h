#pragma once

//LayerCommon ģ��һ���ᶨ�� LAYER_COMMON_NSExport Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef LAYER_COMMON_NSExport

#define LayerCommonNSAPI __declspec(dllexport)

#else

#define LayerCommonNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



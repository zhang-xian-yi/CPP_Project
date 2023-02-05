#pragma once

//SystemEventDriven 模块一定会定义 SysEventNS_Export 为导出 
//其余模块不会定义该宏就为导入
#ifdef EVENT_COMMON_NSExport

#define EventCMNNSAPI __declspec(dllexport)

#else

#define EventCMNNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



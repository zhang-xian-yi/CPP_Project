#pragma once

//SystemEventDriven 模块一定会定义 SysEventNS_Export 为导出 
//其余模块不会定义该宏就为导入
#ifdef SysEventNS_Export

#define SysEventNSAPI __declspec(dllexport)

#else

#define SysEventNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



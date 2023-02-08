#pragma once

//LayerCommon 模块一定会定义 LAYER_COMMON_NSExport 为导出 
//其余模块不会定义该宏就为导入
#ifdef LAYER_COMMON_NSExport

#define LayerCommonNSAPI __declspec(dllexport)

#else

#define LayerCommonNSAPI __declspec(dllimport)

#endif // SysEventNS_Export



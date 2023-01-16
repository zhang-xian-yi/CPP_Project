#pragma once

//Common 模块一定会定义 Common 为导出 
//其余模块不会定义该宏就为导入
#ifdef COMMON_EXPORT_DLL

#define MdlCommonDLLAPI __declspec(dllexport)

#else

#define MdlCommonDLLAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





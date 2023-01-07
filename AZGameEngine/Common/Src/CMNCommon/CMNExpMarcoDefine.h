#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef COMMON_EXPORT_DLL

#define CommonDLLAPI __declspec(dllexport)

#else

#define CommonDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT

#ifdef COMMON_EXPORT_STATICLIB   //导出静态库

#define CommonLibAPI 

#else                   //导出动态库

#define CommonLibAPI //extern "C" int

#endif // LOGGER_EXPORT




#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef LOGGER_EXPORT

#define LogerAPI __declspec(dllexport)

#else

#define LogerAPI __declspec(dllimport)

#endif // LOGGER_EXPORT

#ifdef STATIC_LIBRARY   //导出静态库

#define LogerAPIST 

#else                   //导出动态库

#define LogerAPIST extern "C" int

#endif // LOGGER_EXPORT



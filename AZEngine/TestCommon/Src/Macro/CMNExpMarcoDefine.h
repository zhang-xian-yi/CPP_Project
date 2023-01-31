#pragma once

//Common 模块一定会定义 Common 为导出 
//其余模块不会定义该宏就为导入
#ifdef TEST_COMMON_EXPORT_DLL

#define TestCommonDLLAPI __declspec(dllexport)

#else

#define TestCommonDLLAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





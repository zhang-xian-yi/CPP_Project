#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef MDL_SCHEDULING_EXPORT_DLL

#define MdlScheduleDLLAPI __declspec(dllexport)

#else

#define MdlScheduleDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT



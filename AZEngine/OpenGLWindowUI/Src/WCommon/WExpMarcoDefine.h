#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef WINDOW_NS_EXPORT

#define WindowsNSDLLAPI __declspec(dllexport)

#else

#define WindowsNSDLLAPI __declspec(dllimport)

#endif // OPENGL_UI_EXPORT





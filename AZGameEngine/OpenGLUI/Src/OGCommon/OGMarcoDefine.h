#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef OPENGL_UI_EXPORT

#define OpenGLUIAPI __declspec(dllexport)

#else

#define OpenGLUIAPI __declspec(dllimport)

#endif // OPENGL_UI_EXPORT





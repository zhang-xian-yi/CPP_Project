#pragma once

//Logger 模块一定会定义 LOGGER_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef GAME_ENGINE_EXPORT

#define GameEngineDLLAPI __declspec(dllexport)

#else

#define GameEngineDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT




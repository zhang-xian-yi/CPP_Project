#pragma once

//Common 模块一定会定义 Common 为导出 
//其余模块不会定义该宏就为导入
#ifdef SERIALIZATION_TOOL_NS_DLL

#define SerializationToolNSAPI __declspec(dllexport)

#else

#define SerializationToolNSAPI __declspec(dllimport)

#endif // COMMON_EXPORT_DLL





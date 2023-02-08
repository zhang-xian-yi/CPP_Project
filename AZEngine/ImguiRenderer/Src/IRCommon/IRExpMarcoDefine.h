#pragma once

//ImguiRenderer 模块一定会定义 IMGUI_RENDERER_NS_Export 为导出 
//其余模块不会定义该宏就为导入
#ifdef IMGUI_RENDERER_NS_Export

#define ImguiRendererNSAPI __declspec(dllexport)

#else

#define ImguiRendererNSAPI __declspec(dllimport)

#endif // IMGUI_RENDERER_NS_Export



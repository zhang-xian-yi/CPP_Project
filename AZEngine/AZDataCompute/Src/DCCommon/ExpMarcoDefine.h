#pragma once

//AZDataCompute 模块一定会定义 DATA_COMPUTE_EXPORT 为导出 
//其余模块不会定义该宏就为导入
#ifdef DATA_COMPUTE_EXPORT

#define DataComputeNSDLLAPI __declspec(dllexport)

#else

#define DataComputeNSDLLAPI __declspec(dllimport)

#endif // DATA_COMPUTE_EXPORT




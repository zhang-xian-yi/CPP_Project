#pragma once

//AZDataCompute ģ��һ���ᶨ�� DATA_COMPUTE_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef DATA_COMPUTE_EXPORT

#define DataComputeNSDLLAPI __declspec(dllexport)

#else

#define DataComputeNSDLLAPI __declspec(dllimport)

#endif // DATA_COMPUTE_EXPORT




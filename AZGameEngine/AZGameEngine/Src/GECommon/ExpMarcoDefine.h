#pragma once

//Logger ģ��һ���ᶨ�� LOGGER_EXPORT Ϊ���� 
//����ģ�鲻�ᶨ��ú��Ϊ����
#ifdef GAME_ENGINE_EXPORT

#define GameEngineDLLAPI __declspec(dllexport)

#else

#define GameEngineDLLAPI __declspec(dllimport)

#endif // LOGGER_EXPORT




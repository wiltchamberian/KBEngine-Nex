#pragma once

// =========================================
// 平台判断
// =========================================

#if defined(__UNREAL__) || defined(UE_BUILD_DEBUG) || defined(UE_SERVER) || defined(UE_CLIENT)
    #define KBE_PLATFORM_UE 1
#elif defined(CC_TARGET_PLATFORM)
    #define KBE_PLATFORM_COCOS 1
#else
    #define KBE_PLATFORM_CPP 1
#endif

// =========================================
// UE 版本
// =========================================
#if KBE_PLATFORM_UE

#include "CoreMinimal.h"
#include "Misc/OutputDevice.h"
#include "Engine/Engine.h"


#define __KBENGINE_FORMAT(Buffer, BufferSize, Format, ...) \
    snprintf(Buffer, BufferSize, Format, ##__VA_ARGS__);

#define INFO_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), Format, ##__VA_ARGS__); \
    UE_LOG(LogTemp, Log, TEXT("%s"), UTF8_TO_TCHAR(__buf)); \
}

#define DEBUG_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), "[DEBUG] " Format, ##__VA_ARGS__); \
    UE_LOG(LogTemp, Log, TEXT("%s"), UTF8_TO_TCHAR(__buf)); \
}

#define WARNING_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), "[WARNING] " Format, ##__VA_ARGS__); \
    UE_LOG(LogTemp, Warning, TEXT("%s"), UTF8_TO_TCHAR(__buf)); \
}

#define ERROR_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), "[ERROR] " Format, ##__VA_ARGS__); \
    UE_LOG(LogTemp, Error, TEXT("%s"), UTF8_TO_TCHAR(__buf)); \
}

#define SCREEN_WARNING_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), "[WARNING] " Format, ##__VA_ARGS__); \
    const FString Msg = UTF8_TO_TCHAR(__buf); \
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg); \
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Msg); \
}

#define SCREEN_ERROR_MSG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), "[ERROR] " Format, ##__VA_ARGS__); \
    const FString Msg = UTF8_TO_TCHAR(__buf); \
    UE_LOG(LogTemp, Error, TEXT("%s"), *Msg); \
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, Msg); \
}

#define SCREENDEBUG(Format, ...) \
{ \
    char __buf[2048]; \
    __KBENGINE_FORMAT(__buf, sizeof(__buf), Format, ##__VA_ARGS__); \
    const FString Msg = UTF8_TO_TCHAR(__buf); \
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, Msg); \
}

#endif // UE



// =========================================
// Cocos2d-x 版本
// =========================================
#if KBE_PLATFORM_COCOS

#include "base/CCConsole.h"
#include "base/CCDirector.h"
#include "base/CCScheduler.h"
#include <string>

#define INFO_MSG(Format, ...) \
{ \
    cocos2d::log("[INFO] " Format, ##__VA_ARGS__); \
}

#define DEBUG_MSG(Format, ...) \
{ \
    cocos2d::log("[DEBUG] " Format, ##__VA_ARGS__); \
}

#define WARNING_MSG(Format, ...) \
{ \
    cocos2d::log("[WARNING] " Format, ##__VA_ARGS__); \
}

#define ERROR_MSG(Format, ...) \
{ \
    cocos2d::log("[ERROR] " Format, ##__VA_ARGS__); \
}

#define SCREEN_WARNING_MSG(Format, ...) \
{ \
    cocos2d::log("[WARNING] " Format, ##__VA_ARGS__); \
    auto msg = cocos2d::StringUtils::format("WARNING: " Format, ##__VA_ARGS__); \
    cocos2d::MessageBox(msg.c_str(), "Warning"); \
}

#define SCREEN_ERROR_MSG(Format, ...) \
{ \
    cocos2d::log("[ERROR] " Format, ##__VA_ARGS__); \
    auto msg = cocos2d::StringUtils::format("ERROR: " Format, ##__VA_ARGS__); \
    cocos2d::MessageBox(msg.c_str(), "Error"); \
}

#define SCREENDEBUG(Format, ...) \
{ \
    cocos2d::log("[SCREEN] " Format, ##__VA_ARGS__); \
}

#endif // Cocos



// =========================================
// 原生 C++ 版本
// =========================================
#if KBE_PLATFORM_CPP

#include <cstdio>
#include <cstdarg>
//
// inline void kbe_printf(const char* prefix, const char* fmt, ...) {
//     char buffer[2048];
//     va_list args;
//     va_start(args, fmt);
//     vsnprintf(buffer, sizeof(buffer), fmt, args);
//     va_end(args);
//
// #ifdef _WIN32
//     // 转 GBK 输出
//     int size_needed = MultiByteToWideChar(CP_UTF8, 0, buffer, -1, nullptr, 0);
//     std::wstring wbuf(size_needed, L'\0');
//     MultiByteToWideChar(CP_UTF8, 0, buffer, -1, &wbuf[0], size_needed);
//
//     // 输出到控制台
//     DWORD written;
//     WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), wbuf.c_str(), (DWORD)wbuf.size()-1, &written, nullptr);
//     WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, &written, nullptr);
// #else
//     printf("%s %s\n", prefix, buffer);
// #endif
// }

inline void kbe_printf(const char* prefix, const char* fmt, ...)
{
    char buffer[2048];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    printf("%s %s\n", prefix, buffer);
}

#define INFO_MSG(Format, ...) \
    kbe_printf("[INFO]", Format, ##__VA_ARGS__);

#define DEBUG_MSG(Format, ...) \
    kbe_printf("[DEBUG]", Format, ##__VA_ARGS__);

#define WARNING_MSG(Format, ...) \
    kbe_printf("[WARNING]", Format, ##__VA_ARGS__);

#define ERROR_MSG(Format, ...) \
    kbe_printf("[ERROR]", Format, ##__VA_ARGS__);

#define SCREEN_WARNING_MSG(Format, ...) \
    kbe_printf("[WARNING][SCREEN]", Format, ##__VA_ARGS__);

#define SCREEN_ERROR_MSG(Format, ...) \
    kbe_printf("[ERROR][SCREEN]", Format, ##__VA_ARGS__);

#define SCREENDEBUG(Format, ...) \
    kbe_printf("[SCREEN]", Format, ##__VA_ARGS__);

#endif // 原生 C++


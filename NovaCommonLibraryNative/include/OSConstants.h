//
// Created by Jonathan on 8/25/2022.
//

#ifndef NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H
#define NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

#include <cstddef> //Includes std::size_t

//Possible OS (Platforms) values: NCL_OS_WINDOWS, NCL_OS_POSIX_WINDOWS, NCL_OS_ANDROID, NCL_OS_LINUX, NCL_OS_UNIX,
// NCL_OS_BSD, NCL_OS_IOS, NCL_OS_MACOS

//Possible instruction set architecture values: NCL_ARCH_X64, NCL_ARCH_X86, NCL_ARCH_ARM64, NCL_ARCH_ARM32

//Possible instruction set architecture platform values: NCL_ARCH_FAM_INTEL_AMD, NCL_ARCH_FAM_ARM

namespace Ncl
{

//Determine the current OS (Platform) being built for
#if defined(_WIN32) || defined(_WIN64) //Windows
    /**
     * Determines that the target platform is Windows
     */
    #define NCL_OS_WINDOWS

    /**
     * The name of the current platform.
     */
    constexpr const char PLATFORM_NAME[] = "Windows";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__CYGWIN__) //POSIX on Windows
    /**
     * Determines that the target platform is POSIX for Windows
     */
    #define NCL_OS_POSIX_WINDOWS
    /**
     * Determines that the target platform is UNIX
     */
    #define NCL_OS_UNIX

    /**
     * The name of the current platform.
     */
    constexpr const char PLATFORM_NAME[] = "Windows";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__ANDROID__) //Android; Must come before Linux as this implies Linux also
    /**
     * Determines that the target platform is Android
     */
    #define NCL_OS_ANDROID

    /**
     * The name of the current platform.
     */
    constexpr const char PLATFORM_NAME[] = "Android";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__linux__) // Linux
    /**
     * Determines that the target platform is Linux
     */
    #define NCL_OS_LINUX

    /**
     * The name of the current platform.
     */
    constexpr const char PLATFORM_NAME[] = "Linux";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__unix__) || !defined(__APPLE__) && !defined(__MACH__) // UNIX (and maybe BSD)
    /**
     * Determines that the target platform is UNIX
     */
    #define NCL_OS_UNIX

    //Check if platform is also BSD
    #include <sys/param.h>
    #if defined(BSD)
        /**
         * Determines that the target platform is BSD
         */
        #define NCL_OS_BSD // FreeBSD, NetBSD, OpenBSD, DragonFly BSD

        /**
         * The name of the current platform.
         */
        constexpr const char PLATFORM_NAME[] = "BSD";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #else
        /**
         * The name of the current platform.
         */
        constexpr const char PLATFORM_NAME[] = "UNIX";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #endif
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)

    #include <TargetConditionals.h>

    #if TARGET_IPHONE_SIMULATOR == 1
        /**
         * Determines that the target platform is iOS
         */
        #define NCL_OS_IOS // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        /**
         * Determines that the target platform is iOS
         */
        #define NCL_OS_IOS // Apple iOS
    #elif TARGET_OS_MAC == 1
        /**
         * Determines that the target platform is macOS
         */
        #define NCL_OS_MACOS // Apple OSX
    #else
        #error "Unsupported target Apple platform"
    #endif

    #ifdef NCL_OS_IOS
        /**
         * The name of the current platform.
         */
        constexpr const char PLATFORM_NAME[] = "iOS";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #elif defined(NCL_OS_MACOS)
        /**
         * The name of the current platform.
         */
        constexpr const char PLATFORM_NAME[]    = "macOS";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #endif
#else
    #error "Unsupported target OS platform"
#endif

//Determine the instruction set architecture
#ifdef NCL_OS_WINDOWS
    #if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
        /**
         * Determines that the target architecture is x64 (64-bit)
         */
        #define NCL_ARCH_X64
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define NCL_ARCH_FAM_INTEL_AMD
    #elif defined(_WIN32) || defined(__i386__) || defined(_M_IX86)
        /**
         * Determines that the target architecture is x86 (32-bit)
         */
        #define NCL_ARCH_X86
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define NCL_ARCH_FAM_INTEL_AMD
    #elif defined(_M_ARM64) || defined(__aarch64__)
        /**
         * Determines that the target architecture is ARM64 (64-bit)
         */
        #define NCL_ARCH_ARM64
        /**
         * Determines that the target architecture platform is ARM
         */
        #define NCL_ARCH_FAM_ARM
    #elif defined(_M_ARM) || defined(__arm__)
        /**
         * Determines that the target architecture is ARM32 (32-bit)
         */
        #define NCL_ARCH_ARM32
        /**
         * Determines that the target architecture platform is ARM
         */
        #define NCL_ARCH_FAM_ARM
    #else
        #error "Unsupported instruction set architecture"
    #endif
#else
    #if defined(__x86_64__) || defined(_M_X64)
        /**
         * Determines that the target architecture is x64 (64-bit)
         */
        #define NCL_ARCH_X64
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define NCL_ARCH_FAM_INTEL_AMD
    #elif defined(__i386__) || defined(_M_IX86)
        /**
         * Determines that the target architecture is x86 (32-bit)
         */
        #define NCL_ARCH_X86
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define NCL_ARCH_FAM_INTEL_AMD
    #elif defined(__aarch64__) || defined(_M_ARM64)
        /**
         * Determines that the target architecture is ARM64 (64-bit)
         */
        #define NCL_ARCH_ARM64
        /**
         * Determines that the target architecture platform is ARM
         */
        #define NCL_ARCH_FAM_ARM
    #elif defined(__arm__) || defined(_M_ARM)
        /**
         * Determines that the target architecture is ARM32 (32-bit)
         */
        #define NCL_ARCH_ARM32
        /**
         * Determines that the target architecture platform is ARM
         */
        #define NCL_ARCH_FAM_ARM
    #else
        #error "Unsupported instruction set architecture"
    #endif
#endif

#pragma clang diagnostic pop

}
        
#endif //NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H
        
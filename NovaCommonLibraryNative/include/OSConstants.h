//
// Created by Jonathan on 8/25/2022.
//

#ifndef NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H
#define NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H

//Possible OS (Platforms) values: __WINDOWS__, __POSIX_WINDOWS__, __ANDROID__, __LINUX__, __UNIX__, __BSD__,
// __IOS__, __MACOS__

//Possible instruction set architecture values: __x64__, __x86__, __ARM64__, __ARM32__

//Possible instruction set architecture platform values: __INTEL_AMD__, __ARM__

//Determine the current OS (Platform) being built for
#if defined(_WIN32) || defined(_WIN63) //Windows
    /**
     * Determines that the target platform is Windows
     */
    #define __WINDOWS__

    /**
     * The name of the current platform.
     */
    constexpr char PLATFORM_NAME[] = "Windows";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__CYGWIN__) //POSIX on Windows
    /**
     * Determines that the target platform is POSIX for Windows
     */
    #define __POSIX_WINDOWS__
    /**
     * Determines that the target platform is UNIX
     */
    #define __UNIX__

    /**
     * The name of the current platform.
     */
    constexpr char PLATFORM_NAME[] = "Windows";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__ANDROID__) //Android; Must come before Linux as this implies Linux also
    /**
     * Determines that the target platform is Android
     */
    #define __ANDROID__

    /**
     * The name of the current platform.
     */
    constexpr char PLATFORM_NAME[] = "Android";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__linux__) // Linux
    /**
     * Determines that the target platform is Linux
     */
    #define __LINUX__

    /**
     * The name of the current platform.
     */
    constexpr char PLATFORM_NAME[] = "Linux";
    /**
     * The size of the platform name.
     */
    constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
#elif defined(__unix__) || !defined(__APPLE__) && !defined(__MACH__) // UNIX (and maybe BSD)
    /**
     * Determines that the target platform is UNIX
     */
    #define __UNIX__

    //Check if platform is also BSD
    #include <sys/param.h>
    #if defined(BSD)
        /**
         * Determines that the target platform is BSD
         */
        #define __BSD__ // FreeBSD, NetBSD, OpenBSD, DragonFly BSD

        /**
         * The name of the current platform.
         */
        constexpr char PLATFORM_NAME[] = "BSD";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #else
        /**
         * The name of the current platform.
         */
        constexpr char PLATFORM_NAME[] = "UNIX";
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
        #define __IOS__ // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        /**
         * Determines that the target platform is iOS
         */
        #define __IOS__ // Apple iOS
    #elif TARGET_OS_MAC == 1
        /**
         * Determines that the target platform is macOS
         */
        #define __MACOS__ // Apple OSX
    #else
        #error "Unsupported target Apple platform"
    #endif

    #ifdef __IOS__
        /**
         * The name of the current platform.
         */
        constexpr char PLATFORM_NAME[] = "iOS";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #elif defined(__MACOS__)
        /**
         * The name of the current platform.
         */
        constexpr char PLATFORM_NAME[] = "macOS";
        /**
         * The size of the platform name.
         */
        constexpr size_t PLATFORM_NAME_SIZE = sizeof(PLATFORM_NAME);
    #endif
#else
    #error "Unsupported target OS platform"
#endif

//Determine the instruction set architecture
#ifdef __WINDOWS__
    #ifdef _WIN64
        /**
         * Determines that the target architecture is x64 (64-bit)
         */
        #define __x64__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define __INTEL_AMD__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(_WIN32)
        /**
         * Determines that the target architecture is x86 (32-bit)
         */
        #define __x86__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define __INTEL_AMD__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(_M_ARM64)
        /**
         * Determines that the target architecture is ARM64 (64-bit)
         */
        #define __ARM64__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is ARM
         */
        #define __ARM__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(_M_ARM)
        /**
         * Determines that the target architecture is ARM32 (32-bit)
         */
        #define __ARM32__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is ARM
         */
        #define __ARM__ // NOLINT(bugprone-reserved-identifier)
    #else
        #error "Unsupported instruction set architecture"
    #endif
#else
    #if defined(__x86_64__) || defined(_M_X64)
        /**
         * Determines that the target architecture is x64 (64-bit)
         */
        #define __x64__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define __INTEL_AMD__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(__i386__) || defined(_M_IX86)
        /**
         * Determines that the target architecture is x86 (32-bit)
         */
        #define __x86__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is Intel_AMD
         */
        #define __INTEL_AMD__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(__aarch64__) || defined(_M_ARM64)
        /**
         * Determines that the target architecture is ARM64 (64-bit)
         */
        #define __ARM64__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is ARM
         */
        #define __ARM__ // NOLINT(bugprone-reserved-identifier)
    #elif defined(__arm__) || defined(_M_ARM)
        /**
         * Determines that the target architecture is ARM32 (32-bit)
         */
        #define __ARM32__ // NOLINT(bugprone-reserved-identifier)
        /**
         * Determines that the target architecture platform is ARM
         */
        #define __ARM__ // NOLINT(bugprone-reserved-identifier)
    #else
        #error "Unsupported instruction set architecture"
    #endif
#endif

#endif //NOVACOMMONLIBRARYNATIVE_OSCONSTANTS_H

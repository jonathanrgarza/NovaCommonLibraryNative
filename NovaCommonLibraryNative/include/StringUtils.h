//
// Created by Jonathan on 8/29/22.
//

#ifndef NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H
#define NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H

namespace NCL
{

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

#if defined(_WIN32) || defined(_WIN64) //Windows

    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\r\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#elif defined(__CYGWIN__) //POSIX on Windows

    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#elif defined(__ANDROID__) //Android; Must come before Linux as this implies Linux also

    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#elif defined(__linux__) // Linux

    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#elif defined(__unix__) || !defined(__APPLE__) && !defined(__MACH__) // UNIX (and maybe BSD)

    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)

#include <TargetConditionals.h>
#include <cstdlib>
#include <string>

#if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
    //TODO Confirm iPhone OS new line character for sure
    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif TARGET_OS_MAC == 1
    /**
     * The new line character(s) for the platform.
     */
    constexpr char   NEWLINE[]    = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#else
#warning "Unsupported target Apple platform for New Line array, using default value"
    
    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#endif

#else

#warning "Unsupported platform for New Line array, using default value"
    /**
     * The new line character(s) for the platform.
     */
    constexpr char NEWLINE[] = "\n";
    /**
     * The size of the new line character(s).
     */
    constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);

#endif

    void strTrimLeft(char *str, size_t size);

    void strTrimRight(char *str, size_t size);

    void strTrim(char *str, size_t size);

    void stringTrimLeft(std::string str);

    void stringTrimRight(std::string str);

    void stringTrim(std::string str);


#pragma clang diagnostic pop

}

#endif //NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H
        
//
// Created by Jonathan on 8/30/22.
//

#ifndef NOVACOMMONLIBRARYNATIVE_MACROS_H
#define NOVACOMMONLIBRARYNATIVE_MACROS_H

//Generate Compiler Marco
#ifdef _MSVC_LANG
#define NCL_MSVC 
#elif defined(__clang__)
#define NCL_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
#define NCL_GCC
#endif

//Generate Lang Version Macro
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 199711L) || __cplusplus >= 199711L)
//C++98
#define NCL_LANG98 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 1998L
#endif

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201103L) || __cplusplus >= 201103L)
//C++11
#define NCL_LANG11 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 2011L
#endif

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201402L) || __cplusplus >= 201402L)
//C++14
#define NCL_LANG14 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 2014L
#endif

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
//C++17
#define NCL_LANG17 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 2017L
#endif

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 202002L) || __cplusplus >= 202002L)
//C++20
#define NCL_LANG20 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 2020L
#endif

#if ((defined(_MSVC_LANG) && _MSVC_LANG > 202002L && _MSVC_LANG < 202501L) || \
    (__cplusplus > 202002L && __cplusplus < 202501L))
//C++23
#define NCL_LANG23 1
#undef NCL_LANG_VERSION
#define NCL_LANG_VERSION 2023L
#endif

//Check for nodiscard support
#ifdef NCL_LANG17
#define NCL_NODISCARD [[nodiscard]]
#else
    #if defined(_MSVC_LANG) && _MSVC_LANG >= 1700L
    #define NCL_NODISCARD _Check_return_
    #elif defined(NCL_CLANG) || defined(NCL_GCC) 
    #define NCL_NODISCARD __attribute__((warn_unused_result))
    #else
    #define NCL_NODISCARD 
    #endif
#endif

#endif //NOVACOMMONLIBRARYNATIVE_MACROS_H

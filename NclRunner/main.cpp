//
// Created by Jonathan on 7/8/22.
//

#include <iostream>
#include "Library.h"
#include "StringUtils.h"

auto main() -> int
{
    std::cout << "Ncl Runner" << std::endl;
    hello();
    
    NCL::CString test(3);
    test.copy("hello", sizeof ("hello"), true);
    
    test.isEmpty();
    
    std::cout << "Before copy nullptr: " << test << " (" << test.size() << ")" << std::endl;

    test.copy(nullptr, 0, true);

    std::cout << "After copy nullptr: " << test << std::endl;

    std::string testStr = "    test  \t   ";
    NCL::stringTrim(testStr);
    std::cout << "Test Str:" << testStr << std::endl;

    std::string testStr2 = "   test";
    NCL::stringTrim(testStr2);
    std::cout << "Test Str2:" << testStr2 << std::endl;

    std::string testStr3 = "test   ";
    NCL::stringTrim(testStr3);
    std::cout << "Test Str3:" << testStr3 << std::endl;

    std::string testStr4 = "test\t";
    NCL::stringTrim(testStr4);
    std::cout << "Test Str4:" << testStr4 << std::endl;

    std::string testStr5 = "test";
    NCL::stringTrimRight(testStr5);
    std::cout << "Test Str5:" << testStr5 << std::endl;
    
    return 0;
}
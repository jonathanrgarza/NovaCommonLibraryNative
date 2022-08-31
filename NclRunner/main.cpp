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
    
    return 0;
}
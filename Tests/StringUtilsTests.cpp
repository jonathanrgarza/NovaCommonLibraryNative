
//
// Created by Jonathan on 9/6/2022.
//

#pragma warning (push)
#pragma warning (disable : 4068 ) //Disable unknown paragmas
#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

#include <catch2/catch_test_macros.hpp>

#include "StringUtils.h"

TEST_CASE( "Null-Terminated String Results In True", "[strIsNullTerminated]" )
{
    constexpr char text[] = "hello";
    REQUIRE(Ncl::strIsNullTerminated(text, sizeof(text)) == true);
}

TEST_CASE( "Non-Null-Terminated String Results In False", "[strIsNullTerminated]" )
{
    char text[] = "hello";
    text[5] = ' ';
    REQUIRE(Ncl::strIsNullTerminated(text, sizeof(text)) == false);
}

#pragma clang diagnostic pop
#pragma warning (pop)
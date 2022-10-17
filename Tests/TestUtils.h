//
// Created by Jonathan on 9/6/2022.
//

#ifndef NOVACOMMONLIBRARYNATIVE_TESTUTILS_H
#define NOVACOMMONLIBRARYNATIVE_TESTUTILS_H

#include <string>
#include <cstring>
#include <memory>

template<std::size_t N, std::size_t O>
auto strEquals(const char(&str)[N], const char(&other)[O]) -> bool // NOLINT(modernize-avoid-c-arrays)
{
	size_t minSize = std::min(N, O);
	return strncmp(str, other, minSize) == 0;
};

auto strEquals(const char* str, size_t strSize, const char* other, size_t otherSize) -> bool // NOLINT(modernize-avoid-c-arrays)
{
	size_t minSize = std::min(strSize, otherSize);
	return strncmp(str, other, minSize) == 0;
};

#define STR_EQUAL_LIT_CHECK(expected_, actual_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  CHECK(strEquals(actual_, expected_));

#define STR_EQUAL_LIT_REQUIRE(expected_, actual_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  REQUIRE(strEquals(expected_, actual_));

#define STR_NOT_EQUAL_LIT_CHECK(expected_, actual_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  CHECK(!strEquals(actual_, expected_));

#define STR_NOT_EQUAL_LIT_REQUIRE(expected_, actual_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  REQUIRE(!strEquals(expected_, actual_));

#define STR_EQUAL_CHECK(expected_, expectedSize_, actual_, actualSize_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  CHECK(strEquals(actual_, actualSize_, expected_, expectedSize_));

#define STR_EQUAL_REQUIRE(expected_, expectedSize_, actual_, actualSize_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  REQUIRE(strEquals(actual_, actualSize_, expected_, expectedSize_));

#define STR_NOT_EQUAL_CHECK(expected_, expectedSize_, actual_, actualSize_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  CHECK(!strEquals(actual_, actualSize_, expected_, expectedSize_));

#define STR_NOT_EQUAL_REQUIRE(expected_, expectedSize_, actual_, actualSize_) \
  INFO( "expected = " << '"' << (expected_) << '"');  \
  INFO( "actual   = " << '"' << (actual_)   << '"');  \
  REQUIRE(!strEquals(actual_, actualSize_, expected_, expectedSize_));

#endif //NOVACOMMONLIBRARYNATIVE_TESTUTILS_H

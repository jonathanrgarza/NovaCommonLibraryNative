
//
// Created by Jonathan on 9/6/2022.
//

#pragma warning (push)
#pragma warning (disable : 4068 ) //Disable unknown paragmas
#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

#include "TestUtils.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "StringUtils.h"

TEST_CASE( "Null-Terminated string results in true", "[strIsNullTerminated]" )
{
	//Arrange
    constexpr char text[] = "hello";
	//Act
	//Assert
    REQUIRE(Ncl::strIsNullTerminated(text, sizeof(text)) == true);
}

TEST_CASE( "Non-Null-Terminated string results in false", "[strIsNullTerminated]" )
{
	//Arrange
    char text[] = "hello";
    text[5] = ' ';
	//Act
	//Assert
    REQUIRE(Ncl::strIsNullTerminated(text, sizeof(text)) == false);
}

TEST_CASE( "Null-Terminated string results in no throw", "[strEnsureNullTerminated]" )
{
	//Arrange
	constexpr char text[] = "hello";
	//Act
	//Assert
	REQUIRE_NOTHROW(Ncl::strEnsureNullTerminated(text, sizeof(text)));
}

TEST_CASE( "Non-Null-Terminated string results in throw", "[strEnsureNullTerminated]" )
{
	//Arrange
	char text[] = "hello";
	text[5] = ' ';
	//Act
	//Assert
	REQUIRE_THROWS_AS(Ncl::strEnsureNullTerminated(text, sizeof(text)), std::invalid_argument);
}

TEST_CASE( "String with beginning spaces has it removed", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "    test ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning tabs has it removed", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "\t\t\ttest ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning newlines has it removed", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "\n\n\ntest ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "    \t\n    ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "test ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "Null string returns the same", "[strTrimLeft]" )
{
	//Arrange
	constexpr char* expected = nullptr;
	char* actual = nullptr;

	//Act
	Ncl::strTrimLeft(actual, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "String with ending spaces has it removed", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test    ";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with ending tabs has it removed", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test\t\t\t\t";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with ending newlines has it removed", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test\n\n\n";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "        ";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "Null string returns the same", "[strTrimRight]" )
{
	//Arrange
	constexpr char* expected = nullptr;
	char* actual = nullptr;

	//Act
	Ncl::strTrimRight(actual, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "String with beginning and ending spaces has it removed", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "  test test   ";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning and ending tabs has it removed", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "\t\t test test\t\t\t\t";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning and ending newlines has it removed", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "\n\n test test\n\n\n";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "        ";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "test test";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_LIT_REQUIRE(expected, actual);
}

TEST_CASE( "Null string returns the same", "[strTrim]" )
{
	//Arrange
	constexpr char* expected = nullptr;
	char* actual = nullptr;

	//Act
	Ncl::strTrim(actual, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string get appended", "[stringAppend]" )
{
	//Arrange
	std::string expected = "test appended";
	std::string actual = "test";

	//Act
	Ncl::stringAppend(actual, " appended");

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string with text after null-character get appended", "[stringAppend]" )
{
	//Arrange
	std::string expected = "test appended";
	std::string actual = "test";

	//Act
	Ncl::stringAppend(actual, " appended\0test");

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string get appended, manual size", "[stringAppend]" )
{
	//Arrange
	std::string expected = "test appended";
	std::string actual = "test";
	const char appendStr[] = " appended\0test";

	//Act
	Ncl::stringAppend(actual, appendStr, sizeof(appendStr));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string with text after null-character get appended, manual size", "[stringAppend]" )
{
	//Arrange
	std::string expected = "test appended";
	std::string actual = "test";
	const char appendStr[] = " appended";

	//Act
	Ncl::stringAppend(actual, appendStr, sizeof(appendStr));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal c-strings returns true", "[strEquals]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test";

	//Act
	bool actual = Ncl::strEquals(compareStr, sizeof(compareStr),
								 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal c-strings returns false", "[strEquals]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = " test";

	//Act
	bool actual = Ncl::strEquals(compareStr, sizeof(compareStr),
								 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal c-strings returns true", "[strEqualsIc]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test";

	//Act
	bool actual = Ncl::strEqualsIc(compareStr, sizeof(compareStr),
								 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal c-strings returns false", "[strEqualsIc]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = "testt";

	//Act
	bool actual = Ncl::strEqualsIc(compareStr, sizeof(compareStr),
								   compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with letter case difference returns true", "[strEqualsIc]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "TEST";

	//Act
	bool actual = Ncl::strEqualsIc(compareStr, sizeof(compareStr),
								 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with whitespace difference returns false", "[strEqualsIc]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = "test ";

	//Act
	bool actual = Ncl::strEqualsIc(compareStr, sizeof(compareStr),
								 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal c-strings returns true", "[strEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test";

	//Act
	bool actual = Ncl::strEqualsIws(compareStr, sizeof(compareStr),
								   compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal c-strings returns false", "[strEqualsIws]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = "test t";

	//Act
	bool actual = Ncl::strEqualsIws(compareStr, sizeof(compareStr),
									 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "empty c-string and whitespace c-string returns true", "[strEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "";
	const char compareStr2[] = "     \t\n   ";

	//Act
	bool actual = Ncl::strEqualsIws(compareStr, sizeof(compareStr),
									compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with letter case difference returns false", "[strEqualsIws]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = "TEST";

	//Act
	bool actual = Ncl::strEqualsIws(compareStr, sizeof(compareStr),
								   compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with whitespace difference returns true", "[strEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test ";

	//Act
	bool actual = Ncl::strEqualsIws(compareStr, sizeof(compareStr),
								   compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal c-strings returns true", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal c-strings returns false", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = false;
	const char compareStr[] = "test";
	const char compareStr2[] = "test t";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "empty c-string and whitespace c-string returns true", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "";
	const char compareStr2[] = "     \t\n   ";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with letter case difference returns true", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "TEST";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with whitespace difference returns true", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "test ";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-strings with whitespace and letter case differences returns true", "[strEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const char compareStr[] = "test";
	const char compareStr2[] = "TESt ";

	//Act
	bool actual = Ncl::strEqualsIcws(compareStr, sizeof(compareStr),
									 compareStr2, sizeof(compareStr2));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal strings returns true", "[stringEqualsIc]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test";

	//Act
	bool actual = Ncl::stringEqualsIc(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal strings returns false", "[stringEqualsIc]" )
{
	//Arrange
	const bool expected = false;
	const std::string compareStr = "test";
	const std::string compareStr2 = "testt";

	//Act
	bool actual = Ncl::stringEqualsIc(compareStr,compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with letter case difference returns true", "[stringEqualsIc]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "TEST";

	//Act
	bool actual = Ncl::stringEqualsIc(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with whitespace difference returns false", "[stringEqualsIc]" )
{
	//Arrange
	const bool expected = false;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test ";

	//Act
	bool actual = Ncl::stringEqualsIc(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal strings returns true", "[stringEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test";

	//Act
	bool actual = Ncl::stringEqualsIws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal strings returns false", "[stringEqualsIws]" )
{
	//Arrange
	const bool expected = false;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test t";

	//Act
	bool actual = Ncl::stringEqualsIws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "empty string and whitespace string returns true", "[stringEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr;
	const std::string compareStr2 = "     \t\n   ";

	//Act
	bool actual = Ncl::stringEqualsIws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with letter case difference returns false", "[stringEqualsIws]" )
{
	//Arrange
	const bool expected = false;
	const std::string compareStr = "test";
	const std::string compareStr2 = "TEST";

	//Act
	bool actual = Ncl::stringEqualsIws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with whitespace difference returns true", "[stringEqualsIws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test ";

	//Act
	bool actual = Ncl::stringEqualsIws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "equal strings returns true", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "not equal strings returns false", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = false;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test t";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "empty string and whitespace string returns true", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr;
	const std::string compareStr2 = "     \t\n   ";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with letter case difference returns true", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "TEST";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with whitespace difference returns true", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "test ";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "strings with whitespace and letter case differences returns true", "[stringEqualsIcws]" )
{
	//Arrange
	const bool expected = true;
	const std::string compareStr = "test";
	const std::string compareStr2 = "TESt ";

	//Act
	bool actual = Ncl::stringEqualsIcws(compareStr, compareStr2);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string with 1 character returns 1", "[strLength]" )
{
	//Arrange
	const size_t expected = 1;
	const char testStr[] = "t";

	//Act
	size_t actual = Ncl::strLength(testStr, sizeof(testStr));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string with 0 characters returns 0", "[strLength]" )
{
	//Arrange
	const size_t expected = 0;
	const char testStr[] = "";

	//Act
	size_t actual = Ncl::strLength(testStr, sizeof(testStr));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "c-string with 2 characters and no null-terminator returns 3", "[strLength]" )
{
	//Arrange
	const size_t expected = 3;
	char testStr[3] {};
	testStr[0] = '1';
	testStr[1] = '2';
	testStr[2] = '3';

	//Act
	size_t actual = Ncl::strLength(testStr, sizeof(testStr));

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "null c-string returns 0", "[strLength]" )
{
	//Arrange
	const size_t expected = 0;

	//Act
	size_t actual = Ncl::strLength(nullptr, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "src c-string of length 4 copies into dest buffer of size 5 and returns 4", "[strCopy]" )
{
	//Arrange
	const size_t expected = 4;
	char testStr[5] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCopy(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("test", testStr);
}

TEST_CASE( "src c-string of length 0 copies into dest buffer of size 5 and returns 0", "[strCopy]" )
{
	//Arrange
	const size_t expected = 0;
	char testStr[] = "test";
	const char srcStr[] = "";

	//Act
	size_t actual = Ncl::strCopy(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("", testStr);
}

TEST_CASE( "src c-string of length 4 copies into dest buffer of size 3 and returns 3", "[strCopy]" )
{
	//Arrange
	const size_t expected = 3;
	char testStr[3] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCopy(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("te", testStr);
}

TEST_CASE( "src c-string of length 5 copies 3 characters into dest buffer of size 5 and returns 3", "[strCopy]" )
{
	//Arrange
	const size_t expected = 3;
	char testStr[5] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCopy(testStr, sizeof(testStr), srcStr, sizeof(srcStr) - 2);

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("te", testStr);
}

TEST_CASE( "null c-string returns 0", "[strCopy]" )
{
	//Arrange
	const size_t expected = 0;

	//Act
	size_t actual = Ncl::strCopy(nullptr, 0, nullptr, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "src c-string of length 4 appends into dest buffer of size 5 and returns 4", "[strCat]" )
{
	//Arrange
	const size_t expected = 4;
	char testStr[5] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("test", testStr);
}

TEST_CASE( "src c-string of length 0 appends into dest buffer of size 5 and returns 0", "[strCat]" )
{
	//Arrange
	const size_t expected = 0;
	char testStr[] = "test";
	const char srcStr[] = "";

	//Act
	size_t actual = Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("test", testStr);
}

TEST_CASE( "src c-string of length 4 appends into dest buffer of size 3 and returns 3", "[strCat]" )
{
	//Arrange
	const size_t expected = 3;
	char testStr[3] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("te", testStr);
}

TEST_CASE( "src c-string of length 5 appends 3 characters into dest buffer of size 5 and returns 3", "[strCat]" )
{
	//Arrange
	const size_t expected = 3;
	char testStr[5] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr) - 2);

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("te", testStr);
}

TEST_CASE( "null c-string returns 0", "[strCat]" )
{
	//Arrange
	const size_t expected = 0;

	//Act
	size_t actual = Ncl::strCat(nullptr, 0, nullptr, 0);

	//Assert
	REQUIRE(expected == actual);
}

TEST_CASE( "two src c-string of length 4 appends into dest buffer of size 9 and append both", "[strCat]" )
{
	//Arrange
	const size_t expected = 8;
	char testStr[9] {};
	const char srcStr[] = "test";

	//Act
	size_t actual = Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr));
	actual += Ncl::strCat(testStr, sizeof(testStr), srcStr, sizeof(srcStr));

	//Assert
	REQUIRE(expected == actual);
	STR_EQUAL_LIT_REQUIRE("testtest", testStr);
}

TEST_CASE( "Instance is created with string content", "[CCString::cotr]" )
{
	//Arrange
    const size_t srcSize = sizeof("test");
	const char srcStr[] = "test";

	//Act
	const Ncl::CCString actual(srcStr, srcSize);

	//Assert
	STR_EQUAL_REQUIRE("test", srcSize, actual.str(), actual.size());
    REQUIRE(srcSize == actual.size());
    REQUIRE(srcSize - 1 == actual.length());
}

TEST_CASE( "Instance is created with NULL content", "[CCString::cotr]" )
{
    //Arrange
    //Act
    const Ncl::CCString actual(nullptr, 0);

    //Assert
    REQUIRE(true == actual.isNull());
    REQUIRE(false == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Instance is created with empty content", "[CCString::cotr]" )
{
    //Arrange
    const size_t srcSize = sizeof("");
    const char srcStr[] = "";

    //Act
    const Ncl::CCString actual(srcStr, srcSize);

    //Assert
    REQUIRE(false == actual.isNull());
    REQUIRE(true == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Exists and is set to null", "[CCString::Null]" )
{
    //Arrange
    //Act
    const Ncl::CCString actual = Ncl::CCString::Null;

    //Assert
    REQUIRE(true == actual.isNull());
    REQUIRE(false == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Exists and is set to an empty string", "[CCString::Empty]" )
{
    //Arrange
    //Act
    const Ncl::CCString actual = Ncl::CCString::Empty;

    //Assert
    REQUIRE(false == actual.isNull());
    REQUIRE(true == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Equal strings returns true", "[CCString::==]" )
{
    //Arrange
    const size_t srcSize = sizeof("test");
    const char srcStr1[] = "test";
    const char srcStr2[] = "test";

    //Act
    const Ncl::CCString instance1(srcStr1, srcSize);
    const Ncl::CCString instance2(srcStr2, srcSize);
    
    bool actual = instance1 == instance2;

    //Assert
    REQUIRE(true == actual);
}

TEST_CASE( "Not equal strings returns true", "[CCString::!=]" )
{
    //Arrange
    const size_t srcSize1 = sizeof("test");
    const size_t srcSize2 = sizeof("test2");
    const char srcStr1[] = "test";
    const char srcStr2[] = "test2";

    //Act
    const Ncl::CCString instance1(srcStr1, srcSize1);
    const Ncl::CCString instance2(srcStr2, srcSize2);

    bool actual = instance1 != instance2;

    //Assert
    REQUIRE(true == actual);
}

TEST_CASE( "Instance is created with string content", "[CString::cotr]" )
{
	//Arrange
	const size_t arraySize = 5;
	std::unique_ptr<char[]> srcStr(new char[arraySize]);
	Ncl::strCopy(srcStr.get(), arraySize, "test");

	//Act
	const Ncl::CString actual(srcStr.get(), arraySize);
    srcStr.release();
    
	//Assert
	STR_EQUAL_REQUIRE("test", arraySize, actual.str(), actual.size());
    REQUIRE(arraySize == actual.size());
    REQUIRE(arraySize - 1 == actual.length());
}

TEST_CASE( "Instance is created with NULL content", "[CString::cotr]" )
{
    //Arrange
    //Act
    const Ncl::CString actual(nullptr, 0);

    //Assert
    REQUIRE(true == actual.isNull());
    REQUIRE(false == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Instance is created with empty content", "[CString::cotr]" )
{
    //Arrange
    const size_t arraySize = 1;
    std::unique_ptr<char[]> srcStr(new char[arraySize]);
    Ncl::strCopy(srcStr.get(), arraySize, "");

    //Act
    const Ncl::CString actual(srcStr.get(), arraySize);
    srcStr.release();

    //Assert
    REQUIRE(false == actual.isNull());
    REQUIRE(true == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Exists and is set to null", "[CString::Null]" )
{
    //Arrange
    //Act
    const Ncl::CString actual = Ncl::CString::Null;

    //Assert
    REQUIRE(true == actual.isNull());
    REQUIRE(false == actual.isEmpty());
    REQUIRE(true == actual.isNullOrEmpty());
    REQUIRE(0 == actual.length());
}

TEST_CASE( "Equal strings return true", "[CString::==]" )
{
    //Arrange
    const size_t arraySize = 5;
    std::unique_ptr<char[]> srcStr1(new char[arraySize]);
    Ncl::strCopy(srcStr1.get(), arraySize, "test");

    std::unique_ptr<char[]> srcStr2(new char[arraySize]);
    Ncl::strCopy(srcStr2.get(), arraySize, "test");

    //Act
    const Ncl::CString instance1(srcStr1.get(), arraySize);
    const Ncl::CString instance2(srcStr2.get(), arraySize);
    srcStr1.release();
    srcStr2.release();
    bool actual = instance1 == instance2;

    //Assert
    REQUIRE(true == actual);
}

TEST_CASE( "Not equal strings return true", "[CString::!=]" )
{
    //Arrange
    const size_t arraySize = 6;
    std::unique_ptr<char[]> srcStr1(new char[arraySize]);
    Ncl::strCopy(srcStr1.get(), arraySize, "test");

    std::unique_ptr<char[]> srcStr2(new char[arraySize]);
    Ncl::strCopy(srcStr2.get(), arraySize, "test2");

    //Act
    const Ncl::CString instance1(srcStr1.get(), arraySize);
    const Ncl::CString instance2(srcStr2.get(), arraySize);
    srcStr1.release();
    srcStr2.release();
    bool actual = instance1 != instance2;

    //Assert
    REQUIRE(true == actual);
}

#pragma clang diagnostic pop
#pragma warning (pop)
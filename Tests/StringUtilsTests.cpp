
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
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning tabs has it removed", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "\t\t\ttest ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning newlines has it removed", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "\n\n\ntest ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "    \t\n    ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrimLeft]" )
{
	//Arrange
	constexpr char expected[] = "test ";
	char actual[] = "test ";

	//Act
	Ncl::strTrimLeft(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
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
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with ending tabs has it removed", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test\t\t\t\t";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with ending newlines has it removed", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test\n\n\n";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "        ";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrimRight]" )
{
	//Arrange
	constexpr char expected[] = " test";
	char actual[] = " test";

	//Act
	Ncl::strTrimRight(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
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
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning and ending tabs has it removed", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "\t\t test test\t\t\t\t";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with beginning and ending newlines has it removed", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "\n\n test test\n\n\n";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with all whitespace returns empty string", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "";
	char actual[] = "        ";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
}

TEST_CASE( "String with text content returns the same", "[strTrim]" )
{
	//Arrange
	constexpr char expected[] = "test test";
	char actual[] = "test test";

	//Act
	Ncl::strTrim(actual, sizeof(actual));

	//Assert
	STR_EQUAL_REQUIRE(expected, actual);
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

TEST_CASE( "equal c-strings return true", "[strEquals]" )
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

TEST_CASE( "not equal c-strings return false", "[strEquals]" )
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

TEST_CASE( "equal c-strings return true", "[strEqualsIc]" )
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

TEST_CASE( "not equal c-strings return false", "[strEqualsIc]" )
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

TEST_CASE( "c-strings with letter case difference return true", "[strEqualsIc]" )
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

TEST_CASE( "c-strings with whitespace difference return false", "[strEqualsIc]" )
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

TEST_CASE( "equal c-strings return true", "[strEqualsIws]" )
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

TEST_CASE( "not equal c-strings return false", "[strEqualsIws]" )
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

TEST_CASE( "empty c-string and whitespace c-string return true", "[strEqualsIws]" )
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

TEST_CASE( "c-strings with letter case difference return false", "[strEqualsIws]" )
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

TEST_CASE( "c-strings with whitespace difference return true", "[strEqualsIws]" )
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

TEST_CASE( "equal c-strings return true", "[strEqualsIcws]" )
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

TEST_CASE( "not equal c-strings return false", "[strEqualsIcws]" )
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

TEST_CASE( "empty c-string and whitespace c-string return true", "[strEqualsIcws]" )
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

TEST_CASE( "c-strings with letter case difference return true", "[strEqualsIcws]" )
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

TEST_CASE( "c-strings with whitespace difference return true", "[strEqualsIcws]" )
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

TEST_CASE( "c-strings with whitespace and letter case differences return true", "[strEqualsIcws]" )
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

#pragma clang diagnostic pop
#pragma warning (pop)
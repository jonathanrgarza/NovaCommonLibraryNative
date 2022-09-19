//
// Created by Jonathan on 8/29/22.
//

#include "StringUtils.h"

#include <iostream>
#include <memory>

using namespace Ncl;

const std::string Ncl::TRUE_STRING = "true";

const std::string Ncl::FALSE_STRING = "false";

const CCString TRUE_CCSTRING = CCString("true");

const CCString FALSE_CCSTRING = CCString("false");

constexpr CCString::CCString(const char *str, const size_t size, const bool dynamicPtr, const bool mallocPtr)
		: _str(str),
		  _size(size), _dynamicPtr(dynamicPtr), _mallocPtr(mallocPtr)
{
	if (str == nullptr)
		return;

	_length = strnlen(str, size);
}

CCString::~CCString()
{
	if (!_dynamicPtr)
		return;

	if (_str == nullptr)
		return;

	if (_mallocPtr)
	{
		free(const_cast<void *>(static_cast<const void *>(_str)));
		_str = nullptr;
		return;
	}

	delete[] _str;
	_str = nullptr;
}

const CCString CCString::Null(nullptr, 0);
const CCString CCString::Empty(EMPTY_STR);

auto CCString::operator[](const size_t i) const -> const char &
{
	if (i >= _size)
		throw std::out_of_range("i is greater than CCString's size");

	return _str[i];
}

auto Ncl::operator<<(std::ostream &os, const CCString &str) -> std::ostream &
{
	if (str.isNull())
	{
		//os << "nullptr";
		return os;
	}

	os << str._str;
	return os;
}

CString::CString(char *str, const size_t size, const bool dynamicPtr, const bool mallocPtr) : _str(str),
	_size(size), _dynamicPtr(dynamicPtr), _mallocPtr(mallocPtr)
{
	if (size == 0 && str != nullptr)
		throw std::invalid_argument("size can not be zero when str is not null");
}

CString::CString(const size_t size) : _str(nullptr),
										   _size(size), _dynamicPtr(true), _mallocPtr(false) {
	if (size == 0)
		throw std::invalid_argument("size can not be zero");

	_str = new char[size]{'\0'};
}

CString::~CString()
{
	if (!_dynamicPtr)
		return;

	if (_str == nullptr)
		return;

	if (_mallocPtr)
	{
		free(_str);
		_str = nullptr;
		return;
	}

	delete[] _str;
	_str = nullptr;
}

const CString CString::Null(nullptr, 0);

auto CString::operator[](const size_t i) const -> const char &
{
	if (i >= _size)
		throw std::out_of_range("i is greater than CString's size");

	return _str[i];
}

auto CString::operator[](const size_t i) -> char &
{
	if (i >= _size)
		throw std::out_of_range("i is greater than CString's size");

	return _str[i];
}

auto Ncl::operator<<(std::ostream &os, const CString &str) -> std::ostream &
{
	if (str.isNull())
	{
		//os << "nullptr";
		return os;
	}

	os << str._str;
	return os;
}

auto Ncl::strIsNullTerminated(const char *str, const size_t size) -> bool
{
	if (str == nullptr || size == 0)
		return false;

	const size_t len = strnlen(str, size);
	return len < size;
}

void Ncl::strEnsureNullTerminated(const char *str, const size_t size)
{
	if (!strIsNullTerminated(str, size))
		throw std::invalid_argument("str is not a null-terminated string");
}

auto Ncl::strLength(const char *str, size_t strSize) -> size_t
{
	if (str == nullptr)
		return 0;

	for (size_t i = 0; i < strSize; ++i)
	{
		const char& character = str[i];
		if (character == '\0')
			return i;
	}

	return strSize;
}

void Ncl::strCopy(char *dest, size_t destSize, const char *src, size_t srcSize)
{
	if (dest == nullptr || destSize == 0)
		return;
	if (src == nullptr || srcSize == 0)
		return;

	size_t size = destSize < srcSize ? destSize : srcSize;

	size_t i;
	for (i = 0; i < size; ++i)
	{
		const char& character = src[i];
		if (character == '\0')
			break;
		dest[i] = character;
	}

	dest[i] = '\0';
}

void Ncl::strCat(char *dest, size_t destSize, const char *src, size_t srcSize)
{
	if (dest == nullptr || destSize == 0)
		return;
	if (src == nullptr || srcSize == 0)
		return;

	size_t srcLength = strLength(src, srcSize);

	if (srcLength == 0)
		return;

	size_t destLength = strLength(dest, destSize);

	//size_t appendLength = srcLength < destSize - destLength ? srcLength -
	//TODO: Finish implementation
}

auto Ncl::strEquals(const char *firstStr, size_t firstStrSize, const char *secondStr, size_t secondStrSize) -> bool
{
	if (firstStr == nullptr && secondStr == nullptr)
		return true;
	if (firstStr == nullptr || secondStr == nullptr)
		return false;

	if (firstStrSize == 0 && secondStrSize == 0)
		return true;

	size_t firstStrLength = strnlen(firstStr, firstStrSize);
	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStrLength != secondStrLength)
		return false;

	for(size_t i = 0; i < secondStrLength; i++)
	{
		const char& firstChar = firstStr[i];
		const char& secondChar = secondStr[i];

		if (firstChar != secondChar)
			return false;
	}

	return true;
}

auto Ncl::strEqualsIc(const char *firstStr, size_t firstStrSize, const char *secondStr, size_t secondStrSize) -> bool
{
	if (firstStr == nullptr && secondStr == nullptr)
		return true;
	if (firstStr == nullptr || secondStr == nullptr)
		return false;

	if (firstStrSize == 0 && secondStrSize == 0)
		return true;

	size_t firstStrLength = strnlen(firstStr, firstStrSize);
	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStrLength != secondStrLength)
		return false;

	for(size_t i = 0; i < secondStrLength; i++)
	{
		const char& firstChar = firstStr[i];
		const char& secondChar = secondStr[i];

		if (tolower(firstChar) != tolower(secondChar))
			return false;
	}

	return true;
}

auto Ncl::strEqualsIws(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool
{
	if (firstStr == nullptr && secondStr == nullptr)
		return true;
	if (firstStr == nullptr || secondStr == nullptr)
		return false;

	if (firstStrSize == 0 && secondStrSize == 0)
		return true;

	size_t firstStrLength = strnlen(firstStr, firstStrSize);
	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStrLength == 0 && secondStrLength == 0)
		return true;

	size_t i = 0;
	size_t j = 0;

	while(i < firstStrLength || j < secondStrLength)
	{
		//Get the next non-whitespace character (unless nothing else left) in first string
		char firstChar = firstStr[i];
		while(i < firstStrLength && isspace(firstChar))
		{
			i++;
			firstChar = firstStr[i];
		}

		//Get the next non-whitespace character (unless nothing else left) in second string
		char secondChar = secondStr[j];
		while(j < secondStrLength && isspace(secondChar))
		{
			j++;
			secondChar = secondStr[j];
		}

		//Check for special match cases
		if (firstChar == '\0' || secondChar == '\0')
		{
			if (firstChar == '\0' && secondChar == '\0')
				return true;
			if (isspace(firstChar) || isspace(secondChar))
				return true;
			return false;
		}
		if (isspace(firstChar) && isspace(secondChar))
			return true;

		if (firstChar != secondChar)
			return false;

		if (i < firstStrLength)
		{
			i++;
		}

		if (j < secondStrLength)
		{
			j++;
		}
	}

	if (i < firstStrLength || j < secondStrLength)
		return false;

	return true;
}

auto Ncl::strEqualsIcws(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool
{
	if (firstStr == nullptr && secondStr == nullptr)
		return true;
	if (firstStr == nullptr || secondStr == nullptr)
		return false;

	if (firstStrSize == 0 && secondStrSize == 0)
		return true;

	size_t firstStrLength = strnlen(firstStr, firstStrSize);
	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStrLength == 0 && secondStrLength == 0)
		return true;

	size_t i = 0;
	size_t j = 0;

	while(i < firstStrLength || j < secondStrLength)
	{
		//Get the next non-whitespace character (unless nothing else left) in first string
		char firstChar = firstStr[i];
		while(i < firstStrLength && isspace(firstChar))
		{
			i++;
			firstChar = firstStr[i];
		}

		//Get the next non-whitespace character (unless nothing else left) in second string
		char secondChar = secondStr[j];
		while(j < secondStrLength && isspace(secondChar))
		{
			j++;
			secondChar = secondStr[j];
		}

		//Check for special match cases
		if (firstChar == '\0' || secondChar == '\0')
		{
			if (firstChar == '\0' && secondChar == '\0')
				return true;
			if (isspace(firstChar) || isspace(secondChar))
				return true;
			return false;
		}
		if (isspace(firstChar) && isspace(secondChar))
			return true;

		if (tolower(firstChar) != tolower(secondChar))
			return false;

		if (i < firstStrLength)
		{
			i++;
		}

		if (j < secondStrLength)
		{
			j++;
		}
	}

	if (i < firstStrLength || j < secondStrLength)
		return false;

	return true;
}

auto Ncl::stringEquals(const std::string &firstStr, const char *secondStr, size_t secondStrSize) -> bool
{
	if (secondStr == nullptr || secondStrSize == 0)
		return false;

	//Check for empty string
	if (firstStr.length() == 0 && secondStr[0] == '\0')
		return true;

	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStr.length() != secondStrLength)
		return false;

	for(size_t i = 0; i < secondStrLength; i++)
	{
		const char& firstChar = firstStr[i];
		const char& secondChar = secondStr[i];

		if (firstChar != secondChar)
			return false;
	}

	return true;
}

auto Ncl::stringEqualsIc(const std::string &firstStr, const char *secondStr, size_t secondStrSize) -> bool
{
	if (secondStr == nullptr || secondStrSize == 0)
		return false;

	size_t firstStrLength = firstStr.length();
	size_t secondStrLength = strnlen(secondStr, secondStrSize);

	if (firstStrLength != secondStrLength)
		return false;

	for(size_t i = 0; i < secondStrLength; i++)
	{
		const char& firstChar = firstStr[i];
		const char& secondChar = secondStr[i];

		if (tolower(firstChar) != tolower(secondChar))
			return false;
	}

	return true;
}

auto Ncl::stringEqualsIws(const std::string &firstStr, const char *secondStr, size_t secondStrSize) -> bool
{
	//TODO: Implement
	return false;
}

auto Ncl::stringEqualsIcws(const std::string &firstStr, const char *secondStr, size_t secondStrSize) -> bool
{
	//TODO: Implement
	return false;
}

auto Ncl::stringEquals(const std::string &firstStr, const std::string &secondStr) -> bool
{
	return firstStr == secondStr;
}

auto Ncl::stringEqualsIc(const std::string &firstStr, const std::string &secondStr) -> bool
{
	//TODO: Implement
	return false;
}

auto Ncl::stringEqualsIws(const std::string &firstStr, const std::string &secondStr) -> bool
{
	//TODO: Implement
	return false;
}

auto Ncl::stringEqualsIcws(const std::string &firstStr, const std::string &secondStr) -> bool
{
	//TODO: Implement
	return false;
}

void Ncl::strTrimLeft(char *str, const size_t size)
{
	if (str == nullptr || size == 0)
		return;

	size_t i;
	for (i = 0; i < size; ++i)
	{
		const char &character = str[i];
		if (!isspace(character))
			break;
	}

	//Check if any whitespace
	if (i == 0)
		return;

	//Check if whole string is whitespace
	if (i == size)
	{
		str[0] = '\0';
		return;
	}

	//Move the character after beginning whitespace up to beginning
	const size_t len = strnlen(str, size);
	for (size_t j = 0; j < len - i; ++j)
	{
		str[j] = str[i + j];
	}
	str[len - i] = '\0';
}

void Ncl::strTrimRight(char *str, const size_t size)
{
	if (str == nullptr || size == 0)
		return;

	const size_t len = strnlen(str, size);
	if (len == 0)
		return;

	constexpr size_t end = -1;
	size_t i;
	for (i = len - 1; i != end; --i)
	{
		const char &character = str[i];
		if (!isspace(character))
			break;
	}

	str[i + 1] = '\0';
}

void Ncl::strTrim(char *str, const size_t size)
{
	if (str == nullptr || size == 0)
		return;

	//Right, then left for efficiently
	strTrimRight(str, size);
	strTrimLeft(str, size);
}

void Ncl::stringTrimLeft(std::string &str)
{
	if (str.empty())
		return;

	const size_t len = str.length();
	size_t i;
	for (i = 0; i < len; ++i)
	{
		const char &character = str[i];
		if (!isspace(character))
			break;
	}

	if (i == 0)
		return;

	if (i == len)
	{
		str.clear();
		return;
	}

	str.erase(0, i);
}

void Ncl::stringTrimRight(std::string &str)
{
	if (str.empty())
		return;

	auto i = str.rbegin();
	const auto end = str.rend();

	for (; i != end; ++i)
	{
		const char &character = *i;
		if (!isspace(character))
			break;
	}

	if (i == str.rbegin())
		return;

	if (i == end)
	{
		str.clear();
		return;
	}

	// ReSharper disable once CommentTypo
	//.base() flips the sides, i.e. the rbegin() == end()
	str.erase(end.base(), i.base());
}

void Ncl::stringTrim(std::string &str)
{
	if (str.empty())
		return;

	//Right, then left for efficiently
	stringTrimRight(str);
	stringTrimLeft(str);
}

void Ncl::stringAppend(std::string &str, const char *strToAppend, size_t strToAppendSize)
{
	if (strToAppend == nullptr || strToAppendSize == 0)
		return;

	size_t length = strnlen(strToAppend, strToAppendSize);
	str.append(strToAppend, length);
}

auto Ncl::boolToString(bool value) -> const std::string &
{
	return value ? TRUE_STRING : FALSE_STRING;
}

auto Ncl::boolToCCString(bool value) -> const CCString &
{
	return value ? TRUE_CCSTRING : FALSE_CCSTRING;
}

auto Ncl::strToBool(const char *str, size_t size, bool ignoreCase, bool looseMatch) -> bool
{
	if (str == nullptr || size == 0)
		return false;

	if (!looseMatch)
	{
		if (ignoreCase)
		{
			return strEqualsIc(str, size, TRUE_STR, TRUE_STR_SIZE);
		}

		return strEquals(str, size, TRUE_STR, TRUE_STR_SIZE);
	}

	if (ignoreCase)
	{
		if (strEqualsIcws(str, size, TRUE_STR, TRUE_STR_SIZE))
			return true;
		if (strEqualsIcws(str, size, "yes"))
			return true;

		if (strEqualsIcws(str, size, "on"))
			return true;

		return false;
	}

	if (strEqualsIws(str, size, TRUE_STR, TRUE_STR_SIZE))
		return true;
	if (strEqualsIws(str, size, "yes"))
		return true;

	if (strEqualsIws(str, size, "on"))
		return true;

	return false;
}

auto stringToBool(const std::string &str, bool ignoreCase, bool looseMatch) -> bool
{
	if (str.length() == 0)
		return false;

	if (!looseMatch)
	{
		if (ignoreCase)
		{
			return stringEqualsIc(str, TRUE_STRING);
		}

		return stringEquals(str, TRUE_STRING);
	}

	if (ignoreCase)
	{
		if (stringEqualsIcws(str, TRUE_STRING))
			return true;
		if (stringEqualsIcws(str, "yes"))
			return true;

		if (stringEqualsIcws(str, "on"))
			return true;

		return false;
	}

	if (stringEqualsIws(str, TRUE_STR, TRUE_STR_SIZE))
		return true;
	if (stringEqualsIws(str, "yes"))
		return true;

	if (stringEqualsIws(str, "on"))
		return true;

	return false;
}

#pragma warning(push)
#pragma warning (disable : 4068 ) //Disable unknown paragmas
#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

void CString::resize(const size_t size, const bool retainContents)
{
	const size_t oldSize = _size;
	_size = size;
	if (size == 0)
	{
		deletePtr();
		return;
	}

	std::unique_ptr<char[]> newPtr;
	if (_mallocPtr)
	{
		newPtr.reset(static_cast<char *>(malloc(sizeof(char) * size)));
		newPtr.get()[0] = '\0';
	} else {
		newPtr = std::make_unique<char[]>(size);
		newPtr.get()[0] = '\0';
	}

	if (retainContents)
	{
		const size_t min = std::min(oldSize, size);
		strncpy_s(newPtr.get(), size, _str, min);
	}

	deletePtr();

	_dynamicPtr = true;
	_str = newPtr.release();
}

#pragma clang diagnostic pop
#pragma warning(pop)

void CString::copy(const char *ptr, const size_t size, const bool allowResizing)
{
	if (ptr == nullptr || size == 0)
	{
		if (!allowResizing)
			throw std::invalid_argument("ptr can not be nullptr while copying with no resizing");

		resize(0, false); //Will result in _str becoming a nullptr
		return;
	}

	if (_size >= size)
	{
		strncpy_s(_str, _size, ptr, size);
		return;
	}

	//Need bigger buffer
	if (!allowResizing)
		throw std::invalid_argument("ptr's size is greater than CString's size");

	resize(size, true);
	strncpy_s(_str, _size, ptr, size);
}

void CString::deletePtr()
{
	if (_str == nullptr)
		return;

	if (_dynamicPtr)
	{
		if (_mallocPtr)
		{
			free(_str);
		}
		else
		{
			delete[] _str;
		}
	}

	_str = nullptr;
}

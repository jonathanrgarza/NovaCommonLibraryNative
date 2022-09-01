//
// Created by Jonathan on 8/29/22.
//

#import "StringUtils.h"

#include <iostream>
#include <memory>

const std::string NCL::TRUE_STRING = "true";

const std::string NCL::FALSE_STRING = "false";

constexpr NCL::CCString::CCString(const char *str, size_t size, bool dynamicPtr, bool mallocPtr) : _str(str), 
    _size(size), _dynamicPtr(dynamicPtr), _mallocPtr(mallocPtr)
{
    if (str == nullptr)
        return;
    
    _length = strnlen(str, size);
}

NCL::CCString::~CCString()
{
    if (!_dynamicPtr)
        return;

    if (_str == nullptr)
        return;

    if (_mallocPtr)
    {
        free((void *) _str);
        _str = nullptr;
        return;
    }
    
    delete[] _str;
    _str = nullptr;
}

const NCL::CCString NCL::CCString::Null(nullptr, 0);
const NCL::CCString NCL::CCString::Empty(NCL::EMPTY_STR);

auto NCL::CCString::operator[](size_t i) const -> const char &
{
    if (i >= _size)
        throw std::out_of_range("i is greater than CCString's size");

    return _str[i];
}

auto NCL::operator<<(std::ostream &os, const NCL::CCString &str) -> std::ostream &
{
    if (str.isNull())
    {
        //os << "nullptr";
        return os;
    }
    
    os << str._str;
    return os;
}

NCL::CString::CString(char *str, size_t size, bool dynamicPtr, bool mallocPtr) : _str(str),
_size(size), _dynamicPtr(dynamicPtr), _mallocPtr(mallocPtr)
{
    if (size == 0 && str != nullptr)
        throw std::invalid_argument("size can not be zero when str is not null");
}

NCL::CString::CString(size_t size) : _str(nullptr),
_size(size), _dynamicPtr(true), _mallocPtr(false)
{
    if (size == 0)
        throw std::invalid_argument("size can not be zero");
    
    _str = new char[size] { '\0' };
}

NCL::CString::~CString()
{
    if (!_dynamicPtr)
        return;

    if (_str == nullptr)
        return;

    if (_mallocPtr)
    {
        free((void *) _str);
        _str = nullptr;
        return;
    }

    delete[] _str;
    _str = nullptr;
}

const NCL::CString NCL::CString::Null(nullptr, 0);

auto NCL::CString::operator[](size_t i) const -> const char &
{
    if (i >= _size)
        throw std::out_of_range("i is greater than CString's size");
    
    return _str[i];
}

auto NCL::CString::operator[](size_t i) -> char &
{
    if (i >= _size)
        throw std::out_of_range("i is greater than CString's size");

    return _str[i];
}

auto NCL::operator<<(std::ostream &os, const NCL::CString &str) -> std::ostream &
{
    if (str.isNull())
    {
        //os << "nullptr";
        return os;
    }
    
    os << str._str;
    return os;
}

auto NCL::strIsNullTerminated(const char *str, size_t size) -> bool
{
    if (str == nullptr || size == 0)
        return false;

    size_t len = strnlen(str, size);
    return len == size;
}

void NCL::strEnsureNullTerminated(const char *str, size_t size)
{
    if (!strIsNullTerminated(str, size))
        throw std::invalid_argument("str is not a null-terminated string");
}

void NCL::strTrimLeft(char *str, size_t size)
{
    if (str == nullptr || size == 0)
        return;

    size_t i;
    for (i = 0; i < size; ++i)
    {
        char& character = str[i];
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
    size_t len = strnlen(str, size);
    for (size_t j = 0; j < len - i; ++j)
    {
        str[j] = str[i + j];
    }
    str[len - i] = '\0';
}

void NCL::strTrimRight(char *str, size_t size)
{
    if (str == nullptr || size == 0)
        return;

    size_t len = strnlen(str, size);
    if (len == 0)
        return;
    
    size_t i;
    for (i = len - 1; i < len; --i)
    {
        char& character = str[i];
        if (!isspace(character))
            break;
    }
    
    str[i+1] = '\0';
}

void NCL::strTrim(char *str, size_t size)
{
    if (str == nullptr || size == 0)
        return;
    //Right, then left for efficiently
    strTrimRight(str, size);
    strTrimLeft(str, size);
}

void NCL::stringTrimLeft(std::string &str)
{
    if (str.empty())
        return;

    size_t len = str.length();
    int i;
    for (i = 0; i < len; ++i)
    {
        char& character = str[i];
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

void NCL::stringTrimRight(std::string &str)
{
    if (str.empty())
        return;
    
    auto i = str.rbegin();
    auto end = str.rend();

    for (; i != end; i++)
    {
        char& character = *i;
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
    
    str.erase(i.base(), end.base());
}

void NCL::stringTrim(std::string &str)
{
    if (str.empty())
        return;

    //Right, then left for efficiently
    stringTrimRight(str);
    stringTrimLeft(str);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"
void NCL::CString::resize(size_t size, bool retainContents)
{
    size_t oldSize = _size;
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
    }
    else
    {
        newPtr = std::make_unique<char[]>(size);
        newPtr.get()[0] = '\0';
    }

    if (retainContents)
    {
        size_t min = std::min(oldSize, size);
        strncpy(newPtr.get(), _str, min);
    }

    deletePtr();
    
    _dynamicPtr = true;
    _str = newPtr.release();
}
#pragma clang diagnostic pop

void NCL::CString::copy(const char *ptr, size_t size, bool allowResizing)
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
        strncpy(_str, ptr, size);
        return;
    }

    //Need bigger buffer
    if (!allowResizing)
        throw std::invalid_argument("ptr's size is greater than CString's size");

    resize(size, true);
    strncpy(_str, ptr, size);
}

void NCL::CString::deletePtr()
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

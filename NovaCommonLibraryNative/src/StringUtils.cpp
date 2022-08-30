//
// Created by Jonathan on 8/29/22.
//

#import "StringUtils.h"

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
    
    _str = new char[size];
}

NCL::CString::~CString()
{
    if (!_dynamicPtr)
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
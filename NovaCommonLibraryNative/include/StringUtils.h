//
// Created by Jonathan on 8/29/22.
//

#ifndef NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H
#define NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H

#include <cstdlib>
#include <string>
#include "Macros.h"

namespace Ncl
{
#pragma warning (push)
#pragma warning (disable : 4068 )
#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-c-arrays"

#if defined(_WIN32) || defined(_WIN64) //Windows
	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\r\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif defined(__CYGWIN__) //POSIX on Windows
	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif defined(__ANDROID__) //Android; Must come before Linux as this implies Linux also
	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif defined(__linux__) // Linux
	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif defined(__unix__) || !defined(__APPLE__) && !defined(__MACH__) // UNIX (and maybe BSD)
	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
	#include <TargetConditionals.h>

	#if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
		/**
		 * The new line character(s) for the platform.
		 */
		constexpr const char NEWLINE[] = "\n";
		/**
		 * The size of the new line character(s).
		 */
		constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
	#elif TARGET_OS_MAC == 1
		/**
		 * The new line character(s) for the platform.
		 */
		constexpr const char NEWLINE[] = "\n";
		/**
		 * The size of the new line character(s).
		 */
		constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
	#else
		#warning "Unsupported target Apple platform for New Line array, using default value"

		/**
		 * The new line character(s) for the platform.
		 */
		constexpr const char NEWLINE[] = "\n";
		/**
		 * The size of the new line character(s).
		 */
		constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
	#endif
#else
	#warning "Unsupported platform for New Line array, using default value"

	/**
	 * The new line character(s) for the platform.
	 */
	constexpr const char NEWLINE[] = "\n";
	/**
	 * The size of the new line character(s).
	 */
	constexpr size_t NEWLINE_SIZE = sizeof(NEWLINE);
#endif

	class CCString;
	class CString;

	/**
	 * The string representation of an empty string.
	 */
	constexpr const char EMPTY_STR[] = "";
	/**
	 * The size of the EMPTY_STR array.
	 */
	constexpr size_t EMPTY_STR_SIZE = sizeof(EMPTY_STR);

	/**
	 * The string representation of a true boolean value.
	 */
	constexpr const char TRUE_STR[] = "true";
	/**
	 * The size of the TRUE_STR array.
	 */
	constexpr size_t TRUE_STR_SIZE = sizeof(TRUE_STR);
	/**
	 * The string representation of a false boolean value.
	 */
	constexpr const char FALSE_STR[] = "false";
	/**
	 * The size of the FALSE_STR array.
	 */
	constexpr size_t FALSE_STR_SIZE = sizeof(FALSE_STR);

	/**
	 * The string representation of a true boolean value.
	 */
	extern const std::string TRUE_STRING;
	/**
	 * The string representation of a false boolean value.
	 */
	extern const std::string FALSE_STRING;

	auto strIsNullTerminated(const char *str, size_t size) -> bool;

	void strEnsureNullTerminated(const char *str, size_t size);
    
    /// \brief Gets the length of the given c-string.
    /// \param str The c-string.
    /// \param strSize The maximum size of the c-string (including the null-terminating character).
    /// \return The length of the string, or strSize if a null-terminating character is not found.
    /// Returns 0 if str is a null pointer.
    auto strLength(const char* str, size_t strSize) -> size_t;

    /// \brief Gets the length of the given c-string.
    /// \tparam N The maximum size of the c-string (including the null-terminating character).
    /// \param str The c-string.
    /// \return The length of the string, or strSize if a null-terminating character is not found.
    template<std::size_t N>
    auto strLength(const char(&str)[N]) -> size_t
    {
        for (size_t i = 0; i < N; ++i)
        {
            const char& character = str[i];
            if (character == '\0')
                return i;
        }
        
        return N;
    }
    
    auto strCopy(char* dest, size_t destSize, const char* src, size_t srcSize) -> size_t;

    template<std::size_t N>
	auto strCopy(char* dest, size_t destSize, const char(&src)[N]) -> size_t
    {
        return strCopy(dest, destSize, src, N);
    }

    template<std::size_t N>
	auto strCopy(char(&dest)[N], const char* src, size_t srcSize) -> size_t
    {
		return strCopy(dest, N, src, srcSize);
    }

    template<std::size_t N, std::size_t S>
	auto strCopy(char(&dest)[N], const char(&src)[S]) -> size_t
    {
		return strCopy(dest, N, src, S);
    }

    auto strCat(char* dest, size_t destSize, const char* src, size_t srcSize) -> size_t;

    template<std::size_t N>
	auto strCat(char* dest, size_t destSize, const char(&src)[N]) -> size_t
    {
        return strCat(dest, destSize, src, N);
    }

    template<std::size_t N>
	auto strCat(char(&dest)[N], const char* src, size_t srcSize) -> size_t
    {
        return strCat(dest, N, src, srcSize);
    }

    template<std::size_t N, std::size_t S>
	auto strCat(char(&dest)[N], const char(&src)[S]) -> size_t
    {
        return strCat(dest, N, src, S);
    }

	auto strEquals(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool;

	auto strEqualsIc(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool;

	auto strEqualsIws(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool;

	auto strEqualsIcws(const char* firstStr, size_t firstStrSize, const char* secondStr, size_t secondStrSize) -> bool;

	template<std::size_t N>
	auto strEquals(const char* firstStr, size_t firstStrSize, const char(&secondStr)[N]) -> bool
	{
		return strEquals(firstStr, firstStrSize, secondStr, N);
	}

	template<std::size_t N>
	auto strEqualsIc(const char* firstStr, size_t firstStrSize, const char(&secondStr)[N]) -> bool
	{
		return strEqualsIc(firstStr, firstStrSize, secondStr, N);
	}

	template<std::size_t N>
	auto strEqualsIws(const char* firstStr, size_t firstStrSize, const char(&secondStr)[N]) -> bool
	{
		return strEqualsIws(firstStr, firstStrSize, secondStr, N);
	}

	template<std::size_t N>
	auto strEqualsIcws(const char* firstStr, size_t firstStrSize, const char(&secondStr)[N]) -> bool
	{
		return strEqualsIcws(firstStr, firstStrSize, secondStr, N);
	}

	auto stringEquals(const std::string& firstStr, const char* secondStr, size_t secondStrSize) -> bool;

	auto stringEqualsIc(const std::string& firstStr, const char* secondStr, size_t secondStrSize) -> bool;

	auto stringEqualsIws(const std::string& firstStr, const char* secondStr, size_t secondStrSize) -> bool;

	auto stringEqualsIcws(const std::string& firstStr, const char* secondStr, size_t secondStrSize) -> bool;

	auto stringEquals(const std::string& firstStr, const std::string& secondStr) -> bool;

	auto stringEqualsIc(const std::string& firstStr, const std::string& secondStr) -> bool;

	auto stringEqualsIws(const std::string& firstStr, const std::string& secondStr) -> bool;

	auto stringEqualsIcws(const std::string& firstStr, const std::string& secondStr) -> bool;

	template<std::size_t N>
	auto stringEquals(const std::string& firstStr, const char(&secondStr)[N]) -> bool
	{
		return stringEquals(firstStr, secondStr, N);
	}

	template<std::size_t N>
	auto stringEqualsIc(const std::string& firstStr, const char(&secondStr)[N]) -> bool
	{
		return stringEqualsIc(firstStr, secondStr, N);
	}

	template<std::size_t N>
	auto stringEqualsIws(const std::string& firstStr, const char(&secondStr)[N]) -> bool
	{
		return stringEqualsIws(firstStr, secondStr, N);
	}

	template<std::size_t N>
	auto stringEqualsIcws(const std::string& firstStr, const char(&secondStr)[N]) -> bool
	{
		return stringEqualsIcws(firstStr, secondStr, N);
	}

	void strTrimLeft(char *str, size_t size);

	void strTrimRight(char *str, size_t size);

	void strTrim(char *str, size_t size);

	void stringTrimLeft(std::string &str);

	void stringTrimRight(std::string &str);

	void stringTrim(std::string &str);

	/// \brief Appends the given c-string to.
	/// \tparam N The size of the c-string literal.
	/// \param str The string to append to.
	/// \param strToAppend The c-string to append.
	template<std::size_t N>
	constexpr void stringAppend(std::string &str, const char(&strToAppend)[N])
	{
		size_t length = strnlen(strToAppend, N);
		str.append(strToAppend, length);
	}

	void stringAppend(std::string &str, const char *strToAppend, size_t strToAppendSize);

	auto boolToString(bool value) -> const std::string &;

	auto boolToCCString(bool value) -> const CCString &;

	auto strToBool(const char *str, size_t size, bool ignoreCase = false, bool looseMatch = false) -> bool;

	auto stringToBool(const std::string &str, bool ignoreCase = false, bool looseMatch = false) -> bool;

	class CCString
	{
	public:
		static const CCString Null;
		static const CCString Empty;

		constexpr CCString(const char *str, size_t size, bool dynamicPtr = false, bool mallocPtr = false);

		template<std::size_t N>
		constexpr explicit CCString(const char(&str)[N]) : _str(str), _size(N), _dynamicPtr(false), _mallocPtr(false)
		{
			_length = strnlen(str, N);
		}

		~CCString();

		NCL_NODISCARD constexpr auto isNull() const -> bool { return _str == nullptr; }

		NCL_NODISCARD constexpr auto isEmpty() const -> bool { return _str != nullptr && _length == 0; }

		NCL_NODISCARD constexpr auto isNullOrEmpty() const -> bool { return _str == nullptr || _length == 0; }

		NCL_NODISCARD constexpr auto str() const -> const char * { return _str; }

		NCL_NODISCARD constexpr auto size() const -> size_t { return _size; }

		NCL_NODISCARD constexpr auto length() const -> size_t { return _length; }

		NCL_NODISCARD auto operator[](size_t i) const -> const char &;

		friend auto operator<<(std::ostream &os, const CCString &str) -> std::ostream &;

	private:
		const char *_str;
		const size_t _size;
		const bool _dynamicPtr; // NOLINT(modernize-use-default-member-init)
		const bool _mallocPtr; // NOLINT(modernize-use-default-member-init)
		size_t _length{0};
	};

	class CString
	{
	public:
		static const CString Null;

		CString(char *str, size_t size, bool dynamicPtr = true, bool mallocPtr = false);

		explicit CString(size_t size);

		~CString();

		NCL_NODISCARD constexpr auto isNull() const -> bool { return _str == nullptr; }

		NCL_NODISCARD constexpr auto isEmpty() const -> bool
		{
			if (_str == nullptr)
				return false;

			if ((*_str) == '\0')
				return true;

			return false;
		}

		NCL_NODISCARD constexpr auto isNullOrEmpty() const -> bool
		{
			if (_str == nullptr)
				return true;

			if ((*_str) == '\0')
				return true;

			return false;
		}

		NCL_NODISCARD constexpr auto str() -> char * { return _str; }

		NCL_NODISCARD constexpr auto str() const -> const char * { return _str; }

		NCL_NODISCARD constexpr auto size() const -> size_t { return _size; }

		NCL_NODISCARD constexpr auto length() const -> size_t
		{
			return _str == nullptr ? 0 : strnlen(_str, _size);
		}

		void resize(size_t size, bool retainContents = true);

		void copy(const char *ptr, size_t size, bool allowResizing = false);

		NCL_NODISCARD auto operator[](size_t i) const -> const char &;

		NCL_NODISCARD auto operator[](size_t i) -> char &;

		friend auto operator<<(std::ostream &os, const CString &str) -> std::ostream &;

	private:
		void deletePtr();

		char *_str;
		size_t _size;
		bool _dynamicPtr; // NOLINT(modernize-use-default-member-init)
		const bool _mallocPtr; // NOLINT(modernize-use-default-member-init)
	};

#pragma clang diagnostic pop
#pragma warning (pop)
}

#endif //NOVACOMMONLIBRARYNATIVE_STRINGUTILS_H

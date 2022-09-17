//
// Created by Jonathan on 7/8/22.
//

#ifndef NOVACOMMONLIBRARYNATIVE_LOGGER_H
#define NOVACOMMONLIBRARYNATIVE_LOGGER_H

#include <cstdint>
#include <cstdarg>
#include <string>

namespace Ncl
{
	/// \brief Represents a log level.
	enum class LogLevel
	{
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Fatal
	};

	/// \brief Base logger class. Contains typical log functions and properties.
	class Logger
	{
	public:
		virtual ~Logger() = default;

		//Properties

		/// \brief Gets if the logger is active, i.e. has any output set.
		/// \return True if the logger is active, otherwise, false.
		bool isActive() const { return _isActive; };

		/// \brief Gets the log level for the logger.
		/// \return The log level value.
		LogLevel logLevel() const { return _level; }

		//End Properties

		/// \brief Checks if the given log level is enabled for the logger.
		/// \param level The log level.
		/// \return True if the level is enabled, otherwise, false.
		bool isEnabled(LogLevel level) const
		{
			return level >= _level;
		}

		/// \brief Logs a message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		virtual void log(const char *message, size_t messageSize, LogLevel level = LogLevel::Info,
						 const char *functionName = nullptr, size_t functionNameSize = 0,
						 int32_t lineNumber = -1,
						 const char *fileName = nullptr, size_t fileNameSize = 0) = 0;

		/// \brief Logs a message.
		/// \param message The message.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		virtual void log(const std::string &message, LogLevel level = LogLevel::Info,
						 const char *functionName = nullptr, size_t functionNameSize = 0,
						 int32_t lineNumber = -1,
						 const char *fileName = nullptr, size_t fileNameSize = 0) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		/// \param format The C-string format string.
		/// \param formatSize The format buffer size.
		/// \param args The variable arguments.
		virtual void logf(LogLevel level, const char *functionName, size_t functionNameSize,
						  int32_t lineNumber, const char *fileName, size_t fileNameSize,
						  const char *format, size_t formatSize, va_list args) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		/// \param format The format string.
		/// \param args The variable arguments.
		virtual void logf(LogLevel level, const char *functionName, size_t functionNameSize,
						  int32_t lineNumber, const char *fileName, size_t fileNameSize,
						  const std::string &format, va_list args) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param format The C-string format string.
		/// \param formatSize The format buffer size.
		/// \param args The variable arguments.
		virtual void logf(LogLevel level, const char *format, size_t formatSize, va_list args) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param format The format string.
		/// \param args The variable arguments.
		virtual void logf(LogLevel level, const std::string &format, va_list args) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		/// \param format The C-string format string.
		/// \param formatSize The format buffer size.
		/// \param ... The variable arguments.
		virtual void logf(LogLevel level, const char *functionName, size_t functionNameSize,
						  int32_t lineNumber, const char *fileName, size_t fileNameSize,
						  const char *format, size_t formatSize, ...) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		/// \param format The format string.
		/// \param ... The variable arguments.
		virtual void logf(LogLevel level, const char *functionName, size_t functionNameSize,
						  int32_t lineNumber, const char *fileName, size_t fileNameSize,
						  const std::string &format, ...) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param format The C-string format string.
		/// \param formatSize The format buffer size.
		/// \param ... The variable arguments.
		virtual void logf(LogLevel level, char *format, size_t formatSize, ...) = 0;

		/// \brief Logs a formatted message.
		/// \param level The log level for the message.
		/// \param format The format string.
		/// \param ... The variable arguments.
		virtual void logf(LogLevel level, const std::string &format, ...) = 0;

		/// \brief Logs a trace message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void trace(const char *message, size_t messageSize,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Trace,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a trace message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void trace(const std::string &message,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Trace,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a debug message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void debug(const char *message, size_t messageSize,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Debug,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a debug message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void debug(const std::string &message,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Debug,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a info message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void info(const char *message, size_t messageSize,
				  const char *functionName = nullptr, size_t functionNameSize = 0,
				  int32_t lineNumber = -1,
				  const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Info,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a info message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void info(const std::string &message,
				  const char *functionName = nullptr, size_t functionNameSize = 0,
				  int32_t lineNumber = -1,
				  const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Info,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a warn message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void warn(const char *message, size_t messageSize,
				  const char *functionName = nullptr, size_t functionNameSize = 0,
				  int32_t lineNumber = -1,
				  const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Warn,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a warn message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void warn(const std::string &message,
				  const char *functionName = nullptr, size_t functionNameSize = 0,
				  int32_t lineNumber = -1,
				  const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Warn,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a error message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void error(const char *message, size_t messageSize,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Error,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a error message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void error(const std::string &message,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Error,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a fatal message.
		/// \param message The C-string message.
		/// \param messageSize The message buffer size.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void fatal(const char *message, size_t messageSize,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, messageSize, LogLevel::Fatal,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

		/// \brief Logs a fatal message.
		/// \param message The message.
		/// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
		/// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
		/// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
		/// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
		/// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
		void fatal(const std::string &message,
				   const char *functionName = nullptr, size_t functionNameSize = 0,
				   int32_t lineNumber = -1,
				   const char *fileName = nullptr, size_t fileNameSize = 0)
		{
			log(message, LogLevel::Fatal,
				functionName, functionNameSize,
				lineNumber, fileName, fileNameSize);
		}

	protected:
		bool _isActive = false;
		LogLevel _level = LogLevel::Info;
	};

} // Ncl

#endif //NOVACOMMONLIBRARYNATIVE_LOGGER_H

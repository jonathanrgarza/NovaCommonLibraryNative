//
// Created by Jonathan on 7/8/22.
//

#ifndef NOVACOMMONLIBRARYNATIVE_LOGGER_H
#define NOVACOMMONLIBRARYNATIVE_LOGGER_H

#include <cstdint>
#include <cstdarg>
#include <string>
#include <iostream>

namespace Ncl
{
    /// \brief Represents a log level.
    enum class LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };
    
    /// \brief Base logger class. Contains typical log functions and properties.
    class Logger
    {
    public:
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
        virtual void log(char* message, size_t messageSize, LogLevel level = LogLevel::INFO, 
                         char* functionName = nullptr, size_t functionNameSize = 0, 
                         int32_t lineNumber = -1,
                         char* fileName = nullptr, size_t fileNameSize = 0) = 0;
        /// \brief Logs a message.
        /// \param message The message.
        /// \param level The log level for the message.
        /// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
        /// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
        /// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
        /// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
        /// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
        virtual void log(const std::string& message, LogLevel level = LogLevel::INFO,
                         char* functionName = nullptr, size_t functionNameSize = 0,
                         int32_t lineNumber = -1,
                         char* fileName = nullptr, size_t fileNameSize = 0) = 0;

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
        virtual void logf(LogLevel level, char* functionName, size_t functionNameSize,
                          int32_t lineNumber, char* fileName, size_t fileNameSize,
                          char* format, size_t formatSize, va_list args) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
        /// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
        /// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
        /// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
        /// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
        /// \param format The format string.
        /// \param args The variable arguments.
        virtual void logf(LogLevel level, char* functionName, size_t functionNameSize,
                          int32_t lineNumber, char* fileName, size_t fileNameSize,
                          const std::string& format, va_list args) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param format The C-string format string.
        /// \param formatSize The format buffer size.
        /// \param args The variable arguments.
        virtual void logf(LogLevel level, char* format, size_t formatSize, va_list args) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param format The format string.
        /// \param args The variable arguments.
        virtual void logf(LogLevel level, const std::string& format, va_list args) = 0;
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
        virtual void logf(LogLevel level, char* functionName, size_t functionNameSize,
                         int32_t lineNumber, char* fileName, size_t fileNameSize,
                         char* format, size_t formatSize, ...) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
        /// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
        /// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
        /// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
        /// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
        /// \param format The format string.
        /// \param ... The variable arguments.
        virtual void logf(LogLevel level, char* functionName, size_t functionNameSize,
                          int32_t lineNumber, char* fileName, size_t fileNameSize,
                          const std::string& format, ...) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param format The C-string format string.
        /// \param formatSize The format buffer size.
        /// \param ... The variable arguments.
        virtual void logf(LogLevel level, char* format, size_t formatSize, ...) = 0;
        /// \brief Logs a formatted message.
        /// \param level The log level for the message.
        /// \param format The format string.
        /// \param ... The variable arguments.
        virtual void logf(LogLevel level, const std::string& format, ...) = 0;

        /// \brief Logs a trace message.
        /// \param message The C-string message.
        /// \param messageSize The message buffer size.
        /// \param functionName The C-string function name. nullptr disables its inclusion. Default: nullptr
        /// \param functionNameSize The C-string function name size. 0 disables its inclusion. Default: 0
        /// \param lineNumber The line number associated with the message. -1 disables it inclusion. Default: -1
        /// \param fileName The C-string file name. nullptr disables its inclusion. Default: nullptr
        /// \param fileNameSize The C-string file name size. 0 disables its inclusion. Default: 0
        void trace(char* message, size_t messageSize,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::TRACE, 
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
        void trace(const std::string& message,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::TRACE,
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
        void debug(char* message, size_t messageSize,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::DEBUG,
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
        void debug(const std::string& message,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::DEBUG,
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
        void info(char* message, size_t messageSize,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::INFO,
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
        void info(const std::string& message,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::INFO,
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
        void warn(char* message, size_t messageSize,
                          char* functionName = nullptr, size_t functionNameSize = 0,
                          int32_t lineNumber = -1,
                          char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::WARN,
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
        void warn(const std::string& message,
                          char* functionName = nullptr, size_t functionNameSize = 0,
                          int32_t lineNumber = -1,
                          char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::WARN,
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
        void error(char* message, size_t messageSize,
                          char* functionName = nullptr, size_t functionNameSize = 0,
                          int32_t lineNumber = -1,
                          char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::ERROR,
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
        void error(const std::string& message,
                          char* functionName = nullptr, size_t functionNameSize = 0,
                          int32_t lineNumber = -1,
                          char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::ERROR,
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
        void fatal(char* message, size_t messageSize,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message, messageSize, LogLevel::FATAL,
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
        void fatal(const std::string& message,
                           char* functionName = nullptr, size_t functionNameSize = 0,
                           int32_t lineNumber = -1,
                           char* fileName = nullptr, size_t fileNameSize = 0)
        {
            log(message,LogLevel::FATAL,
                functionName, functionNameSize,
                lineNumber, fileName, fileNameSize);
        }
        
    protected:
        bool _isActive;
        LogLevel _level;
    };
    
    /// \brief A logger which primarly logs to a file.
    class FileLogger : Logger
    {
    public:
        /// \brief Initializes a new instance of FileLogger.
        FileLogger();

#if defined(_WIN32) || defined(_WIN64)
        FileLogger(std::string name, std::string version, std::string logPath, 
               bool includeConsoleOutput = false, bool includeDebugOutput = false);
#else
        FileLogger(std::string name, std::string version, std::string logPath,
                   bool includeConsoleOutput = false);
#endif
        //Properties
        
        //End Properties
        
    private:
        std::string _name;
        std::string _version;
        std::unique_ptr<std::ostream> _fstream;
        bool _isActive;
        bool _leaveOpen;
        bool _includeConsoleOutput;

#if defined(_WIN32) || defined(_WIN64)
        bool _includeDebugOutput;
#endif
        
    };
} // Ncl

#endif //NOVACOMMONLIBRARYNATIVE_LOGGER_H

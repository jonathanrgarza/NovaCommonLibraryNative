//
// Created by Jonathan on 8/25/2022.
//

#ifndef NOVACOMMONLIBRARYNATIVE_FILELOGGER_H
#define NOVACOMMONLIBRARYNATIVE_FILELOGGER_H

#include "Logger.h"

namespace Ncl {
/// \brief A logger which primarly logs to a file.
    class FileLogger : Logger {
    public:
        /// \brief Initializes a new instance of FileLogger.
        FileLogger();

#if defined(_WIN32) || defined(_WIN64)

        FileLogger(const std::string &name, const std::string &version, const std::string &logPath,
                   bool includeConsoleOutput = false, bool includeDebugOutput = false);

#else
        FileLogger(const std::string& name, const std::string& version, const std::string& logPath,
                       bool includeConsoleOutput = false);
#endif
        //Properties

        //End Properties

        void log(const char *message, size_t messageSize, Ncl::LogLevel level = LogLevel::INFO,
                 const char *functionName = nullptr, size_t functionNameSize = 0, int32_t lineNumber = -1,
                 const char *fileName = nullptr, size_t fileNameSize = 0) override;

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
}

#endif //NOVACOMMONLIBRARYNATIVE_FILELOGGER_H

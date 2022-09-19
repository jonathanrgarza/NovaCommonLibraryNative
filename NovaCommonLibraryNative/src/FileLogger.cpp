//
// Created by Jonathan on 8/25/2022.
//

#include "FileLogger.h"

using namespace Ncl;

FileLogger::FileLogger()
{

}

#if defined(_WIN32) || defined(_WIN64)
FileLogger::FileLogger(const std::string &name, const std::string &version, const std::string &logPath,
					   bool includeConsoleOutput, bool includeDebugOutput)
{
}
#else
FileLogger::FileLogger(const std::string &name, const std::string &version, const std::string &logPath,
					   bool includeConsoleOutput)
{
}
#endif

void FileLogger::log(const char *message, size_t messageSize, Ncl::LogLevel level, const char *functionName,
					 size_t functionNameSize, int32_t lineNumber, const char *fileName, size_t fileNameSize)
{
}

//
// Created by Jonathan on 8/25/2022.
//

#include "FileLogger.h"

using namespace Ncl;

FileLogger::FileLogger()
{

}

FileLogger::FileLogger(const std::string& name, const std::string& version, const std::string& logPath,
	bool includeConsoleOutput, bool includeDebugOutput)
{
}

void FileLogger::log(const char *message, size_t messageSize, Ncl::LogLevel level, const char *functionName,
                     size_t functionNameSize, int32_t lineNumber, const char *fileName, size_t fileNameSize)
{

}

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include "ANSI-color-codes.h"

//Declare loggerTesting function as a friend

class Logger {
public:
	enum LogLevel {
		INFO,
		WARNING,
		ERROR
	};

private:
	static Logger* instance;
	std::fstream logFile;
	std::map<std::string, clock_t> activeTicks;
	std::string logFileName;

	Logger(const std::string& filename = "application.log");

	static std::string getCurrentTimestamp();

	std::string getLogLevelString(Logger::LogLevel level);

	std::string getLogLevelColor(Logger::LogLevel level);

	void writeToConsole(const std::string& message, Logger::LogLevel level);

	void writeToFile(const std::string& message);

	std::string removeColourCodes(const std::string& input);

public:
	static Logger* getInstance(const std::string& filename = "application.log");

	void log(const std::string& message, const Logger::LogLevel level = INFO, bool toConsole = false);

	void info(const std::string& message);

	void warning(const std::string& message);

	void error(const std::string& message);

	void printLogFile() const;

	void clearLogs();

	std::string getLastLine(bool noTimestamp = true) const;

	~Logger();
};

#endif

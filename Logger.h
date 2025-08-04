#ifndef LOGGER_H
#define LOGGER_H

class Logger {

private:
	static Logger* instance;
	std::ofstream logFile;
	std::map<std::string, clock_t> activeTicks;
	std::string logFileName;

	Logger(const std::string& filename = "application.log");

	std::string getCurrentTimestamp();

	std::string getLogLevelString(Logger::LogLevel level);

	std::string getLogLevelColor(Logger::LogLevel level);

	void writeToConsole(const std::string& message, Logger::LogLevel level);

	void writeToFile(const std::string& message);

public:
	static Logger* getInstance(const std::string& filename = "application.log");

	void log(const std::string& message, Logger::LogLevel level, bool toConsole);

	void log(const std::string& message, Logger::LogLevel level = Logger.LogLevel.INFO);

	void info(const std::string& message);

	void warning(const std::string& message);

	void error(const std::string& message);

	void printRaw(const std::string& message);

	void printLogFile();

	void clearLogs();

	void ~Logger();

	enum LogLevel {
		INFO, 
		WARNING, 
		ERROR
	};
};

#endif

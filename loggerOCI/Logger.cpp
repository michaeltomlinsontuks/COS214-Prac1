//
// Logger.cpp - Singleton Logger Class Implementation
// Created by Michael Tomlinson
//

#include "Logger.h"
#include <map>

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance(const std::string& filename) {
    static Logger instance(filename); // Static for thread-safe singleton initialization
    return &instance;
}

Logger::Logger(const std::string& filename) : logFileName(filename) {
    logFile.open(logFileName, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Warning: Could not open log file '" << logFileName 
                  << "'. Logging to console only." << std::endl;
    }
}

std::string Logger::getCurrentTimestamp() {
    // Get current time - uses iostream not CHRONO
    time_t rawTime;
    time(&rawTime);
    
    struct tm* timeInfo = localtime(&rawTime);
    
    char buffer[32]; // Sufficient buffer size for [YYYY-MM-DD HH:MM:SS] + null terminator
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", timeInfo);
    
    return std::string(buffer);
}

std::string Logger::getLogLevelString(LogLevel level) {
    switch (level) {
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

std::string Logger::getLogLevelColor(LogLevel level) {
    switch (level) {
        case INFO:
            return WHT;
        case WARNING:
            return YEL;
        case ERROR:
            return RED;
        default:
            return WHT;
    }
}

void Logger::writeToConsole(const std::string& message, const LogLevel level) {
    // Print only the log level and message, no timestamp
    std::string levelStr = getLogLevelString(level);
    std::string colorCode = getLogLevelColor(level);
    std::cout << colorCode << "[" << levelStr << "] " << removeColourCodes(message) << CRESET << std::endl;
}

void Logger::writeToFile(const std::string& message) {
    if (!logFile.is_open()) {
        return;
    }
    
    try {
        std::string timestamp = getCurrentTimestamp();
        
        logFile << removeColourCodes(message) << std::endl;
        
        logFile.flush(); // Ensure data is written to disk immediately
        
        if (logFile.fail()) {
            // Log write failed, report to console and continue
            std::cerr << "Error: Failed to write to log file '" << logFileName 
                      << "'. Continuing with console logging only." << std::endl;
            
            // Close the file to prevent further write attempts
            logFile.close();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred while writing to log file: " << e.what()
                  << ". Continuing with console logging only." << std::endl;
        
        if (logFile.is_open()) {
            logFile.close();
        }
    }
}

void Logger::log(const std::string& message, LogLevel level, bool toConsole) {
    std::string timestamp = getCurrentTimestamp();
    std::string levelStr = getLogLevelString(level);
    if (toConsole) {
        writeToConsole(message, level);
    }
    std::string fileMessage = timestamp + " [" + levelStr + "] " + message;
    writeToFile(fileMessage);
}

void Logger::info(const std::string& message) {
    log(message, INFO);
}

void Logger::warning(const std::string& message) {
    log(message, WARNING);
}

void Logger::error(const std::string& message) {
    log(message, ERROR);
}

void Logger::clearLogs() {
    try {
        if (logFile.is_open()) {
            logFile.close();
        }
        logFile.open(logFileName, std::ios::out | std::ios::trunc);
        if (!logFile.is_open()) {
            std::cerr << "Error: Failed to clear log file '" << logFileName
                      << "'. Could not open file for truncation." << std::endl;
            return;
        }
        logFile.close();
        logFile.open(logFileName, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Error: Failed to reopen log file '" << logFileName
                      << "' after clearing. Continuing with console logging only." << std::endl;
            return;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred while clearing log file: " << e.what()
                  << ". Continuing with existing log file." << std::endl;
        if (!logFile.is_open()) {
            logFile.open(logFileName, std::ios::app);
            if (!logFile.is_open()) {
                std::cerr << "Warning: Could not reopen log file '" << logFileName 
                          << "'. Logging to console only." << std::endl;
            }
        }
    }
}

void Logger::printLogFile() const {
    std::ifstream inFile(logFileName);
    if (!inFile.is_open()) {
        std::cout << BHRED << "Could not open log file: " << logFileName << CRESET << std::endl;
        return;
    }
    std::string line;
    std::cout << BHYEL << "\n--- Log File Contents ---" << CRESET << std::endl;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << BHYEL << "--- End of Log File ---\n" << CRESET << std::endl;
    inFile.close();
}

// std::string Logger::removeColourCodes(const std::string& input) {
//     std::string output = input;
//
//     // Map ANSI escape sequences WITHOUT \e prefix (missing escape character)
//     const std::map<std::string, std::string> colorMapWithoutEscape = {
//         {"[1;41m", "[RED]"}, {"[1;42m", "[GRN]"}, {"[1;43m", "[YEL]"}, {"[1;44m", "[BLU]"},
//         {"[1;45m", "[MAG]"}, {"[1;46m", "[CYN]"}, {"[1;47m", "[WHT]"}, {"[1;40m", "[BLK]"},
//     };
//
//     for (const auto& pair : colorMapWithoutEscape) {
//         const std::string& code = pair.first;
//         const std::string& colorName = pair.second;
//
//         size_t pos = 0;
//         while ((pos = output.find(code, pos)) != std::string::npos) {
//             output.erase(pos, code.length());
//             output.insert(pos, colorName);
//             pos += colorName.length();
//         }
//     }
//     return output;
// }

std::string Logger::removeColourCodes(const std::string& input) {
    std::string output = input;

    // Map ANSI escape sequences WITH proper escape character
    const std::map<std::string, std::string> colorMap = {
        {"\e[1;41m", "[RED]"}, {"\e[1;42m", "[GRN]"}, {"\e[1;43m", "[YEL]"}, {"\e[1;44m", "[BLU]"},
        {"\e[1;45m", "[MAG]"}, {"\e[1;46m", "[CYN]"}, {"\e[1;47m", "[WHT]"}, {"\e[1;40m", "[BLK]"},
    };

    for (const auto& pair : colorMap) {
        const std::string& code = pair.first;
        const std::string& colorName = pair.second;

        size_t pos = 0;
        while ((pos = output.find(code, pos)) != std::string::npos) {
            output.erase(pos, code.length());
            output.insert(pos, colorName);
            pos += colorName.length();
        }
    }
    return output;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
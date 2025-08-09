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

std::string Logger::removeColourCodes(const std::string& input) {
    std::string output = input;

    // Map ANSI escape sequences to color names (with \e prefix)
    const std::map<std::string, std::string> colorMapWithEscape = {
        // Regular colors
        {"\e[0;30m", "[BLK]"},     {"\e[0;31m", "[RED]"},     {"\e[0;32m", "[GRN]"},     {"\e[0;33m", "[YEL]"},
        {"\e[0;34m", "[BLU]"},     {"\e[0;35m", "[MAG]"},     {"\e[0;36m", "[CYN]"},     {"\e[0;37m", "[WHT]"},

        // Bold colors
        {"\e[1;30m", "[BBLK]"},    {"\e[1;31m", "[BRED]"},    {"\e[1;32m", "[BGRN]"},    {"\e[1;33m", "[BYEL]"},
        {"\e[1;34m", "[BBLU]"},    {"\e[1;35m", "[BMAG]"},    {"\e[1;36m", "[BCYN]"},    {"\e[1;37m", "[BWHT]"},

        // Underlined colors
        {"\e[4;30m", "[UBLK]"},    {"\e[4;31m", "[URED]"},    {"\e[4;32m", "[UGRN]"},    {"\e[4;33m", "[UYEL]"},
        {"\e[4;34m", "[UBLU]"},    {"\e[4;35m", "[UMAG]"},    {"\e[4;36m", "[UCYN]"},    {"\e[4;37m", "[UWHT]"},

        // Background colors
        {"\e[40m", "[BLKB]"},      {"\e[41m", "[REDB]"},      {"\e[42m", "[GRNB]"},      {"\e[43m", "[YELB]"},
        {"\e[44m", "[BLUB]"},      {"\e[45m", "[MAGB]"},      {"\e[46m", "[CYNB]"},      {"\e[47m", "[WHTB]"},

        // Bold with background colors (common combinations)
        {"\e[1;41m", "[BRED_REDB]"}, {"\e[1;42m", "[BGRN_GRNB]"}, {"\e[1;43m", "[BYEL_YELB]"}, {"\e[1;44m", "[BBLU_BLUB]"},
        {"\e[1;45m", "[BMAG_MAGB]"}, {"\e[1;46m", "[BCYN_CYNB]"}, {"\e[1;47m", "[BWHT_WHTB]"}, {"\e[1;40m", "[BBLK_BLKB]"},

        // High intensity background colors
        {"\e[0;100m", "[BLKHB]"},  {"\e[0;101m", "[REDHB]"},  {"\e[0;102m", "[GRNHB]"},  {"\e[0;103m", "[YELHB]"},
        {"\e[0;104m", "[BLUHB]"},  {"\e[0;105m", "[MAGHB]"},  {"\e[0;106m", "[CYNHB]"},  {"\e[0;107m", "[WHTHB]"},

        // High intensity colors
        {"\e[0;90m", "[HBLK]"},    {"\e[0;91m", "[HRED]"},    {"\e[0;92m", "[HGRN]"},    {"\e[0;93m", "[HYEL]"},
        {"\e[0;94m", "[HBLU]"},    {"\e[0;95m", "[HMAG]"},    {"\e[0;96m", "[HCYN]"},    {"\e[0;97m", "[HWHT]"},

        // Bold high intensity colors
        {"\e[1;90m", "[BHBLK]"},   {"\e[1;91m", "[BHRED]"},   {"\e[1;92m", "[BHGRN]"},   {"\e[1;93m", "[BHYEL]"},
        {"\e[1;94m", "[BHBLU]"},   {"\e[1;95m", "[BHMAG]"},   {"\e[1;96m", "[BHCYN]"},   {"\e[1;97m", "[BHWHT]"},

        // Complex background combinations
        {"\e[1;30;101m", "[BHBLK_ON_REDHB]"}, {"\e[1;30;102m", "[BHBLK_ON_GRNHB]"}, {"\e[1;30;103m", "[BHBLK_ON_YELHB]"},
        {"\e[1;30;104m", "[BHBLK_ON_BLUHB]"}, {"\e[1;30;105m", "[BHBLK_ON_MAGHB]"}, {"\e[1;30;106m", "[BHBLK_ON_CYNHB]"},
        {"\e[1;30;107m", "[BHBLK_ON_WHTHB]"},

        // Reset codes
        {"\e[0m", "[RESET]"},
    };

    // Map ANSI escape sequences WITHOUT \e prefix (missing escape character)
    const std::map<std::string, std::string> colorMapWithoutEscape = {
        // Regular colors
        {"[0;30m", "[BLK]"},     {"[0;31m", "[RED]"},     {"[0;32m", "[GRN]"},     {"[0;33m", "[YEL]"},
        {"[0;34m", "[BLU]"},     {"[0;35m", "[MAG]"},     {"[0;36m", "[CYN]"},     {"[0;37m", "[WHT]"},

        // Bold colors
        {"[1;30m", "[BBLK]"},    {"[1;31m", "[BRED]"},    {"[1;32m", "[BGRN]"},    {"[1;33m", "[BYEL]"},
        {"[1;34m", "[BBLU]"},    {"[1;35m", "[BMAG]"},    {"[1;36m", "[BCYN]"},    {"[1;37m", "[BWHT]"},

        // Underlined colors
        {"[4;30m", "[UBLK]"},    {"[4;31m", "[URED]"},    {"[4;32m", "[UGRN]"},    {"[4;33m", "[UYEL]"},
        {"[4;34m", "[UBLU]"},    {"[4;35m", "[UMAG]"},    {"[4;36m", "[UCYN]"},    {"[4;37m", "[UWHT]"},

        // Background colors
        {"[40m", "[BLKB]"},      {"[41m", "[REDB]"},      {"[42m", "[GRNB]"},      {"[43m", "[YELB]"},
        {"[44m", "[BLUB]"},      {"[45m", "[MAGB]"},      {"[46m", "[CYNB]"},      {"[47m", "[WHTB]"},

        // Bold with background colors (the ones you're seeing)
        {"[1;41m", "[BRED_REDB]"}, {"[1;42m", "[BGRN_GRNB]"}, {"[1;43m", "[BYEL_YELB]"}, {"[1;44m", "[BBLU_BLUB]"},
        {"[1;45m", "[BMAG_MAGB]"}, {"[1;46m", "[BCYN_CYNB]"}, {"[1;47m", "[BWHT_WHTB]"}, {"[1;40m", "[BBLK_BLKB]"},

        // High intensity background colors
        {"[0;100m", "[BLKHB]"},  {"[0;101m", "[REDHB]"},  {"[0;102m", "[GRNHB]"},  {"[0;103m", "[YELHB]"},
        {"[0;104m", "[BLUHB]"},  {"[0;105m", "[MAGHB]"},  {"[0;106m", "[CYNHB]"},  {"[0;107m", "[WHTHB]"},

        // High intensity colors
        {"[0;90m", "[HBLK]"},    {"[0;91m", "[HRED]"},    {"[0;92m", "[HGRN]"},    {"[0;93m", "[HYEL]"},
        {"[0;94m", "[HBLU]"},    {"[0;95m", "[HMAG]"},    {"[0;96m", "[HCYN]"},    {"[0;97m", "[HWHT]"},

        // Bold high intensity colors
        {"[1;90m", "[BHBLK]"},   {"[1;91m", "[BHRED]"},   {"[1;92m", "[BHGRN]"},   {"[1;93m", "[BHYEL]"},
        {"[1;94m", "[BHBLU]"},   {"[1;95m", "[BHMAG]"},   {"[1;96m", "[BHCYN]"},   {"[1;97m", "[BHWHT]"},

        // Complex background combinations
        {"[1;30;101m", "[BHBLK_ON_REDHB]"}, {"[1;30;102m", "[BHBLK_ON_GRNHB]"}, {"[1;30;103m", "[BHBLK_ON_YELHB]"},
        {"[1;30;104m", "[BHBLK_ON_BLUHB]"}, {"[1;30;105m", "[BHBLK_ON_MAGHB]"}, {"[1;30;106m", "[BHBLK_ON_CYNHB]"},
        {"[1;30;107m", "[BHBLK_ON_WHTHB]"},

        // Reset codes
        {"[0m", "[RESET]"},
    };

    // First pass: Replace known color codes WITH escape character
    for (const auto& pair : colorMapWithEscape) {
        const std::string& code = pair.first;
        const std::string& colorName = pair.second;

        size_t pos = 0;
        while ((pos = output.find(code, pos)) != std::string::npos) {
            output.replace(pos, code.length(), colorName);
            pos += colorName.length();
        }
    }

    // Second pass: Replace known color codes WITHOUT escape character
    for (const auto& pair : colorMapWithoutEscape) {
        const std::string& code = pair.first;
        const std::string& colorName = pair.second;

        size_t pos = 0;
        while ((pos = output.find(code, pos)) != std::string::npos) {
            output.replace(pos, code.length(), colorName);
            pos += colorName.length();
        }
    }

    // Third pass: Handle any remaining unknown sequences (with \e)
    size_t pos = 0;
    while (pos < output.length()) {
        size_t escPos = output.find("\e[", pos);
        if (escPos == std::string::npos) {
            escPos = output.find("\033[", pos);
            if (escPos == std::string::npos) {
                break;
            }
        }

        size_t endPos = output.find('m', escPos);
        if (endPos == std::string::npos) {
            pos = escPos + 1;
            continue;
        }

        output.replace(escPos, endPos - escPos + 1, "[UNKNOWN_ESC]");
        pos = escPos + 13; // Length of "[UNKNOWN_ESC]"
    }

    // Fourth pass: Handle any remaining unknown sequences (without \e, just [*m format)
    pos = 0;
    while (pos < output.length()) {
        size_t bracketPos = output.find('[', pos);
        if (bracketPos == std::string::npos) {
            break;
        }

        // Check if this looks like a color code (contains digits/semicolons and ends with 'm')
        size_t endPos = output.find('m', bracketPos);
        if (endPos == std::string::npos || endPos - bracketPos > 20) { // Reasonable length limit
            pos = bracketPos + 1;
            continue;
        }

        // Check if the content between [ and m contains only digits, semicolons
        bool isColorCode = true;
        for (size_t i = bracketPos + 1; i < endPos; ++i) {
            char c = output[i];
            if (c != ';' && (c < '0' || c > '9')) {
                isColorCode = false;
                break;
            }
        }

        if (isColorCode) {
            output.replace(bracketPos, endPos - bracketPos + 1, "[UNKNOWN_CODE]");
            pos = bracketPos + 15; // Length of "[UNKNOWN_CODE]"
        } else {
            pos = bracketPos + 1;
        }
    }

    return output;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
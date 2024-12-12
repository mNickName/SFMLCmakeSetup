#include "Logger.h"

std::string Logger::getPrefixForLevel(Level level) const {
    switch (level) {
    case ERROR: return "[ERROR] ";
    case WARNING: return "[WARNING] ";
    case INFO: return "[INFO] ";
    case DEBUG: return "[DEBUG] ";
    case SUCCESS: return "[SUCCESS] ";
    default: return "[UNKNOWN] ";
    }
}

std::string Logger::getColorForLevel(Level level) const {
    switch (level) {
    case ERROR: return "\033[1;31m";   // Red
    case WARNING: return "\033[1;33m"; // Yellow
    case INFO: return "\033[1;34m";    // Blue
    case DEBUG: return "\033[0m";      // Default
    case SUCCESS: return "\033[1;32m"; // Green
    default: return "\033[0m";         // Default
    }
}

template <typename T>
std::string Logger::messageToString(const T& message) {
    return getColorForLevel(Level::DEBUG) + getPrefixForLevel(Level::DEBUG) + "(" + className + ") " + std::to_string(message) + "\033[0m";
}

std::string Logger::messageToString(const std::string& message, Level level) {
    return getColorForLevel(level) + getPrefixForLevel(level) + "(" + className + ") " + message + "\033[0m";
}

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::setClassName(std::string className)
{
    this->className = className;
}

void Logger::Log(std::string message, Level level)
{
    std::cout << messageToString(message, level) << std::endl;
}

template <typename T>
Logger& Logger::operator<<(const T& message) {
    std::string formattedMessage = messageToString(message);
    std::cout << formattedMessage << std::endl;
    return *this;
}

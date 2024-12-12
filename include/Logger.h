#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    // Poziomy logowania
    enum Level {
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        SUCCESS
    };

    explicit Logger();
    ~Logger();

    void setClassName(std::string className);

    template <typename T>
    Logger& operator<<(const T& message);

    void Log(std::string message, Level level);

private:
    std::string className;

    std::string getPrefixForLevel(Level level) const;
    std::string getColorForLevel(Level level) const;

    template <typename T>
    std::string messageToString(const T& message);
    std::string messageToString(const std::string& message, Level level);
};

#endif // LOGGER_H

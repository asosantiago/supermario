#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Logger {
private:
    string logLevel_;
    string name_;
    void logData(const string& level,const string& message);
    string getTimestamp();
    Logger() {logLevel_ = "ERROR";};
    ~Logger() {};
public:
    static Logger& getInstance(){
        static Logger instance;
        return instance;
    };
    //LOG 1-ERROR MSG
    void logError(const string& message);
    //LOG 2-INFO MSG
    void logInfo(const string& message);
    //LOG 3-DEBUG MSG
    void logDebug(const string& message);
    void createNameFile();
    string getName();
    string getLogLevel();
    void setName(string name);
    void setLogLevel(string level);
    // disable copy/move -- this is a Singleton
    Logger(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;
};

#endif //LOGGER_LOGGER_H

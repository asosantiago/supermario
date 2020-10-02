#include "Logger.h"
#include <cstring>
#include <iostream>

/* OPEN LOG FILE - WRITE MESSAGE*/
void Logger::logData(const string& level ,const string& message){
    ofstream file;
    file.open(this->getName(), ios::app);
    file << "[" + this->getTimestamp() + "]" << "[" + level + "]" << " - " << message << endl;
    file.close();
}

/* WRITE ERROR MESSAGE */ // ALWAYS
void Logger::logError(const string& message){
    this->logData("ERROR", message);
}

/* WRITE INFO MESSAGE */ // LEVEL INFO -> INFO + ERROR (ALWAYS)
void Logger::logInfo(const string& message){
    if (!(this->logLevel_.compare("DEBUG") * this->logLevel_.compare("INFO")))
        this->logData("INFO", message);
}


/* WRITE DEBUG MESSAGE */
void Logger::logDebug(const string& message){
    if (!this->logLevel_.compare("DEBUG"))
        this->logData("DEBUG", message);
}

void Logger::createNameFile(){
    name_ = this->getTimestamp() + ".log";
}

string Logger::getName() {
    return name_;
}

void Logger::setName(string name) {
    if (name_.empty()) {
        this->createNameFile();
        this->name_ = name + this->name_;
    }
}

string Logger::getLogLevel() {
    return logLevel_;
}

void Logger::setLogLevel(string level) {
    logLevel_ = level;
}

string Logger::getTimestamp() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 80, "%F %T", timeinfo);

    return string(buffer);
}

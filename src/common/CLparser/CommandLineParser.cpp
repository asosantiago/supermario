
#include "CommandLineParser.h"
#include <iostream>
using namespace std;

CommandLineParser::CommandLineParser() {
    Logger::getInstance().setName("log_");
}

string CommandLineParser::logLevelParsed(){
    return this->logLevelParsed_;
}

string CommandLineParser::configFileParsed(){
    return this->configFileParsed_;
}

void CommandLineParser::parseConfigFileAndLogLevel(int argc, const char** argv){
    Logger::getInstance().logDebug("CommandLineParser: CommandLineParser parseConfigFileAndLogLevel function called");
    for (int i = 0; i < argc; i++){
        Logger::getInstance().logDebug("CommandLineParser: argv[" + to_string(i) + "] = " + argv[i]);
        if(string(argv[i]) == "--config"){
            if(i + 1 < argc){
                this->configFileParsed_ = argv[i + 1];
                Logger::getInstance().logInfo("CommandLineParser: The config file parsed is " + this->configFileParsed_);
            }
        }
        else if(string(argv[i]) == "--log_level"){
            if(i + 1 < argc){
                string log_level = string(argv[i + 1]);
                if (log_level == "ERROR" || log_level == "INFO" || log_level == "DEBUG"){
                    this->logLevelParsed_ = log_level;
                    Logger::getInstance().setLogLevel(this->logLevelParsed_);
                    Logger::getInstance().logInfo("CommandLineParser: The log level set in the command line is: " + this->logLevelParsed_);
                }else{
                    Logger::getInstance().logError("CommandLineParser: Error in log level parsed. Log level: " + log_level);
                    Logger::getInstance().logError("CommandLineParser: Config file will be used");
                }
            }
        }
    }
    if (this->configFileParsed_.empty()) Logger::getInstance().logDebug("CommandLineParser: No configuration file was parsed in the command line");
    if (this->logLevelParsed_.empty()) Logger::getInstance().logDebug("CommandLineParser: No logger level was parsed in the command line");
}

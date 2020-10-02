#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include "../logger/Logger.h"

using namespace std;

class CommandLineParser{
    private:
        CommandLineParser();
        ~CommandLineParser() {};
        string logLevelParsed_;
        string configFileParsed_;
    public:
        static CommandLineParser& getInstance() {
            static CommandLineParser instance;
            return instance;
        }

        string logLevelParsed();
        string configFileParsed();
        void parseConfigFileAndLogLevel(int argc, const char** argv);

        // disable copy/move -- this is a Singleton
        CommandLineParser(const CommandLineParser&) = delete;
        CommandLineParser(CommandLineParser&&) = delete;
        CommandLineParser& operator=(const CommandLineParser&) = delete;
        CommandLineParser& operator=(CommandLineParser&&) = delete;
};

#endif //COMMAND_LINE_H

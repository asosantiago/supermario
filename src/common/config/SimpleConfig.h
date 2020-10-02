#ifndef SIMPLE_CONFIG_H
#define SIMPLE_CONFIG_H

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iomanip>
#include "../logger/Logger.h"
#include "../../models/factories/StageData.h"
#include "../CLparser/CommandLineParser.h"

#include "external_library/json-schema.hpp" // external library from https://github.com/pboettch/json-schema-validator
#include "external_library/json.hpp" //external library from  https://github.com/nlohmann/json#stl-like-access

using namespace std;
using json = nlohmann::json;

class SimpleConfig{
    private:
        SimpleConfig();
        ~SimpleConfig() {};
        string default_config_file;
    public:
        string getLogLevel();
        string getLogFilePath();
        string getPlayerName();
        string getPlayerSpaceship();
        string getDefaultSpaceship();
        float getPlayerAcceleration();
        float getEnemiesAcceleration();
        float getGameAcceleration();
        queue<StageData> getStages();
        void readJsonFile(string JsonConfigFileName);
        void validate();
        void validateFieldsInJson(vector<string> fields, json j, string section);
        void initLogger();
        // SimpleConfig(SimpleConfig const&);
        // void operator=(SimpleConfig const&);
        static SimpleConfig& getInstance()
        {
            static SimpleConfig instance;
            return instance;
        }
        json configuration;
        // disable copy/move -- this is a Singleton
        SimpleConfig(const SimpleConfig&) = delete;
        SimpleConfig(SimpleConfig&&) = delete;
        SimpleConfig& operator=(const SimpleConfig&) = delete;
        SimpleConfig& operator=(SimpleConfig&&) = delete;
};

#endif //SIMPLE_CONFIG_H

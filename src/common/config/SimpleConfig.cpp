#include "SimpleConfig.h"

using namespace std;

SimpleConfig::SimpleConfig() {
    default_config_file = "src/common/config/default_config.json";
    Logger::getInstance().setName("log_");
    string config_file = CommandLineParser::getInstance().configFileParsed();
    if (config_file.empty()) {
        config_file = default_config_file;
        Logger::getInstance().logError("SimpleConfig: No configuration file via cli, using " + config_file);
    }
    try {
        readJsonFile(config_file);
        validate();
    } catch (std::runtime_error& e) {
        Logger::getInstance().logError("SimpleConfig: Could not parse config, will use default.");
        readJsonFile(default_config_file);
    }
    if (CommandLineParser::getInstance().logLevelParsed().empty()){
        Logger::getInstance().setLogLevel(this->getLogLevel());
        Logger::getInstance().logInfo("Set config file log level: " + this->getLogLevel());
    }
    
}

string SimpleConfig::getLogLevel() {
    return this->configuration["log_level"];
}

string SimpleConfig::getPlayerName() {
    return this->configuration["player_name"];
}

string SimpleConfig::getPlayerSpaceship() {
    return this->configuration["player_spaceship"];
}

string SimpleConfig::getDefaultSpaceship() {
    return this->configuration["default_spaceship"];
}

float SimpleConfig::getPlayerAcceleration() {
    return this->configuration["player_acceleration"];
}

float SimpleConfig::getEnemiesAcceleration() {
    return this->configuration["enemies_acceleration"];
}

float SimpleConfig::getGameAcceleration() {
    return this->configuration["game_acceleration"];
}

queue<StageData> SimpleConfig::getStages() {
    queue<StageData> stages;
    for (auto stageConfig : this->configuration["stages"]) {

        vector<EnemyData> enemies;
        for (auto enemy : stageConfig["enemies"])
            enemies.push_back(EnemyData(enemy["path"], enemy["path_flipped"], this->configuration["default_spaceship"], enemy["quantity"], enemy["type"]));
        Logger::getInstance().logDebug("SimpleConfig: " + to_string(enemies.size()) + " enemies added to vector<EnemyData>.");
        
        vector<BackgroundData> backgrounds;
        for (auto background : stageConfig["background"])
            backgrounds.push_back(BackgroundData(background["path"], this->configuration["default_background"], PositionData(background["position"]["x"], background["position"]["y"]), background["type"], background["speed"]));
        Logger::getInstance().logDebug("SimpleConfig: " + to_string(backgrounds.size()) + " backgrounds added to vector<BackgroundData>.");

        stages.push(StageData(stageConfig["name"], stageConfig["stage_length"], enemies, backgrounds));
    }
    Logger::getInstance().logDebug("SimpleConfig: " + to_string(stages.size()) + " stages added to queue<StageData>.");

    return stages;
}

string SimpleConfig::getLogFilePath() {
    return this->configuration["log_file_path"];
}

void SimpleConfig::readJsonFile(string jsonConfigFileName){
    Logger::getInstance().logDebug("SimpleConfig: About to parse file in path: " + jsonConfigFileName);
    
    ifstream jsonStream(jsonConfigFileName); 
    if (!jsonStream.is_open()) {
        if (!jsonConfigFileName.empty()) {
            Logger::getInstance().logError("SimpleConfig: The file " + jsonConfigFileName + " passed via cli couldn't be opened. The default configuration file will be used.");
        } else {
            Logger::getInstance().logInfo("SimpleConfig: Since the jsonConfigFileName is empty, the default Config file will be used: " + default_config_file);
        }
        this->readJsonFile(default_config_file);
        return;
    } else {
        try{
            jsonStream >> this->configuration;
            Logger::getInstance().logDebug("SimpleConfig: Configuration file parsed and loaded into Config object.");
        } catch (exception& e) {
            Logger::getInstance().logError("SimpleConfig: Couldn't parse configuration file -  " + string(e.what()) + " - Default configuration file will be used " + default_config_file);
            try {
                this->readJsonFile(default_config_file);
            } catch (std::runtime_error& e){
                throw std::runtime_error("Error at loadDefaultFile");
            }
        }
    }
}

void SimpleConfig::validate() {
    vector<string> required_fields = {"log_level", "player_name", "player_spaceship", "default_background", "default_spaceship", "player_acceleration", "enemies_acceleration", "game_acceleration", "stages"};
    validateFieldsInJson(required_fields, this->configuration, "root");

    int stage_n = 1;
    for (auto stage : this->configuration["stages"]) {
        required_fields = {"name", "stage_length", "enemies", "background"};
        validateFieldsInJson(required_fields, stage, "Error in stage " + to_string(stage_n));

        int enemies_n = 1;
        for (auto enemy : stage["enemies"]) {
            required_fields = {"path", "path_flipped", "quantity", "type"};
            validateFieldsInJson(required_fields, enemy, "Error in stage " + to_string(stage_n) + " Enemy " + to_string(enemies_n));
            enemies_n++;
        }

        int background_n = 1;
        for (auto background : stage["background"]) {
            required_fields = {"path", "position", "type", "speed"};
            validateFieldsInJson(required_fields, background, "Error in stage " + to_string(stage_n) + " Background " + to_string(background_n));
            background_n++;
        }
        stage_n++;
    }
}

void SimpleConfig::validateFieldsInJson(vector<string> fields, json j, string msg) {
    for (auto field : fields) {
        if (j[field] == nullptr) {
            string message = "Error! - Field " + field + " is required - " + msg;
            Logger::getInstance().logError("SimpleConfig: " + message);
            throw std::runtime_error(message);
        }
    }
}

void SimpleConfig::initLogger() {
    Logger::getInstance().setLogLevel(getLogLevel());
}

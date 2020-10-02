#include "Game.h"
#include <iostream>
#include <memory>
#include <experimental/filesystem>
using namespace std;

//The event structure that will be used
SDL_Event event;

Game::Game() {
    stages_data = SimpleConfig::getInstance().getStages();

    this->initGame();
    this->createCharacter();
    this->nextStage();
};

void Game::start() {
    Logger::getInstance().logInfo("Game: Finished setup, starting game!");
    gameLoop();
};

void Game::initGame(){
    Renderer::getInstance().initScreen();
};

void Game::gameLoop() {
    bool quit = false;

    while(!quit) {
        while(SDL_PollEvent(&event)) {
            //If the user has Xed out the window or pressed escape
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                Logger::getInstance().logInfo("Game: User quit the game!");
                quit = true;
            }
        }
        this->refresh();
        if (current_stage.is_finished()) {
            Logger::getInstance().logInfo("Game: Stage: " + current_stage.get_name() + " is finished");
            if (!this->isNextStage())
                quit = true;
            else
                this->nextStage();
        }
    }
    Renderer::getInstance().close();
};

void Game::refresh() {
    this->updateComponents();
    this->updateStage();
    this->updateCharacters();
    this->refreshView();
};

void Game::updateComponents() {
    InputComponent::getInstance().update();
};

void Game::createCharacter() {
    string player_name = SimpleConfig::getInstance().getPlayerName();
    Logger::getInstance().logInfo("Game: Creating Player: " + player_name);
    string player_spaceship = SimpleConfig::getInstance().getPlayerSpaceship();
    //TODO: Make CharacterFactory and do this validation there
    if (!filesystem::exists(player_spaceship)) {
        Logger::getInstance().logError("Game: File: " + player_spaceship + " does not exists, loading default");
        player_spaceship = SimpleConfig::getInstance().getDefaultSpaceship();
    }
    character = Character(Position(100,SimpleConfig::getInstance().getInitialPositionY()), player_name, player_spaceship);
}
void Game::updateCharacters() {
    character.update();
};

void Game::updateStage() {
    current_stage.update();
};

void Game::nextStage() {
    StageData data = stages_data.front();
    Logger::getInstance().logInfo("Game: Loading stage: " + data.name);
    current_stage = StageFactory(data).build();
    stages_data.pop();
}

bool Game::isNextStage() {
    if (stages_data.empty())
        Logger::getInstance().logInfo("Game: There are no more stages, quitting game!");
    return !stages_data.empty();
}

void Game::refreshView() {
    Renderer::getInstance().refresh();
};

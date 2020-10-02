#include "Game.h"
#include <iostream>
#include <memory>
#include <experimental/filesystem>
using namespace std;

//The event structure that will be used
SDL_Event event;

Game::Game() {
    stages_data = SimpleConfig::getInstance().getStages();
    this->restart = false;
    this->initGame();
    this->createCharacter();
    this->current_stage_data = stages_data.front();
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
    this->restart = false;

    while(!quit) {
        while(SDL_PollEvent(&event)) {
            //If the user has Xed out the window or pressed escape
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                Logger::getInstance().logInfo("Game: User quit the game!");
                quit = true;
            }
        }

        if (this->restart) {
            this->createCharacter();
            current_stage = StageFactory(current_stage_data).build();
        }
        this->restart = false;

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
    this->checkCollitions();
    this->doUpdateCharacters();
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

void Game::doUpdateCharacters() {
    character.doUpdate();
};

void Game::updateStage() {
    current_stage.update();
};

void Game::checkCollitions() {
    vector<shared_ptr<Enemy>> enemies = current_stage.getEnemies();
    int char_lim_right = character.getRightLimit();
    int char_lim_left = character.getLeftLimit();
    int char_lim_down = character.getDownLimit();

    for (int i = 0; i < enemies.size(); i++) {
        
        int enemy_lim_right = enemies[i]->getRightLimit();
        int enemy_lim_left = enemies[i]->getLeftLimit();
        int enemy_lim_down = enemies[i]->getDownLimit();
        int enemy_lim_up = enemies[i]->getUpLimit();

        bool col = false;

        if (char_lim_left > enemy_lim_left && char_lim_left < enemy_lim_right ) {
            if (char_lim_down > enemy_lim_up) {
                col = true;
            }
        }

        if (char_lim_right > enemy_lim_left && char_lim_right < enemy_lim_right ) {
            if (char_lim_down > enemy_lim_up) {
                col = true;
            }
        }

        if (char_lim_left < enemy_lim_left && char_lim_right > enemy_lim_right ) {
            if (char_lim_down > enemy_lim_up) {
                col = true;
            }
        }

        if (col) {
            const SDL_MessageBoxButtonData buttons[] = {
                { /* .flags, .buttonid, .text */        0, 0, "si" },
                { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" }
            };
            const SDL_MessageBoxColorScheme colorScheme = {
                { /* .colors (.r, .g, .b) */
                    /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
                    { 255,   0,   0 },
                    /* [SDL_MESSAGEBOX_COLOR_TEXT] */
                    {   0, 255,   0 },
                    /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
                    { 255, 255,   0 },
                    /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
                    {   0,   0, 255 },
                    /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
                    { 255,   0, 255 }
                }
            };
            const SDL_MessageBoxData messageboxdata = {
                SDL_MESSAGEBOX_INFORMATION, /* .flags */
                NULL, /* .window */
                "PERDISTE GATE", /* .title */
                "Try again?", /* .message */
                SDL_arraysize(buttons), /* .numbuttons */
                buttons, /* .buttons */
                &colorScheme /* .colorScheme */
            };
            int buttonid;
            if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
                SDL_Log("error displaying message box");
            }
            if (buttonid == -1) {
                SDL_Log("no selection");
            } else {
                this->restart = true;
                SDL_Log("selection was %s", buttons[buttonid].text);
            }
        }
    }
};

void Game::nextStage() {
    current_stage_data = stages_data.front();
    Logger::getInstance().logInfo("Game: Loading stage: " + current_stage_data.name);
    current_stage = StageFactory(current_stage_data).build();
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

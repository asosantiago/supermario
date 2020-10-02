#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>

#include "../../components/InputComponent.h"
#include "../../services/Renderer.h"
#include "../characters/Character.h"
#include "../../common/config/SimpleConfig.h"
#include "../factories/StageData.h"
#include "../factories/StageFactory.h"


using namespace std;

class Game {
    private:
        queue<StageData> stages_data;
        Character character;
        Stage current_stage;
    public:
        Game();
        void initGame();
        void initScreen();
        void start();
        void gameLoop();
        void refresh();
        void createCharacter();
        void updateCharacters();
        void doUpdateCharacters();
        void updateComponents();
        void updateStage();
        void checkCollitions();
        bool checkCollition(Character character, Enemy enemy);
        void nextStage();
        bool isNextStage();
        void refreshView();
        ~Game() {};
};

#endif // GAME_H

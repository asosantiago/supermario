#include <iostream>

#include "models/game/Game.h"
#include "common/CLparser/CommandLineParser.h"

int main(int argc, const char** argv) {
    CommandLineParser::getInstance().parseConfigFileAndLogLevel(argc, argv);
    
    Game game = Game();
    game.start();

    return 0;
}

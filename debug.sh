set -o errexit

g++ -c src/main.cpp -O0 -g -std=c++17
# Common
g++ -c src/models/Screen.cpp -O0 -g -std=c++17
g++ -c src/models/game/Game.cpp -O0 -g -std=c++17
g++ -c src/models/Position.cpp -O0 -g -std=c++17
g++ -c src/common/config/SimpleConfig.cpp -O0 -g -std=c++17
g++ -c src/common/logger/Logger.cpp -O0 -g -std=c++17
g++ -c src/common/CLparser/CommandLineParser.cpp -O0 -g -std=c++17
# Models
g++ -c src/models/characters/Character.cpp -O0 -g -std=c++17
g++ -c src/models/characters/Enemy.cpp -O0 -g -std=c++17
g++ -c src/models/characters/SpaceShip.cpp -O0 -g -std=c++17
# Services
g++ -c src/services/Renderer.cpp -O0 -g -std=c++17
g++ -c src/components/InputComponent.cpp -O0 -g -std=c++17
# Background
g++ -c src/models/background/Background.cpp -O0 -g -std=c++17
g++ -c src/models/background/Layer.cpp -O0 -g -std=c++17
g++ -c src/models/background/CommonLayer.cpp -O0 -g -std=c++17
g++ -c src/models/background/ContinuousLayer.cpp -O0 -g -std=c++17
# Stage
g++ -c src/models/stage/Stage.cpp -O0 -g -std=c++17
# Factories
g++ -c src/models/factories/BackgroundFactory.cpp -O0 -g -std=c++17
g++ -c src/models/factories/EnemyFactory.cpp -O0 -g -std=c++17
g++ -c src/models/factories/StageFactory.cpp -O0 -g -std=c++17

g++ -Wall *.o -o game -lSDL2 -lSDL2_image -O0 -g -std=c++17 -lstdc++fs

rm *.o

gdb game_debug

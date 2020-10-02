set -o errexit

g++ -c src/main.cpp -std=c++17
# Common
g++ -c src/models/Screen.cpp -std=c++17
g++ -c src/models/game/Game.cpp -std=c++17
g++ -c src/models/Position.cpp -std=c++17
g++ -c src/common/config/SimpleConfig.cpp -std=c++17
g++ -c src/common/logger/Logger.cpp -std=c++17
g++ -c src/common/CLparser/CommandLineParser.cpp -std=c++17
# Models
g++ -c src/models/characters/Character.cpp -std=c++17
g++ -c src/models/characters/Enemy.cpp -std=c++17
g++ -c src/models/characters/SpaceShip.cpp -std=c++17
# Services
g++ -c src/services/Renderer.cpp -std=c++17
g++ -c src/components/InputComponent.cpp -std=c++17
# Background
g++ -c src/models/background/Background.cpp -std=c++17
g++ -c src/models/background/Layer.cpp -std=c++17
g++ -c src/models/background/CommonLayer.cpp -std=c++17
g++ -c src/models/background/ContinuousLayer.cpp -std=c++17
# Stage
g++ -c src/models/stage/Stage.cpp -std=c++17
# Factories
g++ -c src/models/factories/BackgroundFactory.cpp -std=c++17
g++ -c src/models/factories/EnemyFactory.cpp -std=c++17
g++ -c src/models/factories/StageFactory.cpp -std=c++17

g++ -Wall *.o -o game -lSDL2 -lSDL2_image -std=c++17

rm *.o

#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL2/SDL.h>
#include <vector>
#include "Component.h"

#define MAX_NUMBER_OF_INPUTS 5

class InputComponent : public Component {
private:
    const Uint8* keyboard_state;
    std::vector<bool> keys_held;
public:
    InputComponent(InputComponent const&);
    void operator=(InputComponent const&);
    static InputComponent& getInstance()
    {
        static InputComponent instance;
        return instance;
    }
    InputComponent();
    virtual void update();
    const Uint8* get_keyboard_state();
    std::vector<bool> get_user_input();
    ~InputComponent();
};

enum player_actions {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    SHOOT
};

#endif // INPUT_COMPONENT_H

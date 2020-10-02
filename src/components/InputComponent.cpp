#include "InputComponent.h"

InputComponent::InputComponent() : keys_held(MAX_NUMBER_OF_INPUTS, false) {
    this->keyboard_state = SDL_GetKeyboardState(NULL);
}

void InputComponent::update() {
    SDL_PumpEvents();

    this->keys_held[UP] = keyboard_state[SDL_SCANCODE_W] ? true : false;
    this->keys_held[LEFT] = keyboard_state[SDL_SCANCODE_A] ? true : false;
    this->keys_held[DOWN] = keyboard_state[SDL_SCANCODE_S] ? true : false;
    this->keys_held[RIGHT] = keyboard_state[SDL_SCANCODE_D] ? true : false;
    this->keys_held[SHOOT] = keyboard_state[SDL_SCANCODE_SPACE] ? true : false;
}

const Uint8* InputComponent::get_keyboard_state() {
    return this->keyboard_state;
}
std::vector<bool> InputComponent::get_user_input() {
    return this->keys_held;
}

InputComponent::~InputComponent() {}

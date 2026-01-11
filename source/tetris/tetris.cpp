#include "tetris.hpp"

Tetris::Tetris(){
    initialize();
}

Tetris::~Tetris(){

}

void Tetris::initialize(){
    gameScreen.initialize(Constants::GAME_SCREEN, MODE_0_2D);
    uiScreen.initialize(Constants::UI_SCREEN, MODE_0_2D);
}

void Tetris::gameLoop(){

}
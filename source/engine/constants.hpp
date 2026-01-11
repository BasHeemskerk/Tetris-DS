#pragma once

#include <nds.h>

//the Constants namespace holds variables that never change and are precomputed at compilation
// Constants is included in every single cpp file i create
namespace Constants{
    static constexpr int GAME_SCREEN = 0; //where we let our blocks fall
    static constexpr int UI_SCREEN = 1; //where we show our score and next piece
    static constexpr int MAIN_SCREEN = GAME_SCREEN; //our game screen is always our main screen!
}
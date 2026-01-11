#pragma once

#include <nds.h>

//the Constants namespace holds variables that never change and are precomputed at compilation
// Constants is included in every single cpp file i create
namespace Constants{
    inline constexpr int GAME_SCREEN = 0; //where we let our blocks fall
    inline constexpr int UI_SCREEN = 1; //where we show our score and next piece
    inline constexpr int MAIN_SCREEN = GAME_SCREEN; //our game screen is always our main screen!

    inline constexpr int TILE_COLORS[] = {
        RGB15(31, 7, 11),   // SALMON
        RGB15(31, 25, 5),   // ORANGE
        RGB15(31, 31, 6),   // YELLOW
        RGB15(10, 27, 7),   // GREEN
        RGB15(0, 29, 31),   // CYAN
        RGB15(27, 1, 22),   // PURPLE
        RGB15(29, 2, 3),    // RED
        RGB15(31, 9, 3),    // DARK ORANGE
        RGB15(31, 18, 1),   // SANDY BROWN
        RGB15(7, 17, 5),    // DARK GREEN
        RGB15(0, 14, 26),   // BLUE
        RGB15(15, 4, 13),   // DARK PURPLE
        RGB15(5, 5, 16),    // NAVY
        RGB15(9, 11, 24)   // DARK MED BLUE
    };
}
#pragma once

#include "../constants.hpp"

#include <string.h>

class Renderer{
    public:
        Renderer();
        ~Renderer();

        void initialize(int SCREEN, int MODE); //initialize our rendering system
        void createTiles();
        void createPalettes();
        void clearMap();


    private:
        int m_screen;
        int m_bgId;
        u16* m_mapPtr;
        u16* m_tilePtr;
};
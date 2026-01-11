#include "renderer.hpp"

Renderer::Renderer(){

}

Renderer::~Renderer(){
    
}

void Renderer::initialize(int SCREEN, int MODE){
    if (SCREEN == Constants::MAIN_SCREEN){
        //check if we are initializing our main screen
        videoSetMode(MODE | DISPLAY_BG0_ACTIVE);
        vramSetBankA(VRAM_A_MAIN_BG);

        //initialize background
        m_bgId = bgInit(0, BgType_Text8bpp, BgSize_T_256x256, 0, 1);
    } else {
        //if this screen is not our main screen it must be our subscreen
        videoSetModeSub(MODE | DISPLAY_BG0_ACTIVE);
        vramSetBankC(VRAM_C_SUB_BG);

        //initialize background
        m_bgId = bgInitSub(0, BgType_Text8bpp, BgSize_T_256x256, 0, 1);
    }

    //get our pointers
    m_mapPtr = bgGetMapPtr(m_bgId);
    m_tilePtr = bgGetGfxPtr(m_bgId);

    //store our screen
    m_screen = SCREEN;

    createTiles();
    createPalettes();
    clearMap();

    m_mapPtr[0] = 1;
}

void Renderer::createTiles(){
    u8* tileMemory = (u8*)m_tilePtr;
    for (int i = 0; i < 15; i++){
        memset(&tileMemory[i * 64], i, 64);
    }
}

void Renderer::createPalettes(){
    if (m_screen == Constants::MAIN_SCREEN){
        BG_PALETTE[0] = RGB15(0, 0, 0);
        for (int i = 0; i < 14; i++){
            BG_PALETTE[i + 1] = Constants::TILE_COLORS[i];
        }
    } else {
        BG_PALETTE_SUB[0] = RGB15(0, 0, 0);
        for (int i = 0; i < 14; i++){
            BG_PALETTE_SUB[i + 1] = Constants::TILE_COLORS[i];
        }
    }
}

void Renderer::clearMap(){
    memset(m_mapPtr, 0, 2048);
}
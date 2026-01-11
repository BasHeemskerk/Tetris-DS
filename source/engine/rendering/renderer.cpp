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
}
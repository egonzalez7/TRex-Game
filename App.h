#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"

#include "Game.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
  
    
    bool game_over;
    void idle();
    bool moving;
    Game* game;
};

#endif

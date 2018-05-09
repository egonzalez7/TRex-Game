#include "App.h"

static App* singleton;

void app_timer(int value){
    
    singleton->game->moveDesert();
    singleton->game->moveGround();
    singleton->game->moveCactus();
    singleton->game->moveClouds();
    singleton->game->Dino->advance();
    singleton->game->movePowerUp();
    singleton->game->showPowerUp();
    singleton->game->moveDino();
    singleton->game->Numbers->animate();
    singleton->game->Numbers2->animate();
    singleton->game->Numbers3->animate();
    singleton->game->Numbers4->animate();
    singleton->game->Game_Over->animate();
    singleton->game->Game_Over;
    singleton->game->Game_Over->advance();
    singleton->redraw();
    
    glutTimerFunc(25, app_timer, value);

}

  
    
  

bool tenth = false;
bool hundredth = false;

int counter = 0;

void score(int value){
 singleton->game->Score();
    
    glutTimerFunc(400, score, value);
}


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
  
    
    game_over = false;
    game = new Game ();
    app_timer(1);
    score(2);
   
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game->draw();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::idle(){
     game->livesChanges();
  //  game->draw();
 //   game->overlapping= true;
   game->livesChanges2();
  //  game->draw();

}

void App::keyUp(unsigned char key){
    if (key == ' '){
        
        game->dinoFall();
    }
}
void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete game;
  
        exit(0);
    }
    
    if (key == ' '){
        game->dinoJump();
        
        
    }
    if (key == 'p'){
        game->pauseGame();
        
   }
    if (key == 'r') {
        game->resumeGame();
    }
    if (key == 's'){
        game->reset();
        
    }
}

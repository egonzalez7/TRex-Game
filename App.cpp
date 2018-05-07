#include "App.h"

static App* singleton;

void app_timer(int value){
    
    singleton->game->moveDesert();
    singleton->game->moveGround();
    singleton->game->moveCactus();
    singleton->game->moveClouds();
   // singleton->game->Dino->advance();
    singleton->game->movePowerUp();
    singleton->game->showPowerUp();
    singleton->game->moveDino();
    
    singleton->redraw();
    
    glutTimerFunc(25, app_timer, value);

    
//   if (singleton->game_over){
//        singleton->game->dino();
//  }
//    if (singleton->game){
//            singleton->game->advance();
//    }
//
  
    
}
//void dinoRun(int value){
//      if (!singleton->game->Dino->done()){ // added done into TexRect.h
//            singleton->game->Dino->advance(); // added advanced into TexRect.h
//            singleton->redraw();
//            glutTimerFunc(32, dinoRun, value);
//      }
//}

bool tenth = false;
bool hundredth = false;

int counter = 0;

void score(int value){

    counter++;
    
    singleton->game->Numbers->advance();
    
    if (counter % 10 == 0){
        singleton->game->Numbers2->advance();
    }
    
    if (counter % 100 == 0){
        singleton->game->Numbers3->advance();
    }
    
    if (counter % 1000 == 0){
        singleton->game->Numbers4->advance();
    }

    glutTimerFunc(600, score, value);
}



App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
  
    
 game_over = false;
    game = new Game ();
    app_timer(1);
   // dinoRun(1);
    score(2);
    game->liveChanges();
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
  game->liveChanges();
//    // dinoRun(1);
//   // score(1);
   // game->Dino->advance();

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
}

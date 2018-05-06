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
   //singleton->game->Numbers->advance();
    
    singleton->redraw();
    
    glutTimerFunc(16, app_timer, value);

    
   // if (singleton->game_over){
     //   singleton->game->dino();
    //}
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
void score(int value){
    if (!singleton->game->Numbers->done()){ // added done into TexRect.h
        singleton->game->Numbers->advance(); // added advanced into TexRect.h
        singleton->redraw();
        glutTimerFunc(2, score, value);
    }
}
//        else{
//            singleton->redraw();
//        }
//        singleton->ball->jump();
//        float bx = singleton->ball->x + singleton->ball->w/2;
//        float by = singleton->ball->y - singleton->ball->h + 0.1;
//        if (singleton->platform->contains(bx, by)){
//            singleton->ball->rising = true;
//            singleton->ball->yinc +=0.005;
//            singleton->ball->xinc = singleton->ball->yinc;
//            if (singleton->ball->yinc > 0.15){
//                singleton->ball->yinc = 0.15;
//            }
//        }
//        
//        if (singleton->ball->y - singleton->ball->h < -0.99){
//            singleton->moving = false;
//            singleton->game_over = true;
//            singleton->gameOver->animate();
//            
//        }
//    }
//    if (singleton->up){
//        singleton->platform->moveUp(0.05);
//    }
//    if (singleton->down){
//        singleton->platform->moveDown(0.05);
//    }
//    if (singleton->left){
//        singleton->platform->moveLeft(0.05);
//    }
//    if (singleton->right){
//        singleton->platform->moveRight(0.05);
//    }
//    
//    if (singleton->game_over){
//        singleton->redraw();
//        glutTimerFunc(100, app_timer, value);
//    }
//    else{
//        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
//            singleton->redraw();
//            glutTimerFunc(16, app_timer, value);
//        }
//    }
    
    
//}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
  
    
 game_over = false;
    game = new Game ();
    app_timer(1);
   // dinoRun(1);
}
/*
void App::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
            left = true;
        }
        if (key == 101){
            //up = true;
        }
        if (key == 102){
            right = true;
        }
        if (key == 103){
            //down = true;
        }
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
    }
}
*/
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
/*
void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

}
*/
void App::idle(){
  // game->lifeChanges();
//    // dinoRun(1);
//   // score(1);
//   // game->Dino->advance();
//
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

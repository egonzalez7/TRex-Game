#include <iostream>
#include <thread>
#include "Game.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Game::Game(){
    
    Dino = new AnimatedRect("images/dino.png",3,2, -.9,-.30, .5,.4 );
    
    Ground = new TexRect("images/ground.png", -1., -0.5, 2.2 , 0.5);
    Ground2 = new TexRect("images/ground.png", 1, -0.5, 2.4, 0.5);

    Desert = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    Desert2 = new TexRect("images/desert.png", 1, 1.1, 2.3, 2);
  
   
    Cactus1 = new TexRect("images/cactus.png", 0.8, -0.38, 0.3, 0.3);
    Cactus2 = new TexRect("images/cactus.png", 2.0, -0.38, 0.3, 0.3);
    FiestaCactus = new TexRect("images/fiestaCactus.png", 1.2, -0.38, 0.3, 0.3);
    
   
    Cloud = new TexRect("images/cloud.png", 1,.7 , .3, .3);
    Cloud2 = new TexRect("images/cloud.png", 1.7,.45 , .3, .3);
   
    Numbers= new AnimatedRect("images/numbers.png",2,5,.9,.8,.1,.1);
    Numbers2= new AnimatedRect("images/numbers.png",2,5,.8,.8,.1,.1);
    Numbers3= new AnimatedRect("images/numbers.png",2,5,.7,.8,.1,.1);
    Numbers4= new AnimatedRect("images/numbers.png",2,5,.6,.8,.1,.1); 

    
    Life1 = new TexRect ("images/heart.png", 0.9, 0.95, 0.1, 0.1);
    Life2 = new TexRect("images/heart.png", 0.8,0.95, 0.1, 0.1);
    Life3 = new TexRect("images/heart.png", 0.7,0.95, 0.1, 0.1);
    Game_Over = new AnimatedRect("game_over.png",7,1, -0.5, 0.5, 1, 1);

    //all the objects
    gameStart = true;
    gameOver = false;
    countLives = 3;
    countTime = 0;
    timer = 0;
    
    
    powerUpOn = false;
    jumping= false;
    shouldFall= false;
    canJump = true;
    
    overlapping = false;
    pause = false;
    counter = 0;
    linc = 0.03;
    linc2 = 0.04;
    linc3 = 0.05;
    
    
}

void Game::moveCactus(){
    if (countLives != 0){
        if (!pause) {
        x = Cactus1->getX();
        x2 = Cactus2->getX();
        
        
        if(x < -1.1){
            x = 1.1;
        }
        
        
        if(x2 < -1.1){
            x2 = 2.5;
        }
        
        if(countLives == 3){
            x -=  linc;
            x2 -= linc;
            Cactus1->setX(x);
            Cactus2->setX(x2);
        }
        
        if(countLives == 2){
            x -= linc2;
            x2 -= linc2;
            Cactus1->setX(x);
            Cactus2->setX(x2);
        }
        
        if(countLives == 1){
            x -= linc3;
            x2 -= linc3;
            Cactus1->setX(x);
            Cactus2->setX(x2);
        }
        } else {
            x = Cactus1->getX();
            x2 = Cactus2->getX();
            Cactus1->setX(x);
            Cactus2->setX(x2);
        }
    }

}
void Game::movePowerUp(){
    if (countLives != 0){
        if (!pause) {
        if (powerUpOn){
            x = FiestaCactus->getX();
            if(x < -1.1){
                x = 1.1;
                timer = 0;
                powerUpOn = false;
            }
            
            if(countLives == 3){
                x -= linc;
                FiestaCactus->setX(x);
            }
            
            if(countLives == 2){
                x -= linc2;
                FiestaCactus->setX(x);
            }
            
            if(countLives == 1){
                x -= linc3;
                FiestaCactus->setX(x);
            }
        }
        } else {
            x = FiestaCactus->getX();
            FiestaCactus->setX(x);
        }
    }
}

void Game::moveClouds(){
    if (countLives != 0){
        if (!pause) {
            x = Cloud->getX();
            x -= 0.0011;
        
            if (x < -1.2){
                x = 1.1;
            }
        
            Cloud->setX(x);
            x = Cloud2->getX();
        
            if (x < -1.2){
                x = 1.1;
            }
            x -= 0.001;
            Cloud2->setX(x);
        } else {
            x =Cloud->getX();
            Cloud->setX(x);
        }
    }
}
void Game::moveGround(){
    if (countLives != 0){
        if (!pause) {
        x = Ground->getX();
        x2 = Ground2 ->getX();

        
        if (x < -3) {
            x = 1;
        }
        if(x2 < -3.00){
            x2 = 1;
        }

            if (countLives == 3){
                x-= linc;
                x2-= linc;
            }
            if (countLives == 2){
                x-= linc2;
                x2-=linc2;
            }
            
            if (countLives == 1){
                x-= linc3;
                x2-= linc3;
            }
      
        
        Ground->setX(x);
        Ground2->setX(x2);
        } else {
            x = Ground->getX();
            x2 = Ground2 ->getX();
            Ground2->setX(x2);
            Ground->setX(x);
            
        }
    }
}

void Game::moveDesert(){
     if (countLives != 0){
        if(!pause) {
        x = Desert->getX();
        x2 = Desert2 ->getX();
        
        if (x < -3) {
            x = 1;
        }
        
        if(x2 < -3){
            x2 = 1;
        }
        
        x-= 0.0005;
        x2-=0.0005;
        

        Desert->setX(x);
        Desert2->setX(x2);
        } else {
        x = Desert->getX();
        x2 = Desert2 ->getX();
        
        Desert->setX(x);
        Desert2->setX(x2);
        }
     }
}

void Game::dinoJump(){
    if (canJump){
        if (!shouldFall)
            jumping = true;
        canJump = false;
    }
}

void Game::dinoFall(){
    canJump = true;
    jumping = false;
    
    
}
void Game::moveDino(){
    if (countLives != 0){
        if  (!pause) {
            Dino->animate();
        if (jumping){
            if((y < .05) & (!shouldFall)){
                Dino->stop();
                y = Dino->getY();
                y += 0.02;
                Dino->setY(y);
                linc = 0.035;
            }
            else {
                shouldFall = true;
                jumping = false;
            }
        }
        else {
            if (y > -.35){
                Dino->stop();
                y = Dino->getY();
                y -= 0.04;
                Dino->setY(y);
            }
            else {
                shouldFall = false;
                linc = 0.01;
            }
        }
        }
        else{
            Dino->stop();
        }
    }
    else{
        Dino->stop();
    }
}

void Game::livesChanges(){
    
    float xd, xc,yd, yc,xc2,yc2,xfc,yfc;
    xd = Dino->getX()+ Dino->getW()-.17;
    yd = Dino->getY();
    xc = Cactus1->getX();
    yc = Cactus1->getY()+ Cactus1->getH()-.17;
    xc2 = Cactus2->getX();
    yc2 = Cactus2->getY()+ Cactus2->getH()-.17;
    xfc = FiestaCactus->getX();
    yfc =FiestaCactus->getY()+ FiestaCactus->getH() -.17;
   
    if (!overlapping){

        
        if ((xc < xd && yd <= yc) || (xc2 < xd && yd <= yc2)) {
            overlapping = true;
            countLives--;
            powerUpOn = true;
            
        }
        if (xfc < xd && yd <= yfc ) {
            overlapping = true;
            countLives++;
        }

    }

}

void Game::livesChanges2(){
    //moveCactus();
    float xd, xc,yd, yc,xc2,yc2,xfc,yfc;
    xd = Dino->getX()+ Dino->getW()-.17;
    yd = Dino->getY();
    xc = Cactus1->getX();
    yc = Cactus1->getY()+ Cactus1->getH()-.17;
    xc2 = Cactus2->getX();
    yc2 = Cactus2->getY()+ Cactus2->getH()-.17;
    xfc = FiestaCactus->getX();
    yfc =FiestaCactus->getY()+ FiestaCactus->getH() -.17;
    if (overlapping){
    if (xd >  xc && yd > yc2 ){
         overlapping = false;
        }
        if (xd >  xfc && yd > yfc ){
             overlapping = false;
        }
    }
}




void Game::draw(){
    Desert2->draw();
    Desert->draw();
    Ground2->draw();
    Ground->draw();
    Cactus1->draw();
    Cactus2->draw();
    FiestaCactus->draw();
    Dino->draw();
    Cloud->draw();
    Cloud2->draw();
    if (countLives == 3){
        Life1->draw();
        Life2->draw();
        Life3->draw();
    }
    else if (countLives == 2){
        Life1->draw();
        Life2->draw();
        
    }
    else if (countLives == 1){
        Life1->draw();
    }
    else if(countLives == 0){
        Game_Over->draw();
    }
    Numbers->draw();
    Numbers2->draw();
    Numbers3->draw();
    Numbers4->draw();


}

void Game::showPowerUp(){
    random = rand();
    for(int i = 0; i < 1000; i++){
        timer++;
    }
    
    if (FiestaCactus->getX() > 1.0 && timer > random && countLives < 3){
        powerUpOn = true;
    }
}
void Game::gameIsOver(){
        if(countLives == 0){
            Game_Over->draw();
         }
    }

void Game::pauseGame(){
    pause = true;
}
void Game::reset(){
    countLives = 3;
    counter = 0;
    Numbers->Reset();
    Numbers2->Reset();
    Numbers3->Reset();
    Numbers4->Reset();
     Score();

 }

void Game::resumeGame() {
    pause = false;
}
void Game::Score() {
    if (countLives!=0){
        if (!pause){
        counter++;
       Numbers->advance();

      if (counter % 10 == 0){
            Numbers2->advance();
            
        }
        
        if (counter % 100 == 0){
            
           Numbers3->advance();
        }
        
        if (counter % 1000 == 0){
           Numbers4->advance();
            
        }
           }
    }
    
    else{
         Numbers->stop();
         Numbers2->stop();
         Numbers3->stop();
         Numbers4->stop();
    }
}


Game::~Game(){
    delete Desert;
    delete Desert2;
    delete Ground;
    delete Ground2;
    delete Cactus1;
    delete Cactus2;
    delete FiestaCactus;
    delete Dino;
    delete Cloud;
    delete Cloud2;
    delete Life1;
    delete Life2;
    delete Life3;
    delete Game_Over;
}

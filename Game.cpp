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
    
    Ground = new TexRect("images/ground.png", -1., -0.5, 2, 0.5);
    Ground2 = new TexRect("images/ground.png", 1, -0.5, 2.1, 0.5);

    Desert = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    Desert2 = new TexRect("images/desert.png", 1, 1.1, 2.3, 2);
  
   
    Cactus1 = new TexRect("images/cactus.png", 0.8, -0.3, 0.3, 0.3);
    Cactus2 = new TexRect("images/cactus.png", 2.0, -0.3, 0.3, 0.3);
    FiestaCactus = new TexRect("images/fiestaC.png", 1.2, -0.3, 0.3, 0.3);
    
   
    Cloud = new TexRect("images/cloud.png", 1,.7 , .3, .3);
    Cloud2 = new TexRect("images/cloud.png", 1.7,.45 , .3, .3);
   
    Numbers= new AnimatedRect("images/numbers.png", 2,5,.5,.6,.3,.3);
    
    Life1 = new TexRect ("images/heart.png", 0.9, 0.95, 0.1, 0.1);
    Life2 = new TexRect("images/heart.png", 0.8,0.95, 0.1, 0.1);
    Life3 = new TexRect("images/heart.png", 0.7,0.95, 0.1, 0.1);
    
     lifes.push_front(Life1);
     lifes.push_front(Life2);
     lifes.push_front(Life3);

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
    
}

void Game::moveCactus(){
    x = Cactus1->getX();
    x2 = Cactus2->getX();
    
    
    if(x < -1.1){
        x = 1.1;
    }
    
    
    if(x2 < -1.1){
        x2 = 2.5;
    }
    
    if(countLives == 3){
        x -= 0.01;
        x2 -= 0.01;
        Cactus1->setX(x);
        Cactus2->setX(x2);
    }
    
    if(countLives == 2){
        x -= 0.02;
        x2 -= 0.02;
        Cactus1->setX(x);
        Cactus2->setX(x2);
    }
    
    if(countLives == 1){
        x -= 0.03;
        x2 -= 0.03;
        Cactus1->setX(x);
        Cactus2->setX(x2);
    }
    
   

}
void Game::movePowerUp(){
    if (powerUpOn){
        x = FiestaCactus->getX();
        if(x < -1.1){
            x = 1.1;
            timer = 0;
            powerUpOn = false;
        }
        
        if(countLives == 3){
            x -= 0.01;
            FiestaCactus->setX(x);
        }
        
        if(countLives == 2){
            x -= 0.02;
            FiestaCactus->setX(x);
        }
        
        if(countLives == 1){
            x -= 0.03;
            FiestaCactus->setX(x);
        }
    }
}

void Game::moveClouds(){
    
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
    
}
void Game::moveGround(){
    x = Ground->getX();
    x2 = Ground2 ->getX();

    
    if (x < -3) {
        x = 1;
    }
    if(x2 < -3.00){
        x2 = 1;
    }

    
    x-= 0.01;
    x2-=0.01;
    
    Ground->setX(x);
    Ground2->setX(x2);

}

void Game::moveDesert(){
    x = Desert->getX();
    x2 = Desert2 ->getX();
    
    if (x < -3) {
        x = 1;
    }
    
    if(x2 < -3){
        x2 = 1;
    }
    
    x-= 0.1;
    x2-=0.1;
    

    Desert->setX(x);
    Desert2->setX(x2);
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
    if (jumping){
        if((y < -0.1) & (!shouldFall)){
            y = Dino->getY();
            y += 0.1;
            Dino->setY(y);
            
        }
        else {
            shouldFall = true;
            jumping = false;
        }
    }
    else {
        if (y > -0.35){
            y = Dino->getY();
            y -= 0.1;
            Dino->setY(y);
        }
        else {
            shouldFall = false;
        }
    }
}



//xc < xd && yd< yc conditions
//void Game::lifeChanges(){
//    float xd, xc,yd, yc,xfc,yfc;
//    xd = Dino->getX()+ Dino->getW();
//    yd = Dino->getY();
//    xc = Cactus1->getX();
//    yc = Cactus1->getY()+ Cactus1->getH();
//    xfc = Cactus2->getX();
//    yfc = Cactus2->getY()+ Cactus2->getH();
//    if (xc < xd && yd < yc){
//          lifes.erase(lifes.begin()+1);
//        Life1->draw();
//        std::cout<<"hiiii"<<std::endl;
//        if (countLives == 3){
//           // lifes.erase(lifes.begin());
//            std::cout<<"hiiii"<<std::endl;
//            //  lifes.push_back(Life1);
//        }
//        
//        if (countLives == 2){
//             lifes.push_back(Life2);
//        }
//        if (countLives == 1){
//             lifes.push_back(Life3);
//                
//        }
//
//    }
//     if (xfc < xd && yd < yfc){
//         if (countLives == 3){
//          lifes.push_front(Life3);
//         }
//         if (countLives == 2){
//             lifes.push_front(Life2);
//         }
//        
//         if (countLives == 1){
//               lifes.push_front(Life1);
//                 
//             }
//     }
//
//}



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
    Life1->draw();
    Life2->draw();
    Life3->draw();
     Numbers->draw();

     // Game_Over->draw();
}

void Game::reset(){
    
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


Game::~Game(){
    delete Desert;
    delete Cactus1;
    delete Cactus2;
    delete FiestaCactus;
    delete Dino;
    delete Cloud;
    delete Cloud2;
    delete Life1;
    delete Life2;
    delete Life3;
    for (int i = 0; i < lifes.size(); i++) {
        delete lifes[i];
    }
    //delete Game_Over;
}

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
    Desert = new TexRect("desert.png", -1, 1, 2, 2);
    Cactus1 = new TexRect("cactus.png", 0.8, -0.3, 0.3, 0.3);
    Cactus2 = new TexRect("cactus.png", 2.0, -0.3, 0.3, 0.3);
    FiestaCactus = new TexRect("fiestaCactus.png", 1.2, -0.3, 0.3, 0.3);
    Dino = new TexRect("dino.png", -0.1, -0.34, 0.4, 0.4);
    Life1 = new TexRect("heart.png", 0.9, 0.95, 0.1, 0.1);
    Life2 = new TexRect("heart.png", 0.8,0.95, 0.1, 0.1);
    Life3 = new TexRect("heart.png", 0.7,0.95, 0.1, 0.1);
    Cloud = new TexRect("cloud.png", -0.7, 0.85, 0.3, 0.3);
    Cloud2 = new TexRect("cloud.png", 0.7, 0.65, 0.25, 0.25);
    
    Game_Over = new AnimatedRect("game_over.png",7,1, -0.5, 0.5, 1, 1);
    
    gameOver = false;
    countLives = 2;
    countTime = 0;
    gameStart = true;
    timer = 0;
    
    powerUpOn = false;
    
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
    
    if( x < -1.2){
        x = 1.1;
    }
    
    Cloud->setX(x);
    x = Cloud2->getX();
    
    if(x < -1.2){
        x = 1.1;
    }
    
    x -= 0.001;
    Cloud2->setX(x);
    
}


void Game::draw(){
    Desert->draw();
    Cactus1->draw();
    Cactus2->draw();
    FiestaCactus->draw();
    Dino->draw();
    Life1->draw();
    Life2->draw();
    Life3->draw();
    Cloud->draw();
    Cloud2->draw();
    Game_Over->draw();
    
    
//    if(gameOver){
//        Desert->draw();
//        Cactus1->draw();
//        Dino->draw();
//        
//    }
    
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
    delete Life1;
    delete Life2;
    delete Life3;
    delete Cloud;
    delete Cloud2;
   //delete Game_Over;
}

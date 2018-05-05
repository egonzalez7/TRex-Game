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
    
    Dino = new AnimatedRect("images/dino.png", 3, 2, 0, 0, 0.6, 0.6);
    
    Ground = new TexRect("images/ground.png", -1, -0.5, 2, 0.5);
    Ground2 = new TexRect("images/ground.png", -1, -0.5, 2, 0.5);
    Ground3 = new TexRect("images/ground.png", -1, -0.5, 2, 0.5);
    Ground4 = new TexRect("images/ground.png", -1, -0.5, 2, 0.5);
    
    Desert = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    Desert2 = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    Desert3 = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    Desert4 = new TexRect("images/desert.png", -1, 1.1, 2, 2);
    
    Cactus1 = new TexRect("images/cactus.png", 0.8, -0.3, 0.3, 0.3);
    Cactus2 = new TexRect("images/cactus.png", 2.0, -0.3, 0.3, 0.3);
    Fiesta = new TexRect("images/fiestaCactus.png", 0.8, -0.3, 0.3, 0.3);
    Life1 = new TexRect("images/heart.png", 0.9, 0.95, 0.1, 0.1);
    Life2 = new TexRect("images/heart.png", 0.8,0.95, 0.1, 0.1);
    Life3 = new TexRect("images/heart.png", 0.7,0.95, 0.1, 0.1);
    Cloud = new TexRect("images/cloud.png", -0.7, 0.85, 0.3, 0.3);
    Cloud2 = new TexRect("images/cloud.png", 0.7, 0.65, 0.25, 0.25);
    
    //Game_Over = new AnimatedRect("game_over.png",7,1, -0.5, 0.5, 1, 1);
    
    gameStart = true;
    gameOver = false;
    countLives = 3;
    countTime = 0;
    Time = 0;
    
    powerUpOn = true;
    jumping = false;
    shouldFall = false;
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
    
    x -= 0.01;
    x2 -= 0.01;
    Cactus1->setX(x);
    Cactus2->setX(x2);
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

void Game::moveGround(){
    x = Ground->getX();
    x2 = Ground2 ->getX();
    x3 = Ground3 ->getX();
    
    if (x < -1.7) {
        x = -1;
    }
    
    if(x2 < -1.7){
        x2 = 0;
    }
    
    if(x3 < -1.7){
        x3=1;
    }
    
    x-= 0.01;
    x2-=0.01;
    x3-=0.01;
    
    Ground->setX(x);
    Ground2->setX(x2);
    Ground3->setX(x3);
}

void Game::moveDesert(){
        x = Desert->getX();
        x2 = Desert2 ->getX();
        x3 = Desert3 ->getX();
        
        if (x < -1.7) {
            x = -1;
        }
        
        if(x2 < -1.7){
            x2 = 0;
        }
        
        if(x3 < -1.7){
            x3=1;
        }
        
        x-= 0.0005;
        x2-=0.0005;
        x3-=0.0005;
        
        Desert->setX(x);
        Desert2->setX(x2);
        Desert3->setX(x3);
}

void Game::movePowerUp(){
    if (powerUpOn){
        x = Fiesta->getX();
        if(x < -1.1){
            x = 1.1;
            timer = 0;
            powerUpOn = false;
        }
        
        x -= 0.01;
        Fiesta->setX(x);
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
 
    if (jumping)
    {
        if(y < -0.1 & !shouldFall)
        {
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


void Game::draw(){
    
    Desert4->draw();
    Desert3->draw();
    Desert2->draw();
    Desert->draw();
    Ground4->draw();
    Ground3->draw();
    Ground->draw();
    Ground2->draw();
    Cactus1->draw();
    Cactus2->draw();
    Fiesta->draw();
    Dino->draw();
    Life1->draw();
    Life2->draw();
    Life3->draw();
    Cloud->draw();
    Cloud2->draw();
    //Game_Over->draw();
    
    if(gameOver){
        gameStart = false;
       // Game_Over = new TexRect("game_over.png", -0.5, 0.5, 1, 1);
        Desert->draw();
        Cactus1->draw();
        Dino->draw();
    }
    
}

void Game::reset(){
    Game* game = new Game();
    Board* board = new Board();

    bool reset = true;
    
    while(true) {
        board->update(game);

        if(reset) {
            delete board;
            board = new Board();
            reset = false;
        }
    }
}

void Game::showPowerUp(){
    random = rand();
    for(int i = 0; i < 10000; i++){
        timer++;
    }
    
    if (Fiesta->getX() > 1.0 && timer > random && countLives < 3){
        powerUpOn = true;
    }
}

Game::~Game(){
    delete Ground;
    delete Desert;
    delete Cactus1;
    delete Cactus2;
    delete Fiesta;
    delete Dino;
    delete Life1;
    delete Life2;
    delete Life3;
    delete Cloud;
    delete Cloud2;
    //delete Game_Over;
}

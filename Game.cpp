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
    Desert = new TexRect("images/desert.png", -1, 1, 2, 2);
    Cactus = new TexRect("images/cactus.png", 0.8, -0.3, 0.3, 0.3);
    Dino = new TexRect("images/dino.bmp", 1,1,1,1);
    Life1 = new TexRect("images/heart.png", 0.9, 0.95, 0.1, 0.1);
    Life2 = new TexRect("images/heart.png", 0.8,0.95, 0.1, 0.1);
    Life3 = new TexRect("images/heart.png", 0.7,0.95, 0.1, 0.1);
   
    
                      
    //all the objects
    
    gameOver = false;
    countLives = 3;
    countTime = 0;
    gameStart = false;
    AITime = 0;
    
}

void Game::moveCactus(){
    
    x = Cactus->getX();
    x -= 0.01;
   Cactus->setX(x);
    

}

void Game::draw(){
    Desert->draw();
    Cactus->draw();
    Dino->draw();
    Life1->draw();
    Life2->draw();
    Life3->draw();
    
    if(gameOver){
        Game_Over = new TexRect("game_over.png", -0.5, 0.5, 1, 1);
        Desert->draw();
        Cactus->draw();
        Dino->draw();
    }
    
}

void Game::reset(){
    
}

void Game::AIPlay(int AITime){
    
}

Game::~Game(){
    delete Desert;
    delete Cactus;
    delete Dino;
    delete Life1;
    delete Life2;
    delete Life3;
    delete Game_Over;
}

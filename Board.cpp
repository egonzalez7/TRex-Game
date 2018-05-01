#include <iostream>
#include <thread>
#include "Board.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


Board::Board(){
    objects.push_back(new TexRect("images/desert.png", -1, 1, 2, 2));
    objects.push_back(new TexRect("images/cactus.bmp", 0.8, -0.4, 0.2, 0.2));
    objects.push_back(new TexRect("images/Dino.bmp", -0.8,-0.2,.45,.4));
    //objects.push_back(new TexRect("hearts.bmp", 1, 1, 1, 1));
    
                      
    //all the objects
    
    gameOver = false;
    countLives = 3;
    countTime = 0;
    gameStart = false;
    AITime = 0;
    
}

void Board::draw(){
    for(int i = 0; i < objects.size(); i++){
        objects[i]->draw();
    }
    if(gameOver){
        objects.push_back(new TexRect("game_over.png", -0.5, 0.5, 1, 1));
        for(int i = 0; i < objects.size(); i++){
            objects[i]->draw();
        }
    }
    
}

void Board::reset(){
    
}

void Board::AIPlay(int AITime){
    
}

Board::~Board(){
    for(int i = 0; i < objects.size(); i++){
        delete objects[i];
    }
}

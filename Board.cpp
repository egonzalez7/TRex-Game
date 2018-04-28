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
    objects.push_back(new TexRect("desert.png", -1.0, 1.0, 2.0, 2.0));
    //objects.push_back(new TexRect("cactus.bmp", 0.0, 0.0, 0.5, 0.5));
    //all the objects
    
    gameOver = false;
    countLives = 3;
    countTime = 0;
    gameStart = false;
    AITime = 0;
    
}

void Board::draw(){
    for(int i = 0; i < sizeof(objects); i++){
        objects[i]->draw();
    }
}

void Board::reset(){
    
}

void Board::AIPlay(int AITime){
    
}

Board::~Board(){
    for(int i = 0; i < sizeof(objects); i++){
        delete objects[i];
    }
}

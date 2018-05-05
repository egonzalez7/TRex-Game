//
//  Board.hpp
//  glutapp
//
//  Created by Mia Parelius on 4/28/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <vector>
#include "TexRect.h"
#include "AnimatedRect.h"

class Game{
    float x;
    float x2;
    float x3;
    bool gameOver;
    int countLives;
    int countTime;
    int Time;
    void AIPlay(int);
    void reset();
    bool powerUpOn;
    int timer;
public:
    float random;
    
    TexRect* Cactus1;
    TexRect* Cactus2;
    TexRect* Fiesta;
    TexRect* Ground;
    TexRect* Ground2;
    TexRect* Ground3;
    TexRect* Ground4; //the one that stays in place. Desert 4 too.
    TexRect* Desert;
    TexRect* Desert2;
    TexRect* Desert3;
    TexRect* Desert4;
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    AnimatedRect* Dino;
    //TexRect* Game_Over;
    TexRect* Cloud;
    TexRect* Cloud2;
    
    //AnimatedRect* Game_Over;
    
    Game();
    
    bool gameStart;
    void draw();
    void moveDesert();
    void moveCactus();
    void moveGround();
    void moveFiesta();
    void moveClouds();
    void movePowerUp();
    void showPowerUp();
    //void gameIsOver();
    
    ~Game();
};

class Board{
public:
    void update(Game* game) {
        game->draw();
    }
};



#endif 


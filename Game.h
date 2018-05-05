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

class Game{
   bool gameOver;
    int countLives;
    bool gameStart;
    int countTime;
    void reset();
    int timer;
    bool powerUpOn;
public:
    float x;
    float x2;
    float random;
    TexRect* Cactus1;
    TexRect* Cactus2;
    TexRect* FiestaCactus;
    TexRect* Desert;
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    TexRect* Dino;
    TexRect* Cloud;
    TexRect* Cloud2;
    
    AnimatedRect* Game_Over;
    
    Game();
    
    void draw();
    void moveCactus();
    void moveClouds();
    void movePowerUp();
    void showPowerUp();
    
    void gameIsOver();
    
    ~Game();

};

#endif /* Board_hpp */


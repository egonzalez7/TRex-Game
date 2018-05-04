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
    int countTime;
    int AITime;
    void AIPlay(int);
    void reset();
public:
    TexRect* Cactus;
    TexRect* Fiesta;
    TexRect* Desert;
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    TexRect* Dino;
    TexRect* Game_Over;
    
    Game();
    
    bool gameStart;
    void draw();
    void moveCactus();
    void moveFiesta();
    
    ~Game();
};

class Board {
public:
    void update(Game* game) {
        game->draw();
    }
};



#endif 


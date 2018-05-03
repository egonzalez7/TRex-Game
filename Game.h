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
    void reset();
    void AIPlay(int);
public:
    float x;
    float y;
    TexRect* Cactus;
    TexRect* Desert;
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    TexRect* Dino;
    TexRect* Game_Over;
    
    Game();
    
    void draw();
    bool gameStart;
    void moveCactus();

    ~Game();
};

#endif /* Board_hpp */


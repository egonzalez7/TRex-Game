//
//  Board.hpp
//  glutapp
//
//  Created by Mia Parelius on 4/28/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <iostream>
#include <vector>
#include "TexRect.h"

class Board{
    std::vector<TexRect*> objects;
    bool gameOver;
    int countLives;
    int countTime;
    int AITime;
    void reset();
    bool gameStart;
    void AIPlay(int);
public:
    Board();
    void draw();
    
    ~Board();
};

#endif /* Board_hpp */

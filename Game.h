
#ifndef Game_h
#define Game_h

#include <iostream>
#include "TexRect.h"
#include "AnimatedRect.h"
#include <vector>
#include "deque"


class Game{
    bool gameOver;
    int countLives;
    bool gameStart;
    int countTime;
    void reset();
    int timer;
    bool powerUpOn;
    bool jumping;
    bool canJump;
    
   public:
    bool shouldFall;
    float x,x2,x3;
    float y;
    float random;
   // std::vector <TexRect*> lifes;
    std::deque<TexRect*> lifes;
    AnimatedRect* Dino;
    
    TexRect* Ground;
    TexRect* Ground2;
    
    TexRect* Desert;
    TexRect* Desert2;
    
    TexRect* Cactus1;
    TexRect* Cactus2;
    TexRect* FiestaCactus;
 
    TexRect* Cloud;
    TexRect* Cloud2;
    
    AnimatedRect* Numbers;
    
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    

    AnimatedRect* Game_Over;

    Game();
    void draw();
    void moveCactus();
    void moveClouds();
    void moveGround();
    void moveDesert();
    void movePowerUp();
    void showPowerUp();
   // void lifeChanges();
    void moveDino();
    void dinoJump();
    void dinoFall();
    void gameIsOver();

    

    ~Game();
};

#endif 


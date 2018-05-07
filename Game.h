
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
    
    bool overlapping;
    float cinc;
    
   public:
    bool shouldFall;
    float x,x2;
    float y;
    float random;
    std::deque<TexRect*> lives;
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
    AnimatedRect* Numbers2;
    AnimatedRect* Numbers3;
    AnimatedRect* Numbers4;
    AnimatedRect* Numbers5;
    
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
    void liveChanges();
    void moveDino();
    void dinoJump();
    void dinoFall();
    void gameIsOver();
 
    

    

    ~Game();
};

#endif 


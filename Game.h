
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
    float x,x2;
    float y;
    float random;
   // std::vector <TexRect*> lifes;
    std::deque<TexRect*> lifes;
    TexRect* Cactus1;
    TexRect* Cactus2;
    TexRect* FiestaCactus;
    TexRect* Desert;
 //   TexRect* Dino;
    TexRect* Cloud;
    TexRect* Cloud2;
    TexRect* Life1;
    TexRect* Life2;
    TexRect* Life3;
    AnimatedRect* Dino;
     AnimatedRect* Numbers;
    AnimatedRect* Game_Over;
   // AnimatedRect* Dino;
    Game();
    void draw();
    void moveCactus();
    void moveClouds();
    void movePowerUp();
    void showPowerUp();
    void lifeChanges();
    void moveDino();
    void dinoJump();
    void dinoFall();
    void gameIsOver();

   // void moveCactus();
    

    ~Game();
};

#endif 


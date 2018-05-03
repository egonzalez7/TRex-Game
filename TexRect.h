#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect{
    float x;
    float y;
    float w;
    float h;
public:

    GLuint texture_id;

    TexRect (const char*, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    float getX() const{
        return x;
    }
    float getY() const {
        return y;
    }
    float getW() const {
        return w;
    }
    float getH() const {
        return h;
    }
    
    void setX(float x){
        this->x = x;
    }
    void setY(float y){
        this->y = y;
    }
    void setW(float w){
        this->w = w;
    }
    void setH(float h){
        this->h = h;
    }
    

    
    
    void jump();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
};

#endif

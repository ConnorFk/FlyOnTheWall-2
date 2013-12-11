//
//  MyString.h
//  6Strings_wave
//
//  Created by Connor on 13-12-10.
//
//
#include "ofMain.h"
#include "Particle.h"

#ifndef _Strings_wave_MyString_h
#define _Strings_wave_MyString_h

class MyString : public ofBaseApp{
    
public:
    
    void setup(ofVec2f leftpos, ofVec2f rightpos);
    void update();
    void draw();
    void ifCollision(ofVec2f m);
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);
    
    //Collision
    bool collision;
    
    int n;
    float A;
    ofVec2f left;
    ofVec2f right;
    int y;
    
    //distance
    ofVec2f L;
    float Lsq;
    
    int alp;
    float rad;
    
    ofVec2f Points[40];
    float decay;
    
    
    
    
    
};
#endif

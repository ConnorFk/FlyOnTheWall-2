//
//  MyString.h
//  NIbrew
//
//  Created by Connor on 13-12-13.
//
//

#include "ofMain.h"
#include "Particles.h"

#ifndef __openNiSample007__Mystring_h
#define __openNiSample007__Mystring_h




class MyString : public ofBaseApp{
    
public:
    
    void setup(int leftpos, int rightpos, int ypos);
    void update();
    void draw(ofColor c);
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
    float L;
    float Lsq;
    
    int alp;
    float rad;
    
    ofVec2f Points[40];
    float decay;
    
    
    
    
    
};
#endif
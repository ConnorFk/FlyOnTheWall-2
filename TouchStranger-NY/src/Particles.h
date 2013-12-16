//
//  Particles.h
//  NIbrew
//
//  Created by Connor on 13-12-13.
//
//

#ifndef __openNiSample007__Particles__
#define __openNiSample007__Particles__


#include <iostream>
#include "ofMain.h"
#include "MyString.h"

class particle{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    void erase();
    
    float damping;
    ofColor c;
    
protected:
private:
    
    ofImage particleImage;
    
    
};

#endif /* defined(___Strings_wave__Particle__) */

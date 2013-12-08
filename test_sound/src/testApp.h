#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);
    
    ofVec2f a[6], b[6], c;
    bool collision[6];
    bool soundPlay[6];
    float r;
    float j[6];//sound volume
    ofSoundPlayer sound[6];
};

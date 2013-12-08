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
    
    
    //minumum distance
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);
    
    ofVec2f a,b,c;
    float L; //Distance
    float A; //magnitude
    float J; //sound volume
    deque<ofVec2f> pointsOnString;
    int NumPoints;
    float decay;
    int n; // viblation mode
    
    ofImage particleImage;
    bool soundPlay;
    
    ofSoundPlayer mus;
};

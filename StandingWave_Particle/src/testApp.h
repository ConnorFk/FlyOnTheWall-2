#pragma once

#include "ofMain.h"
#include "particle.h"

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
    
    //load image and sound
    ofImage particleImage;
    
    //Standing Wave related
    ofVec2f a[6],b[6],c,d,e;
    float L,L1; //Distance
    float A; //magnitude
    deque<ofVec2f> pointsOnString;
    int NumPoints;
    float decay;
    int n; // viblation mode
    float sigma;
    void Parameter_Set(ofVec2f a, ofVec2f b);
    void Vibration_Calc(ofVec2f a, ofVec2f b, ofVec2f c);
    void Vibration_Draw(ofVec2f a, ofVec2f b, ofVec2f c);
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);

    //Collision
    bool collision[6];
    void ifCollision();


    //Particle related
    vector <particle> particles;
   
    
    int alp;
    float rad;
    
    int i;
    int I;
    
    bool soundPlay[6];
    float j[6];//sound volume
    ofSoundPlayer sound[6];


};

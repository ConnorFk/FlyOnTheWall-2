#pragma once

#include "ofMain.h"
#include "MyString.h"
#include "Particle.h"

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
    
        void drawParticles();
    
    deque<ofVec2f> pointsOnString;
    
    ofVec2f mouse;
    MyString s[6];
    
    //Particle related
    vector <particle*> particles;
    typedef vector<particle*>::iterator pIter;

	int alp;
    float rad;
    
    bool soundPlay[6];
    float j[6];//sound volume
    ofSoundPlayer sound[6];
};

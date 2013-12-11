
#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "MyString.h"
#include "Particle.h"

class testApp : public ofBaseApp{
    
public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    void drawParticles();
    void userEvent(ofxOpenNIUserEvent & event);
    
    deque<ofVec2f> pointsOnString;
    
	ofxOpenNI openNIDevice;
    
    ofTrueTypeFont verdana;
    
    //joints
    ofVec2f leftHand1,head1,leftFoot1,leftShoulder1,neck1,torso1,leftelbow1,leftknee1,lefthip1,rightHand1,rightFoot1,rightShoulder1,rightelbow1,rightknee1,righthip1;
    ofVec2f rightHand2,head2,rightFoot2,rightShoulder2,neck2,torso2,rightelbow2,rightknee2,righthip2,leftHand2,leftFoot2,leftshoulder2,leftelbow2,leftknee2,lefthip2;
    
    
    float minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p);
    
//    ofVec2f a[6], b[6], c;
//    bool collision[6];
    bool soundPlay[6];
    float r;
    float j[6];//sound volume
    ofSoundPlayer sound[6];
    
    
    ofVec2f mouse;
    MyString s[6];
    
    //Particle related
    vector <particle*> particles;
    typedef vector<particle*>::iterator pIter;
    
	int alp;
    float rad;

    
    
};

#endif


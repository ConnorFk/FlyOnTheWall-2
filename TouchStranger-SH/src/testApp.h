#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "Mystring.h"
#include "Particles.h"
#import"ofxSpacebrew.h"

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
    void userEvent(ofxOpenNIUserEvent & event);
    void drawParticles();
    
	ofxOpenNI openNIDevice;
    
    ofTrueTypeFont Belgrad;
    
    //user1 for test by kinect(New York side)
    ofVec2f leftHand1,rightHand1,head1,leftFoot1,rightFoot1,leftShoulder1,rightShoulder1,neck1,leftknee1,lefthip1,torso1,leftelbow1,rightelbow1,rightknee1,righthip1;
    
    //user2 drawn by spacebrew(Shanghai side)
    ofVec2f leftHand2,rightHand2,head2,leftFoot2,rightFoot2,leftShoulder2,rightShoulder2,neck2,leftknee2,lefthip2,torso2,leftelbow2,rightelbow2,rightknee2,righthip2;
    
    
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
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    void onMessage( Spacebrew::Message & msg );
    
    
};

#endif


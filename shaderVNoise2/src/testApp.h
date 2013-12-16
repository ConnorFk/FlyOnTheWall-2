#ifndef _TEST_APP
#define _TEST_APP

#include "ofxControlPanel.h"

#include "ofMain.h"

#define  NUM 500

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofShader shader;
    GLUquadricObj *quadric;
    ofImage redColor;
    
protected:
    //mouse stuff
    ofVec2f mMouse;
    
    int counter;
    
    //uniform values
    float blendValue;
    
    
    ofEasyCam   cam;
    
    ofxControlPanel	panel;
    
    int LightPosition,surfaceColorR,surfaceColorG,surfaceColorB,surfaceColorE,
        offset1,offset2,offset3,scaleIn,scaleOut,Freq,Width,Width1,Height,StripeShift;
    
    
    int i, j, c, d;
    float time;
    vector <ofPoint> pos;
    
    bool col;

};

#endif
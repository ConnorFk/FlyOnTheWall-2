#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    p.set(ofGetWidth()/4, ofGetHeight()/2);
    q.set(ofGetWidth()*3/4, ofGetHeight()/2);
    
    L = ofDist(p.x, p.y, q.x, q.y);
    
    for (int i = 0; i < 100; i++){
        ofVec2f pos = ofVec2f((q-p).x/100*i,0);
        pointsOnString.push_back(pos);
    }
    
    A = 10;
    
    mus.loadSound("sound1.mp3");
    
    mus.setVolume(2.0f);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofPushMatrix();
    ofTranslate(p);
    
    for (int i = 1; i < pointsOnString.size(); i++){
        pointsOnString[i].y = A*sin(PI/L*i*(q-p).x/100)*cos(TWO_PI*20/2/L*ofGetElapsedTimef()*200);
    }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(10, 20, 80);
    ofCircle(p, 10);
    ofCircle(q, 10);
    //    ofLine(p, q);
    
    
    for (int i = 0; i < pointsOnString.size(); i++){
        pointsOnString[100] = ofVec2f((q-p).x, 0);
        ofLine(p+pointsOnString[i], p+pointsOnString[i+1]);
              //ofCircle(p+pointsOnString[i], 10);
                
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}

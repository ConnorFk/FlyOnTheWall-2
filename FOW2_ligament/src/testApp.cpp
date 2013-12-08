#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(50);
    
    time=0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    time+=0.02;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //ofSetColor(150);
    ofPushMatrix();
    ofTranslate(0, 200);
    for( j = 0; j < 6; j++){
         for( i = 0; i < NUM; i++){
             pos.push_back(ofPoint());
             pos[i].x = 5 + i*5;
              pos[i].y = ofNoise ( time + i * 0.005 + j ) * 150 + j * 30;   // set up a noise time offest by i value
              if (pos[i].y < mouseY-200+0.01) {
 
                    ofSetColor(50,100,250);
    
              } else {
   
                   ofSetColor(150);
                  
              }
              ofCircle(pos[i].x, pos[i].y, 3);
         }
    }
    ofPopMatrix();
    
    
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
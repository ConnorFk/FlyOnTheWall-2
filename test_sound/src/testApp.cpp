#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //----------------------------------------------sound setting part
    sound[0].loadSound("string1.wav");
    sound[0].setVolume(0.f);
    sound[0].setLoop(true);
    
    sound[1].loadSound("string2.wav");
    sound[1].setVolume(0.f);
    sound[1].setLoop(true);
    
    sound[2].loadSound("string3.wav");
    sound[2].setVolume(0.f);
    sound[2].setLoop(true);
    
    sound[3].loadSound("string4.wav");
    sound[3].setVolume(0.f);
    sound[3].setLoop(true);
    
    sound[4].loadSound("string5.wav");
    sound[4].setVolume(0.f);
    sound[4].setLoop(true);
    
    sound[5].loadSound("string6.wav");
    sound[5].setVolume(0.f);
    sound[5].setLoop(true);
    
    
    
    for (int i=0; i<6; i++) {
        a[i] = ofVec2f(ofGetWidth()/4, ofGetHeight()/7 + ofGetHeight()/7*i);
        b[i] = ofVec2f(ofGetWidth()*3/4, ofGetHeight()/7 + ofGetHeight()/7*i);
        j[i] = 1.f;
        collision[i] = false;
        soundPlay[i] = false;
        sound[i].play();  //when you run the 6sound will turn on together
    }
    
    r = 15;
}

//--------------------------------------------------------------
void testApp::update(){
    
    c = ofVec2f(mouseX, mouseY);
    
    for (int i=0; i<6; i++) {
        if (minimum_distance_Squared(a[i], b[i], c) < r*r) {
            collision[i] = true;
            soundPlay[i] = true;
            j[i] = 1.f;
        }
        else{
            collision[i] = false;
            
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<6; i++) {
        ofSetColor(255);
        ofCircle(a[i], 20);
        ofCircle(b[i],20);
        ofLine(a[i],b[i]);
        if ( j[i] < 1.1f && soundPlay[i]) {
            ofSetColor(255, 0, 0);
            ofCircle(c, 14);
            sound[i].setVolume(j[i]);
            j[i] *= 0.992;
            cout<<j[i]<<endl;
        }
    }
    
}

//--------------------------------------------------------------
float testApp::minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p){
    
    
    // Return minimum distance between line segment vw and point p
    const float l2 = ofDistSquared(v.x, v.y, w.x, w.y);  // i.e. |w-v|^2 -  avoid a sqrt
    if (l2 == 0.0) return ofDistSquared(p.x, p.y, v.x, v.y);   // v == w case
    // Consider the line extending the segment, parameterized as v + t (w - v).
    // We find projection of point p onto the line.
    // It falls where t = [(p-v) . (w-v)] / |w-v|^2
    const float t =(p - v).dot(w - v) / l2;
    
    if (t < 0.0) return ofDistSquared(p.x, p.y, v.x, v.y);       // Beyond the 'v' end of the segment
    else if (t > 1.0) return ofDistSquared(p.x, p.y, w.x, w.y);  // Beyond the 'w' end of the segment
    const ofVec2f projection = v + t * (w - v);  // Projection falls on the segment
    return ofDistSquared(p.x, p.y, projection.x, projection.y);
    
    
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

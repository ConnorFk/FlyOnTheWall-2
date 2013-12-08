#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //Load Image
    particleImage.loadImage("particle.png");
    
    a.set(ofGetWidth()/4, ofGetHeight()/4);
    b.set(ofGetWidth()*3/4, ofGetHeight()*3/4);
    NumPoints = 40;
    
    for (int i = 0; i < NumPoints; i++){
        ofVec2f pos = ofVec2f((b-a).x/NumPoints*i,(b-a).y/NumPoints*i);
        pointsOnString.push_back(pos);
    }
    
    A = 70;
    J = 1.f;
    decay=1;
    n = 1;
    
    mus.loadSound("mus2.wav");
    mus.play();
    mus.setVolume(0.f);
    mus.setLoop(true);
    soundPlay = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    L = ofDist(a.x, a.y, b.x, b.y);
    c = ofVec2f(mouseX, mouseY);
    
    ofPushMatrix();
    ofTranslate(a);
    decay *= 0.97;
    ofVec2f q=ofVec2f(1,0);
    float angle=q.angle(b-a);
    ofRotateZ(angle);
    
    for (int i = 1; i < pointsOnString.size(); i++){
        pointsOnString[i].x = L/NumPoints*i;
        pointsOnString[i].y = A*sin(n*PI/L*i*L/NumPoints)*cos(TWO_PI*20/2/L*ofGetElapsedTimef()*800) * decay;
    }
    
    if (minimum_distance_Squared(a, b, c) < 5*5){
        if ((c-a).dot(c-a) < L*L/(3*3)) {
            n=3;
            decay = 1;
        }
        if ((c-a).dot(c-a) > L*L/(3*3) && (c-a).dot(c-a) < L*L*4/9) {
            n=1;
            decay = 1;
        }
        if( ((c-a).dot(c-a) >  L*L*4/9)){
            n=3;
            decay=1;
        }
        soundPlay = true;
        J = 1.f;
        
    }
    
    if(J < 1.1 && soundPlay){
        mus.setVolume(J);
        J *= 0.99;
    }
    cout<<J<<endl;
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(10, 20, 80);
    ofCircle(a, 10);
    ofSetColor(255, 20, 80);
    ofCircle(b, 10);
    ofSetColor(10, 20, 80);
    
    ofCircle(c, 20);
    
    ofPushMatrix();
    ofTranslate(a);
    ofVec2f q=ofVec2f(1,0);
    float angle=q.angle(b-a);
    ofRotateZ(angle);
    
    for (int i = 0; i < pointsOnString.size(); i++){
        //        ofLine(pointsOnString[i], pointsOnString[i+1]);
        pointsOnString[NumPoints] = ofVec2f(L, 0);
        //        ofCircle(pointsOnString[i], 10);
        //        ofCircle(pointsOnString[NumPoints], 2);
        particleImage.draw(pointsOnString[i].x -16, pointsOnString[i].y -16);
    }
    
    ofPopMatrix();
    
    
    
}

//--------------------------------------------------------------
float testApp::minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p){
    
    
    // Return minimum distance between line segment vw and point p
    const float l2 = ofDistSquared(v.x, v.y, w.x, w.y);  // i.e. |w-v|^2 -  avoid a sqrt
    if (l2 == 0.0) return ofDist(p.x, p.y, v.x, v.y);   // v == w case
    // Consider the line extending the segment, parameterized as v + t (w - v).
    // We find projection of point p onto the line.
    // It falls where t = [(p-v) . (w-v)] / |w-v|^2
    const float t =(p - v).dot(w - v) / l2;
    
    if (t < 0.0) return ofDist(p.x, p.y, v.x, v.y);       // Beyond the 'v' end of the segment
    else if (t > 1.0) return ofDist(p.x, p.y, w.x, w.y);  // Beyond the 'w' end of the segment
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

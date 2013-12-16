#include "testApp.h"
#include "MyString.h"

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

    //----------------------------------------------
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for(int i = 0; i < 6; i++){
       s[i].setup(ofGetWidth()/4, ofGetWidth()*3/4, ofGetHeight()/7*(i+1));
       soundPlay[i] = false;
       j[i] = 1.f;
       sound[i].play();  //when you run the 6sound will turn on together
    }
    
    for (unsigned int i = 0; i < 100; i++){
        particles.push_back(new particle());
	}

    
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        float cirVal = ofRandom(TWO_PI);
        float vx = cos(cirVal) * ofRandom(0,4);
        float vy = sin(cirVal) * ofRandom(0,4);
        (*iter)->setInitialCondition(300, 300, vx, vy);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    mouse.x = mouseX;
    mouse.y = mouseY;
    for(int i = 0; i < 6; i++){
       s[i].ifCollision(mouse);
       s[i].update();
        if(s[i].collision){
            drawParticles();
            j[i] = 1.f;
            soundPlay[i] = true;
        }
        if (ofGetFrameRate() < 55) {
            pointsOnString.clear();
        }
    }
    
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
		(*iter)->resetForce();
		(*iter)->addForce(0,0.04);  // gravity
		(*iter)->addDampingForce();
		(*iter)->update();
	}
    alp += 1;


}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < 6; i++){
        s[i].draw();
        
        if(j[i] < 1.1f && soundPlay[i]){             //sound part
            
            sound[i].setVolume(j[i]);
            j[i] *= 0.992;
            cout<<j[i]<<endl;
            
        }

        
        if (s[i].collision == 1) {
            ofCircle(mouseX, mouseY, 20);
        }

        
    }
    
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        (*iter)->draw();
    }


}

//--------------------------------------------------------------
void testApp::drawParticles(){
    alp = 0;
    //for (int i = 0; i < particles.size(); i++){
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        float cirVal = ofRandom(TWO_PI);
        
        float vx = cos(cirVal) * ofRandom(0,4);
        float vy = sin(cirVal) * ofRandom(0,4);
        (*iter)->setInitialCondition(mouseX,mouseY,vx, vy);
        
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

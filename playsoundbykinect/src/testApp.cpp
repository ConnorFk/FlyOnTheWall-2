#include "testApp.h"
#include "MyString.h"

//--------------------------------------------------------------
void testApp::setup() {
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();
    
    // set properties for all user masks and point clouds
    //openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
    openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
    openNIDevice.setUsePointCloudsAllUsers(true);
    openNIDevice.setPointCloudDrawSizeAllUsers(2); // size of each 'point' in the point cloud
    openNIDevice.setPointCloudResolutionAllUsers(2); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel
    
    // you can alternatively create a 'base' user class
    //    ofxOpenNIUser user;
    //    user.setUseMaskTexture(true);
    //    user.setUsePointCloud(true);
    //    user.setPointCloudDrawSize(2);
    //    user.setPointCloudResolution(2);
    //    openNIDevice.setBaseUserClass(user);
    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
   
    
    
    
    
//----------------------------------------sound setting part
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

//        b[i] = ofVec2f(ofGetWidth()*3/4, ofGetHeight()/7 + ofGetHeight()/7*i);
        j[i] = 1.f;
//        collision[i] = false;
        soundPlay[i] = false;
        sound[i].play();  //when you run the 6sound will turn on together
    }
    
    r = 15;
    
    //----------------------------------------------
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    head2.x = ofGetWidth()*3/4;
    head2.y = ofGetHeight()/7;
    neck2.x = ofGetWidth()*3/4;
    neck2.y = ofGetHeight()*2/7;
    rightShoulder2.x = ofGetWidth()*3/4;
    rightShoulder2.y = ofGetHeight()*3/7;
    torso2.x = ofGetWidth()*3/4;
    torso2.y = ofGetHeight()*4/7;
    righthip2.x = ofGetWidth()*3/4;
    righthip2.y = ofGetHeight()*5/7;
    rightknee2.x = ofGetWidth()*3/4;
    rightknee2.y = ofGetHeight()*6/7;
    

    
    
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
    openNIDevice.update();
    
    s[0].setup(head1,head2);
    s[1].setup(neck1,neck2);
    s[2].setup((neck1+torso1)/2,rightShoulder2) ;
    s[3].setup(torso1,torso2);
    s[4].setup(lefthip1,righthip2);
    s[5].setup(leftknee1,rightknee2);
    

    mouse = rightHand1;

    
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
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    openNIDevice.drawDebug();
    ofPopMatrix();
    
    ofPushMatrix();
    // use a blend mode so we can see 'through' the mask(s)
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // get number of current users
    int numUsers = openNIDevice.getNumTrackedUsers();
    
    // iterate through users
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
        leftHand1 = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition();
        rightHand1 = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition();
        head1 = user.getJoint(JOINT_HEAD).getProjectivePosition();
        leftShoulder1 = user.getJoint(JOINT_LEFT_SHOULDER).getProjectivePosition();
        leftelbow1 = user.getJoint(JOINT_LEFT_ELBOW).getProjectivePosition();
        rightelbow1 = user.getJoint(JOINT_RIGHT_ELBOW).getProjectivePosition();
        rightShoulder1 = user.getJoint(JOINT_RIGHT_SHOULDER).getProjectivePosition();
        leftFoot1 = user.getJoint(JOINT_LEFT_FOOT).getProjectivePosition();
        rightFoot1 = user.getJoint(JOINT_RIGHT_FOOT).getProjectivePosition();
        neck1= user.getJoint(JOINT_NECK).getProjectivePosition();
        leftknee1= user.getJoint(JOINT_LEFT_KNEE).getProjectivePosition();
        lefthip1= user.getJoint(JOINT_LEFT_HIP).getProjectivePosition();
        torso1= user.getJoint(JOINT_TORSO).getProjectivePosition();
        rightknee1= user.getJoint(JOINT_RIGHT_KNEE).getProjectivePosition();
        righthip1= user.getJoint(JOINT_RIGHT_HIP).getProjectivePosition();
        
        
        

        
        // draw the mask texture for this user
        user.drawMask();
        
        // you can also access the pixel and texture references individually:
        
        // TEXTURE REFERENCE
        //ofTexture & tex = user.getMaskTextureReference();
        // do something with texture...
        
        // PIXEL REFERENCE
        //ofPixels & pix = user.getMaskPixels();
        // do something with the pixels...
        
        // and point clouds:
        
        ofPushMatrix();
        // move it a bit more central
        ofTranslate(320, 240, 10);
        user.drawPointCloud();
        
        // you can also access the mesh:
        
        // MESH REFERENCE
        //ofMesh & mesh = user.getPointCloud();
        // do something with the point cloud mesh
        
        ofPopMatrix();
        
    }
    
    ofDisableBlendMode();
    ofPopMatrix();
    

    ofSetColor(100);
    ofRect(0, 0, 2000, 2000);
    
    
    ofPushMatrix();
    // move it a bit more central
    ofTranslate(20, 40);
    ofSetColor(255, 0, 0);
    //        ofCircle(leftHand, 30);
    ofCircle(rightHand1, 5);
    //        ofCircle(head, 30);
    //        ofCircle(leftShoulder, 30);
    //        ofCircle(rightShoulder, 30);
    //        ofCircle(leftFoot, 30);
    //        ofCircle(rightFoot, 30);
   

    ofSetColor(0,255,223);
    ofSetLineWidth(5);
    
    ofLine(head1,neck1);
    ofLine(neck1,rightShoulder1);
    ofLine(neck1,leftShoulder1);
    ofLine(rightShoulder1, rightelbow1);
    ofLine(rightelbow1, rightHand1);
    ofLine(leftShoulder1, leftelbow1);
    ofLine(leftelbow1, leftHand1);
    ofLine(neck1, torso1);
    ofLine(torso1, lefthip1);
    ofLine(torso1, righthip1);
    ofLine(lefthip1, leftknee1);
    ofLine(leftknee1, leftFoot1);
    ofLine(righthip1, rightknee1);
    ofLine(rightknee1, rightFoot1);
    
    
    
        for(int i = 0; i < 6; i++){
            s[i].draw();
            
            if(j[i] < 1.1f && soundPlay[i]){
                sound[i].setVolume(j[i]);
                j[i] *= 0.992;
                cout<<j[i]<<endl;
            }
            
//            if (s[i].collision == 1) {
//                ofCircle(mouseX, mouseY, 20);
//            }
            
        }
        /*----------------------------------------particle part*/
        for(pIter iter=particles.begin();iter !=particles.end();++iter){
            (*iter)->draw();
        }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::drawParticles(){
    alp = 0;
    //for (int i = 0; i < particles.size(); i++){
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        float cirVal = ofRandom(TWO_PI);
        
        float vx = cos(cirVal) * ofRandom(0,4);
        float vy = sin(cirVal) * ofRandom(0,4);
        (*iter)->setInitialCondition(mouse.x,mouse.y,vx, vy);
        
    }
    
}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){
    // show user event messages in the console
    ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
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
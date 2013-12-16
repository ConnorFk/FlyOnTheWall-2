#include "testApp.h"
#include "Mystring.h"

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
    
    Belgrad.loadFont("verdana.ttf", 24);
    
    
    /*-------------------------------sound & graphic effects*/
    
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
    ofBackground(100);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for(int i = 0; i < 6; i++){
        s[i].setup(ofGetWidth()/4, ofGetWidth()*3/4, ofGetHeight()/5 + ofGetHeight()/15*i);
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
    
    
    /*----------------------------------------spacebrew part*/
    // init spacebrew
    string host = "75.101.237.143"; // "localhost";
    string name = "string_senderSHG";
    string description = "stringsenderSHG";
    
    // general setup
    ofSetFrameRate(30);
    
    //------------send signal-----------
    spacebrew.addPublish("torsoX", "range");
    spacebrew.addPublish("torsoY", "range");
    spacebrew.addPublish("neckX", "range");
    spacebrew.addPublish("neckY", "range");
    spacebrew.addPublish("headX", "range");
    spacebrew.addPublish("headY", "range");
    
    spacebrew.addPublish("leftShoulderX", "range");
    spacebrew.addPublish("leftShoulderY", "range");
    spacebrew.addPublish("leftElbowX", "range");
    spacebrew.addPublish("leftElbowY", "range");
    spacebrew.addPublish("leftHandX", "range");
    spacebrew.addPublish("leftHandY", "range");
    
    spacebrew.addPublish("rightShoulderX", "range");
    spacebrew.addPublish("rightShoulderY", "range");
    spacebrew.addPublish("rightElbowX", "range");
    spacebrew.addPublish("rightElbowY", "range");
    spacebrew.addPublish("rightHandX", "range");
    spacebrew.addPublish("rightHandY", "range");
    
    spacebrew.addPublish("leftHipX", "range");
    spacebrew.addPublish("leftHipY", "range");
    spacebrew.addPublish("leftKneeX", "range");
    spacebrew.addPublish("leftKneeY", "range");
    spacebrew.addPublish("leftFootX", "range");
    spacebrew.addPublish("leftFootY", "range");
    
    spacebrew.addPublish("rightHipX", "range");
    spacebrew.addPublish("rightHipY", "range");
    spacebrew.addPublish("rightKneeX", "range");
    spacebrew.addPublish("rightKneeY", "range");
    spacebrew.addPublish("rightFootX", "range");
    spacebrew.addPublish("rightFootY", "range");
    
    //------------receive---------------------
    
    spacebrew.addSubscribe("torsoX", "range");
    spacebrew.addSubscribe("torsoY", "range");
    spacebrew.addSubscribe("neckX", "range");
    spacebrew.addSubscribe("neckY", "range");
    spacebrew.addSubscribe("headX", "range");
    spacebrew.addSubscribe("headY", "range");
    
    spacebrew.addSubscribe("leftShoulderX", "range");
    spacebrew.addSubscribe("leftShoulderY", "range");
    spacebrew.addSubscribe("leftElbowX", "range");
    spacebrew.addSubscribe("leftElbowY", "range");
    spacebrew.addSubscribe("leftHandX", "range");
    spacebrew.addSubscribe("leftHandY", "range");
    
    spacebrew.addSubscribe("rightShoulderX", "range");
    spacebrew.addSubscribe("rightShoulderY", "range");
    spacebrew.addSubscribe("rightElbowX", "range");
    spacebrew.addSubscribe("rightElbowY", "range");
    spacebrew.addSubscribe("rightHandX", "range");
    spacebrew.addSubscribe("rightHandY", "range");
    
    spacebrew.addSubscribe("leftHipX", "range");
    spacebrew.addSubscribe("leftHipY", "range");
    spacebrew.addSubscribe("leftKneeX", "range");
    spacebrew.addSubscribe("leftKneeY", "range");
    spacebrew.addSubscribe("leftFootX", "range");
    spacebrew.addSubscribe("leftFootY", "range");
    
    spacebrew.addSubscribe("rightHipX", "range");
    spacebrew.addSubscribe("rightHipY", "range");
    spacebrew.addSubscribe("rightKneeX", "range");
    spacebrew.addSubscribe("rightKneeY", "range");
    spacebrew.addSubscribe("rightFootX", "range");
    spacebrew.addSubscribe("rightFootY", "range");
    
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
    
    // update spacebrew
    if ( spacebrew.isConnected() ){
        
        spacebrew.sendRange("torsoX", torso1.x );
        spacebrew.sendRange("torsoY", torso1.y );
        spacebrew.sendRange("neckX", neck1.x );
        spacebrew.sendRange("neckY", neck1.y );
        spacebrew.sendRange("headX", head1.x );
        spacebrew.sendRange("headY", head1.y );
        
        spacebrew.sendRange("leftShoulderX", leftShoulder1.x) ;
        spacebrew.sendRange("leftShoulderY", leftShoulder1.y) ;
        spacebrew.sendRange("leftElbowX", leftelbow1.x);
        spacebrew.sendRange("leftElbowY", leftelbow1.y);
        spacebrew.sendRange("leftHandX", leftHand1.x);
        spacebrew.sendRange("leftHandY", leftHand1.y);
        
        spacebrew.sendRange("rightShoulderX", rightShoulder1.x );
        spacebrew.sendRange("rightShoulderY", rightShoulder1.y );
        spacebrew.sendRange("rightElbowX", rightelbow1.x);
        spacebrew.sendRange("rightElbowY", rightelbow1.y);
        spacebrew.sendRange("rightHandX", rightHand1.x);
        spacebrew.sendRange("rightHandY", rightHand1.y);
        
        spacebrew.sendRange("leftHipX", lefthip1.x);
        spacebrew.sendRange("leftHipY", lefthip1.y);
        spacebrew.sendRange("leftKneeX", leftknee1.x);
        spacebrew.sendRange("leftKneeY", leftknee1.y);
        spacebrew.sendRange("leftFootX", leftFoot1.x);
        spacebrew.sendRange("leftFootY", leftFoot1.y);
        
        spacebrew.sendRange("rightHipX", righthip1.x);
        spacebrew.sendRange("rightHipY", righthip1.y);
        spacebrew.sendRange("rightKneeX", rightknee1.x);
        spacebrew.sendRange("rightKneeY", rightknee1.y);
        spacebrew.sendRange("rightFootX", rightFoot1.x);
        spacebrew.sendRange("rightFootY", rightFoot1.y);
    }
    
    /*-------------------------------sound & graphic effects*/
    mouse=rightHand1;
    
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
    
    
    ofSetColor(0);
    ofRect(0, 0, 2000, 2000);
    
    
    ofSetColor(0,255,223);
    ofSetLineWidth(5);
    
    ofPushMatrix();
    ofTranslate(0, 100);
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
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(800, 100);
    
    ofSetColor(255,0,124);
    ofSetLineWidth(5);
    
    ofLine(head2,neck2);
    ofLine(neck2,rightShoulder2);
    ofLine(neck2,leftShoulder2);
    ofLine(rightShoulder2, rightelbow2);
    ofLine(rightelbow2, rightHand2);
    ofLine(leftShoulder2, leftelbow2);
    ofLine(leftelbow2, leftHand2);
    ofLine(neck2, torso2);
    ofLine(torso2, lefthip2);
    ofLine(torso2, righthip2);
    ofLine(lefthip2, leftknee2);
    ofLine(leftknee2, leftFoot2);
    ofLine(righthip2, rightknee2);
    ofLine(rightknee2, rightFoot2);
    ofPopMatrix();
    
    
    /*-------------------------------sound & graphic effects*/
    for(int i = 0; i < 6; i++){
        s[i].draw(particles[0]->c);
        
        if(j[i] < 1.1f && soundPlay[i]){             //sound part
            
            sound[i].setVolume(j[i]);
            j[i] *= 0.992;
            cout<<j[i]<<endl;
            
        }
        
        ofPushMatrix();
        ofTranslate(0, 100);
        if (s[i].collision == 1) {
            ofCircle(mouse.x, mouse.y, 10);
        }
        ofPopMatrix();
        
        
    }
    
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        (*iter)->draw();
    }
    
    /*-------------------------------font*/
    string msg1 = " Shanghai ";
    string msg2 = " New York ";
    
    ofSetColor(255);
	Belgrad.drawString(msg1, 150, 800);
    Belgrad.drawString(msg2, 1100, 800);
    
    
}

//--------------------------------------------------------------
void testApp::drawParticles(){
    alp = 0;
    //for (int i = 0; i < particles.size(); i++){
    for(pIter iter=particles.begin();iter !=particles.end();++iter){
        float cirVal = ofRandom(TWO_PI);
        
        float vx = cos(cirVal) * ofRandom(0,4);
        float vy = sin(cirVal) * ofRandom(0,4);
        (*iter)->setInitialCondition(mouse.x,mouse.y,vx*2, vy*2);
        
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
// SPACEBREW
void testApp::onMessage( Spacebrew::Message & m ){
    //----------------------------
    if (m.name=="torsoX") {
        torso2.x=m.valueRange();
    }
    if (m.name=="torsoY") {
        torso2.y=m.valueRange();
    }
    if (m.name=="neckX") {
        neck2.x=m.valueRange();
    }
    if (m.name=="neckY") {
        neck2.y=m.valueRange();
    }
    if (m.name=="headX") {
        head2.x=m.valueRange();
    }
    if (m.name=="headY") {
        head2.y=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftShoulderX") {
        leftShoulder2.x=m.valueRange();
    }
    if (m.name=="leftShoulderY") {
        leftShoulder2.y=m.valueRange();
    }
    if (m.name=="leftElbowX") {
        leftelbow2.x=m.valueRange();
    }
    if (m.name=="leftElbowY") {
        leftelbow2.y=m.valueRange();
    }
    if (m.name=="leftHandX") {
        leftHand2.x=m.valueRange();
    }
    if (m.name=="leftHandY") {
        leftHand2.y=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightShoulderX") {
        rightShoulder2.x=m.valueRange();
    }
    if (m.name=="rightShoulderY") {
        rightShoulder2.y=m.valueRange();
    }
    if (m.name=="rightElbowX") {
        rightelbow2.x=m.valueRange();
    }
    if (m.name=="rightElbowY") {
        rightelbow2.y=m.valueRange();
    }
    if (m.name=="rightHandX") {
        rightHand2.x=m.valueRange();
    }
    if (m.name=="rightHandY") {
        rightHand2.y=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftHipX") {
        lefthip2.x=m.valueRange();
    }
    if (m.name=="leftHipY") {
        lefthip2.y=m.valueRange();
    }
    if (m.name=="leftKneeX") {
        leftknee2.x=m.valueRange();
    }
    if (m.name=="leftKneeY") {
        leftknee2.y=m.valueRange();
    }
    if (m.name=="leftFootX") {
        leftFoot2.x=m.valueRange();
    }
    if (m.name=="leftFootY") {
        leftFoot2.y=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightHipX") {
        righthip2.x=m.valueRange();
    }
    if (m.name=="rightHipY") {
        righthip2.y=m.valueRange();
    }
    if (m.name=="rightKneeX") {
        rightknee2.x=m.valueRange();
    }
    if (m.name=="rightKneeY") {
        rightknee2.y=m.valueRange();
    }
    if (m.name=="rightFootX") {
        rightFoot2.x=m.valueRange();
    }
    if (m.name=="rightFootY") {
        rightFoot2.y=m.valueRange();
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
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackground(0, 0, 0);
    ofBackground(255, 255, 255);

//    //--------------------------------panel setting
//    panel.setup("shader settings", 720, 0, 300, 748);
//	panel.addPanel("shader", 1, false);
//    
//	panel.setWhichPanel("control");
//	panel.setWhichColumn(0);
//	//panel.addSlider("LightPosition ", "LIGHTPOSITION", 1.648, 0.28, 1.0f, true);
//    panel.addSlider("surfaceColorR", "SURFACECOLORR", 0.f, 0.,5., true);
//    panel.addSlider("surfaceColorG", "SURFACECOLORG", 0.f, 0.,5., true);
//    panel.addSlider("surfaceColorB", "SURFACECOLORB", 0.f, 0.,5., true);
//    panel.addSlider("surfaceColorE", "SURFACECOLORE", 0.f, 0.,5., true);
//    panel.addSlider("offset1","OFFSET1", -1.857f, -5.f, 5.f, true);
//    panel.addSlider("offset2","OFFSET2", 100.5f, -50.f, 500.f, true);
//    panel.addSlider("offset3","OFFSET3", 0.5f, -50.f, 50.f, true);
//    panel.addSlider("scaleIn","SCALEIN", -5.873,-10,100, true);
//    panel.addSlider("scaleOut","SCALEOUT", 5.f,0,800, true);
//    panel.addSlider("Freq","FREQ",0.f, -100.f,100.f,true);
//    panel.addSlider("Width","WIDTH",1.f,0,5,true);
//    panel.addSlider("Width1","WIDTH1",400.f,0.,800.,true);
//    panel.addSlider("Height","HEIGHT",400.f,0.,800.,true);
//    panel.addSlider("StripeShift","STRIPESHIFT",100.f,0.f,200.f,true);
//	panel.loadSettings("cvSettings.xml");
//    
    
    //--------------------------------shader setting
    ofDisableArbTex();
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
    glEnable(GL_DEPTH_TEST);
    
    
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    shader.load("shaders/vnoise.vert", "shaders/vnoise.frag");
    
    counter = 0;
    blendValue = 0;
    
    time = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    time+=0.02;
    
//    panel.update();
 
    //--------------------------------this part is strange now. i want to change the color of the string that my mouse touch
    //--------------------------------but it seems the color only change when all the strings are on top of my mouse.
    
//    if ( col == 0) {
//        surfaceColorR = panel.getValueI("SURFACECOLORR");
//        surfaceColorG = panel.getValueI("SURFACECOLORG");
//        surfaceColorB = panel.getValueI("SURFACECOLORB");
//        surfaceColorE = panel.getValueI("SURFACECOLORE");
//    } else if ( col == 1) {
//        
//        for ( i = 0; i< NUM; i++){
//            
//            surfaceColorR = ofNoise(i*10);
//            surfaceColorG = ofNoise(i*10+time*100);
//            surfaceColorB = ofNoise(i*10+time*2000);
//           // surfaceColorE = ofNoise(i+time*30);
//            
//        }
//
//    }
 
//    surfaceColorR = panel.getValueI("SURFACECOLORR");
//    surfaceColorG = panel.getValueI("SURFACECOLORG");
//    surfaceColorB = panel.getValueI("SURFACECOLORB");
//    surfaceColorE = panel.getValueI("SURFACECOLORE");
//    offset1 = panel.getValueI("OFFSET1");
//    offset2 = panel.getValueI("OFFSET2");
//    offset3 = panel.getValueI("OFFSET3");
//    scaleIn = panel.getValueI("SCALEIN");
//    scaleOut = panel.getValueI("SCALEOUT");
//    Freq = panel.getValueI("FREQ");
//    Width = panel.getValueI("WIDTH");
//    Width1 = panel.getValueI("WIDTH1");
//    Height = panel.getValueI("HEIGHT");
//    StripeShift = panel.getValueI("STRIPESHIFT");


}

//--------------------------------------------------------------
void testApp::draw(){
    //panel.draw();

    
    //--------------------------------part of shader/render waves
    //cam.begin();
    shader.begin();
    
    shader.setUniform3f("LightPosition",1.648, 10., 1.0f);
    shader.setUniform4f("surfaceColor", 0.f, 0.f, 0.f, 1.f);
    shader.setUniform3f("offset", -3, 147, 43);
    shader.setUniform1f("scaleIn", 16);
    shader.setUniform1f("scaleOut", 17);
    
    shader.setUniform1f("Freq",0);
    shader.setUniform1f("Width",35);
    shader.setUniform1f("StripeShift",93);
    
    ofPushMatrix();
    ofTranslate(0, 150);
    for( j = 0; j < 6; j++){
        for( i = 0; i < NUM; i++){
            pos.push_back(ofPoint());
            pos[i].x = 5 + i * 5;
            pos[i].y = ofNoise ( time + i * 0.005 + j ) * 250 + j * 30;   // set up a noise time offest by i value
            
            ofCircle(pos[i].x, pos[i].y, 3);
            
            
            if ( i < NUM-1  ){
                
                ofLine(pos[i].x, pos[i].y,pos[i+1].x, pos[i+1].y);
                
            }
            else{   //---------to draw the last line made of last two points which are out of the i&j drawing loop
                ofLine(pos[499].x, pos[499].y,2505, ofNoise((time+0.02)+2.5+j)*150+j*30);
            }
        }
    }
    ofPopMatrix();
    
    //cam.end();
    shader.end();
    
    
    
    
    //--------------------------------part of normal waves. the strange thing here is the strings I draw below supposed to be on top layer but it draws on the bottom of the shader strings.
    ofPushMatrix();
    ofTranslate(0, 150);
    for( j = 0; j < 6; j++){
        for( i = 0; i < NUM; i++){
            pos.push_back(ofPoint());
            pos[i].x = 5 + i * 5;
            pos[i].y = ofNoise ( time + i * 0.005 + j ) * 250 + j * 30;   // set up a noise time offest by i value
            if (pos[i].y < mouseY-200+0.01) {
                
                ofSetColor(250, 50, 250);
                
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
void testApp::mouseMoved(int x, int y){
    mMouse.x = x;
    mMouse.y = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    panel.mouseDragged(x,y,button);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    panel.mousePressed(x,y,button);

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    panel.mouseReleased();

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
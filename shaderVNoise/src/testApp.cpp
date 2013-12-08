#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackground(0, 0, 0);
    ofBackground(255, 255, 255);

    //--------------------------------panel set up
    panel.setup("shader settings", 720, 0, 300, 748);
	panel.addPanel("shader", 1, false);
    
	panel.setWhichPanel("control");
	panel.setWhichColumn(0);
	//panel.addSlider("LightPosition ", "LIGHTPOSITION", 1.648, 0.28, 1.0f, true);
    panel.addSlider("surfaceColorR", "SURFACECOLORR", 1.0f, 0.,5., true);
    panel.addSlider("surfaceColorG", "SURFACECOLORG", 1.0f, 0.,5., true);
    panel.addSlider("surfaceColorB", "SURFACECOLORB", 1.0f, 0.,5., true);
    panel.addSlider("surfaceColorE", "SURFACECOLORE", 1.0f, 0.,5., true);
    panel.addSlider("offset1","OFFSET1", -1.857f, -5.f, 5.f, true);
    panel.addSlider("offset2","OFFSET2", 100.5f, 50.f, 500.f, true);
    panel.addSlider("offset3","OFFSET3", 0.5f, -5.f, 100.f, true);
    panel.addSlider("scaleIn","SCALEIN", -5.873,-10,100, true);
    panel.addSlider("scaleOut","SCALEOUT", 10.f,0,800, true);
    panel.addSlider("Freq","FREQ",0.f, 0,200.f,true);
    panel.addSlider("Width","WIDTH",1.f,0,5,true);
    panel.addSlider("Width1","WIDTH1",400.f,0.,800.,true);
    panel.addSlider("Height","HEIGHT",400.f,0.,800.,true);

    panel.addSlider("StripeShift","STRIPESHIFT",100.f,50.f,200.f,true);
	
	panel.loadSettings("cvSettings.xml");
    
    
    //--------------------------------
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
    
    

}

//--------------------------------------------------------------
void testApp::update(){
    panel.update();
    
    surfaceColorR = panel.getValueI("SURFACECOLORR");
    surfaceColorG = panel.getValueI("SURFACECOLORG");
    surfaceColorB = panel.getValueI("SURFACECOLORB");
    surfaceColorE = panel.getValueI("SURFACECOLORE");
    offset1 = panel.getValueI("OFFSET1");
    offset2 = panel.getValueI("OFFSET2");
    offset3 = panel.getValueI("OFFSET3");
    scaleIn = panel.getValueI("SCALEIN");
    scaleOut = panel.getValueI("SCALEOUT");
    Freq = panel.getValueI("FREQ");
    Width = panel.getValueI("WIDTH");
    Width1 = panel.getValueI("WIDTH1");
    Height = panel.getValueI("HEIGHT");
    StripeShift = panel.getValueI("STRIPESHIFT");


}

//--------------------------------------------------------------
void testApp::draw(){
    panel.draw();
    
    cam.begin();
    shader.begin();

    
    shader.setUniform3f("LightPosition",1.648, 10., 1.0f);
    shader.setUniform4f("surfaceColor", surfaceColorR, surfaceColorG, surfaceColorB, surfaceColorE);
    shader.setUniform3f("offset", offset1, offset2, offset3);
    shader.setUniform1f("scaleIn", scaleIn);
    shader.setUniform1f("scaleOut", scaleOut);
    
    shader.setUniform1f("Freq",Freq);
    shader.setUniform1f("Width",Width);
    shader.setUniform1f("StripeShift",StripeShift);
    
    
    
    ofRotateY(360*sinf(float(ofGetFrameNum())/500.0f));
    ofRotate(-90, 1, 0, 0);
    
    
    gluSphere(quadric, 150, Width1, Height);
    
    shader.end();
    cam.end();

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
#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
//    particleImage.loadImage("particle.png");
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity
	// damping is a force operating in the oposite direction of the
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}




//------------------------------------------------------------
void particle::draw(){
//    particleImage.draw(pos.x -16, pos.y -16);

    float hue;
    hue = ofMap(atan2(vel.y, vel.x), -PI, PI, 0, 255);
    ofSetColor(ofColor::fromHsb(hue, 225, 225));
    
    ofCircle(pos.x, pos.y, 1.5);
    
}


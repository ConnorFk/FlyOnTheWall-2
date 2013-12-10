//
//  Mystring.cpp
//  6Strings_wave
//
//  Created by Connor on 13-12-10.
//
//

#include "ofMain.h"
#include "testApp.h"
#include "MyString.h"

//--------------------------------------------------------------
void MyString :: setup(int leftpos, int rightpos, int ypos){

    left.x = leftpos;
    right.x = rightpos;
    y = ypos;
    left.y=ypos;
    right.y=ypos;
    collision = false;
    A = 70;
    n = 0;
    L = rightpos - leftpos;
    Lsq = L*L;
    for(int i = 0; i < 40; i++){
        Points[i].x = leftpos+L/40*i;
        Points[i].y = y;
    }
    
}

//--------------------------------------------------------------
void MyString :: update(){
    decay *= 0.97;  //decay magnitude
    if(decay < 0.01){
        decay = 0;
    }
    for(int i = 0; i < 40; i++){
        Points[i].y = y+A*sin(n*PI/L*i*L/40)*cos(TWO_PI*20/2/L*ofGetElapsedTimef()*250)*decay;
        
    }
}

//--------------------------------------------------------------
void MyString :: draw(){
    for(int i = 0; i < 40; i++){
        ofCircle(Points[i].x, Points[i].y, 2);
    }
}

//--------------------------------------------------------------
void MyString :: ifCollision(ofVec2f m){
    
    float dist=minimum_distance_Squared(left, right, m);
    
    
    if (dist < 15*15){  //squared of minimum distance
        if ((m-left).dot(m-left) < Lsq/(3*3)) {  //when collision point is near to a
            n=3;
            A = 40;
            decay = 1;

        }
        if ((m-left).dot(m-left) > Lsq/(3*3) && (m-left).dot(m-left) < Lsq*4/9) { //when collision point is in the middle of a and b
            n=1;
            A = 70;
            decay = 1;

        }
        if( ((m-left).dot(m-left) >  Lsq*4/9)){  //when collision point is near to b
            n=2;
            A= 40;
            decay = 1;

        }
        collision = true;
    }else{
        collision = false;
    }

    
}


//--------------------------------------------------------------
float MyString::minimum_distance_Squared(ofVec2f v, ofVec2f w, ofVec2f p){
    
    
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



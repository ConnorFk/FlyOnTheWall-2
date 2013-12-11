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
void MyString :: setup(ofVec2f leftpos, ofVec2f rightpos){
    
    left.x = leftpos.x;
    right.x = rightpos.x;
    left.y = leftpos.y;
    right.y = rightpos.y;
    //right.y=ypos;
    collision = false;
    A = 70;
    n = 0;
    L.x = abs(rightpos.x - leftpos.x);
    L.y = abs(rightpos.y - leftpos.y);
    Lsq = L.x*L.x + L.y*L.y;
    //Lsq = L*L;
    for(int i = 0; i < 40; i++){
        Points[i].x = leftpos.x+L.x/40*i;
        Points[i].y = leftpos.y+L.y/40*i;
    }
    
}

//--------------------------------------------------------------
void MyString :: update(){
    decay *= 0.97;  //decay magnitude
    if(decay < 0.01){
        decay = 0;
    }
    for(int i = 0; i < 40; i++){
        Points[i].y = left.y+A*sin(n*PI/L.x*i*L.x/40)*cos(TWO_PI*20/2/L.x*ofGetElapsedTimef()*250)*decay;
        cout<<Points[i].y<<endl;
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
    
    if (dist < 5*5){  //squared of minimum distance
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



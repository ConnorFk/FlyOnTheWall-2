

#include "testApp.h"

//--------------------------------------------------------------
void testApp::Parameter_Set(ofVec2f a, ofVec2f b){
    //two points
    NumPoints = 40; //Number of Points on the string
    
    //set points
    for (int i = 0; i < NumPoints; i++){
        ofVec2f pos = ofVec2f((b-a).x/NumPoints*(i),(b-a).y/NumPoints*(i));
        pointsOnString.push_back(pos);
    }
    
    //parameter settings
    //A = 70;
    
}

//--------------------------------------------------------------
void testApp::Vibration_Calc(ofVec2f a, ofVec2f b, ofVec2f c){
    

    ofPushMatrix();
    ofTranslate(a);  //transrate x,y-coordinate to point a
    decay *= 0.97;  //decay magnitude
    if(decay < 0.01){
        decay = 0;
    }
    ofVec2f q=ofVec2f(1,0);  //normal vector
    float angle=q.angle(b-a);  //get angle of q and (b-a)
    ofRotateZ(angle);  //rotate x,y-coordinate(around z-axis)
    float L = abs((b-a).x/cos(angle/180*PI)); // avoid square root
    float Lsq = L*L;
    for (int i = 1; i < 41; i++){
        pointsOnString[i].x = L/NumPoints*i;
        
        pointsOnString[i].y = A*sin(n*PI/L*i*L/NumPoints + sigma)*cos(TWO_PI*20/2/L*ofGetElapsedTimef()*250) * decay;
    }
    
    if (minimum_distance_Squared(a, b, c) < 15*15){  //squared of minimum distance
        
        if ((c-a).dot(c-a) < Lsq/(3*3)) {  //when collision point is near to a
            n=3;
            A = 40;
            decay = 1;
            sigma = 0;
//            sigma = PI/2;
        }
        if ((c-a).dot(c-a) > Lsq/(3*3) && (c-a).dot(c-a) < Lsq*4/9) { //when collision point is in the middle of a and b
            n=1;
            A = 70;
            decay = 1;
            sigma = 0;
        }
        if( ((c-a).dot(c-a) >  Lsq*4/9)){  //when collision point is near to b
            n=2;
            A= 40;
            decay=1;
//            sigma = PI/2;
            sigma = 0;            
        }
        collision[int(a.y)] = true;
    }else{

        collision[int(a.y)] = false;
    }
    ofPopMatrix();

    

}

//--------------------------------------------------------------
void testApp::Vibration_Draw(ofVec2f a, ofVec2f b, ofVec2f c){
    
    ofSetColor(10, 20, 80);
    ofCircle(a, 15+10*sin(ofGetElapsedTimef())*sin(ofGetElapsedTimef()*0.9));
    ofCircle(b, 15+10*sin(ofGetElapsedTimef())*sin(ofGetElapsedTimef()*0.9));
    
    ofCircle(c, 20);
    
    ofPushMatrix();
    ofTranslate(a);
    ofVec2f q=ofVec2f(1,0);
    float angle=q.angle(b-a);
    ofRotateZ(angle);
    
    for (int i = 1; i < 41; i++){
        //pointsOnString[NumPoints] = ofVec2f(L, 0);
        ofCircle(pointsOnString[i], 2);
        ofCircle(pointsOnString[0], 5);
        ofCircle(pointsOnString[40], 5);
    }
    
    ofPopMatrix();
        
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


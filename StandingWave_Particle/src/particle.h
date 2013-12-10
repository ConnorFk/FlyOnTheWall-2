#include "ofMain.h"

class particle{
    public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    void erase();
    
    float damping;
    
    protected:
    private:
    
    ofImage particleImage;

    
};
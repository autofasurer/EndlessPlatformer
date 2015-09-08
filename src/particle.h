//
//  particle.h
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 08/09/15.
//
//

#ifndef EndlessPlatformer_particle_h
#define EndlessPlatformer_particle_h
#include "ofMain.h"
class particle{

public:
    //constructor
    particle();
    
    //methods
    void draw();
    void update();
    
    //variables
    ofVec3f vel;
    ofPoint pos;
    
};
#endif

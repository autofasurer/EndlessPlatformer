//
//  particle.cpp
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 08/09/15.
//
//

#include "particle.h"

//constructor

particle::particle(){
    pos.set(ofGetWidth(), ofRandom(0, ofGetHeight()), 0);
    vel.set(ofRandom(-16, -4), 1, 0);
}

void particle::update(){
    pos += vel;
}
void particle::draw(){
    ofSetColor(255,255,255);
    ofRect(pos.x, pos.y, 3, 1);
}


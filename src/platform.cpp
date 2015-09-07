//
//  platform.cpp
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 06/09/15.
//
//

#include "platform.h"

//constructor
platform::platform(int y){

    platformColor.set(255, 255, 255);
    birthday = ofGetElapsedTimef();
    platformWidth = ofRandom(40, 100);
    y += ofRandom(-150, 150);
    birthPlace = y;
    pos.set(ofGetWidth()+platformWidth, ofClamp(y, 100, ofGetHeight()-100), 0);
    vel.set(-2, 0, 0);
}

void platform::update(){
    pos += vel;
    pos.y += sin(ofGetElapsedTimef()-birthday)/2;
}

void platform::draw(){
    ofSetColor(platformColor);
    ofRect(pos.x, pos.y, platformWidth, 20);
}
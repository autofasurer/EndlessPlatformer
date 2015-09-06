//
//  platform.h
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 06/09/15.
//
//
#include "ofMain.h"

#pragma once
#ifndef EndlessPlatformer_platform_h
#define EndlessPlatformer_platform_h

class platform{
public:
    
    //methods
    void update();
    void draw();
    
    //constructor
    platform(int y);
    
    //variables
    ofPoint pos;
    ofVec3f vel;
    int platformWidth;
    int birthday;
    int birthPlace;
private:
    
};

#endif

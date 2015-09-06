//
//  player.h
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 06/09/15.
//
//
#include "ofMain.h"

#pragma once
#ifndef EndlessPlatformer_player_h
#define EndlessPlatformer_player_h

class player{
    public:
    //constructor
    player();
    //methods
    void update();
    void draw();
    //variables
    bool jumping;
    bool standing;
    bool falling;
    ofPoint pos;
    ofVec3f vel;
    int width, height, jumpConstant;
    float gravity;
    float speed;
    private:
};

#endif

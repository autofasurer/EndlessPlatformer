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
    void update(ofVec3f extVel);
    void draw();
        //variables
    bool jumping;
    bool standing;
    bool falling;
    int moveX;
    int score;
    ofPoint pos;
    ofVec3f vel;
    int width, height, jumpConstant;
    float gravity;
    float speed;
    ofMesh scarf;
    
private:
    void drawScarf();
};

#endif

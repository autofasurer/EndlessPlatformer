//
//  player.cpp
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 06/09/15.
//
//
#include "player.h"

player::player(){
    falling = true;
    standing = false;
    jumping = false;
    pos.set(ofGetWidth()/2, 0, 0);
    width = 10;
    height = 20;
    gravity = 2;
    speed = 1.2;
    jumpConstant = -25;
    vel.set(0, gravity, 0);
}

void player::update(){
    if (pos.y > ofGetHeight()-height){
        pos.y = ofGetHeight()-height;
        standing = true;
    }
    if (falling){
        vel.y = gravity;
    }

    if (standing){
        vel.y = 0;
    }
    if (jumping){
        if (standing){
            vel.y = -25;
            standing = false;
        }
        if (vel.y <= 0){
            jumping = false;
        }
    }
    vel.y += gravity;
    pos += vel;

}

void player::draw(){
    ofSetColor(200, 50, 0);
    ofRect(pos.x, pos.y, width,height);
}
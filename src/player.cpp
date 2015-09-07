 //
//  player.cpp
//  EndlessPlatformer
//
//  Created by Brecht Debackere on 06/09/15.
//
//
#include "player.h"

player::player(){
    standing = false;
    jumping = false;
    moveX = 0;
    pos.set((ofGetWidth()/4)*3, 0, 0);
    width = 10;
    height = 20;
    gravity = 1.;
    jumpConstant = -16;
    vel.set(0, gravity, 0);
    score = 0;
}

void player::update(ofVec3f extVel){
    if (pos.y > ofGetHeight()-height){
        pos.y = ofGetHeight()-height;
        standing = true;
        score = 0;
    }

        if(standing){ //if we are touching the floor
            if(vel.y > 0){
                vel.y *= -0.1;
            }
            if(jumping){ //and if the up arrow is pressed
                vel.y = jumpConstant; //set the y speed to the jump constant
            }
        } else {
            vel.y += gravity;
        }
        /*if (jumping){
            vel.y = jumpConstant;
            standing = false;
        }
        if (vel.y <= 0){
            jumping = false;
        }*/

    //else {
    //vel.y = gravity * !standing;
    //}
    vel.x = moveX;
    pos += vel + extVel;
}

void player::draw(){
    ofSetColor(200, 50, 0);
    ofRect(pos.x, pos.y, width, height);
}
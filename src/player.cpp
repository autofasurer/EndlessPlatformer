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

    vel.x = moveX + -1;
    pos += vel + extVel;
    //drawScarf();
}

void player::draw(){
    ofSetColor(250, 230, 230);
    ofRect(pos.x, pos.y, width, height);
    drawScarf();
}

void player::drawScarf(){
    ofMesh scarf;
    
    scarf.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    scarf.enableColors();
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f one(pos.x+width, pos.y+5, 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f two(pos.x+width, pos.y+10, 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f three(pos.x, pos.y+5, 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f four(pos.x, pos.y+10, 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f five(pos.x-10, pos.y+(ofRandom(0,5)), 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f six(pos.x-10, pos.y+(ofRandom(0,5))+5, 0.0);
    scarf.addColor(ofFloatColor(1.0, 0.0, 0.0));
    ofVec3f seven(pos.x-20, pos.y+(ofRandom(0,5)), 0.0);
    ofVec3f eight(pos.x-20, pos.y+(ofRandom(0,5))+5, 0.0);

    scarf.addVertex(one);
    scarf.addVertex(two);
    scarf.addVertex(three);
    scarf.addVertex(four);
    scarf.addVertex(five);
    scarf.addVertex(six);
    scarf.addVertex(seven);
    scarf.addVertex(eight);
    
    scarf.draw();
}

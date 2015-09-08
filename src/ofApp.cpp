#include "ofApp.h"

bool shouldRemovePlatform(platform &p){
    if(p.pos.x < (0 - p.platformWidth) )return true;
    else return false;
}
bool shouldRemoveParticle(particle &p){
    if(p.pos.x < 0 || p.pos.y > ofGetHeight()) return true;
    else return false;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofToggleFullscreen();
    ofBackground(175, 200, 215);
    platforms.push_back(ofGetHeight()/2);
    currentPlatform = 0;
    previousPlatform = -1;
   }

//--------------------------------------------------------------
void ofApp::update(){
    
    particles.push_back(particle());
    if (platforms.back().pos.x < ofGetWidth()-platforms.back().platformWidth){
    platforms.push_back(platform(platforms.back().birthPlace));
    }
    
    for(vector<platform>::iterator it = platforms.begin(); it != platforms.end(); it++){
        
        if (player.pos.x + (player.width/2) >= (*it).pos.x && (player.pos.x - (player.width/2)) <= ((*it).pos.x + (*it).platformWidth)){
            if ( abs(((*it).pos.y - (player.pos.y + player.height))) <= 14 ){
                currentPlatform = (*it).birthday;
                if (currentPlatform != previousPlatform){
                        player.score += 1;
                }
                previousPlatform = currentPlatform;
                player.pos.y = (*it).pos.y - player.height;
                player.standing = true;
                player.update((*it).vel);
            }
            else{
                player.standing = false;
            }
        }
        (*it).update();
    }
    ofRemove(platforms, shouldRemovePlatform);
    player.standing = false;
    player.update(ofVec3f(0,0,0));
    
    for(vector<particle>::iterator it = particles.begin(); it != particles.end(); it++){
        (*it).update();
    }
    ofRemove(particles, shouldRemoveParticle);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    player.draw();
    
    for(vector<particle>::iterator it = particles.begin(); it != particles.end(); it++){
        (*it).draw();
    }
    for(vector<platform>::iterator it = platforms.begin(); it != platforms.end(); it++){
        (*it).draw();
    }
    stringstream ss;
    ss << "SCORE: " << ofToString(player.score) << "\n";
    
    ofDrawBitmapString(ss.str().c_str(), 20, 20);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT){
        player.moveX = -3;
        }
    else if (key == OF_KEY_RIGHT){
        player.moveX = 3;
        }
    else if (key == OF_KEY_UP){
        if(!player.jumping){
        player.jumping = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_LEFT){
        player.moveX = 0;
    }
    else if (key == OF_KEY_RIGHT){
        player.moveX = 0;
    }
    else if (key == ' '){
        player.pos.y = 0;
        player.standing = false;
    }
    else if (key == OF_KEY_UP){
        player.jumping = false;
    }
}
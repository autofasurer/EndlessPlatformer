#include "ofApp.h"

bool shouldRemove(platform &p){
    if(p.pos.x < (0 - p.platformWidth) )return true;
    else return false;
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    platforms.push_back(ofGetHeight()/2);
    currentPlatform = previousPlatform = 0;
   }

//--------------------------------------------------------------
void ofApp::update(){
    
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
                (*it).platformColor.set(200, 255, 0);
            }
            else{
                player.standing = false;
                 //(*it).platformColor.set(255, 255, 255);
            }
        }
        (*it).update();
    }
    ofRemove(platforms, shouldRemove);
    player.standing = false;
    player.update(ofVec3f(0,0,0));

}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw();
    
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
    else if (key == ' '){
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
    else if (key == OF_KEY_UP){
        player.pos.y = 0;
        player.standing = false;
    }
    else if (key == ' '){
        player.jumping = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"

bool shouldRemove(platform &p){
    if(p.pos.x < (0 - p.platformWidth) )return true;
    else return false;
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    platforms.push_back(ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    

    if (platforms.back().pos.x < ofGetWidth()-platforms.back().platformWidth){
    platforms.push_back(platform(platforms.back().birthPlace));
    }
    
    for(vector<platform>::iterator it = platforms.begin(); it != platforms.end(); it++){
        (*it).update();
    }
    ofRemove(platforms, shouldRemove);
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw();
    
    for(vector<platform>::iterator it = platforms.begin(); it != platforms.end(); it++){
        (*it).draw();
    }
    cout << platforms.size() << endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT){
        player.vel.x = -2;
    }
    else if (key == OF_KEY_RIGHT){
        player.vel.x = 2;
    }
    else if (key == OF_KEY_UP){
        player.jumping = true;
        player.falling = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_LEFT){
        player.vel.x = 0;
    }
    else if (key == OF_KEY_RIGHT){
        player.vel.x = 0;
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

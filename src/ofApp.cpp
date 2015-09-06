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

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(vector<platform>::iterator it = platforms.begin(); it != platforms.end(); it++){
        (*it).draw();
    }
    cout << platforms.size() << endl;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

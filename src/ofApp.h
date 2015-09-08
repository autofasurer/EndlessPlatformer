#pragma once

#include "ofMain.h"
#include "platform.h"
#include "player.h"
#include "particle.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
    vector <platform> platforms;
    vector <particle> particles;
    player  player;
    int     currentPlatform, previousPlatform;


};
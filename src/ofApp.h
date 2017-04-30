#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSyphon.h"
#include "ofxPostProcessing.h"

#include "CircleClass.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxPanel gui;
    ofParameter<float> volume;
    ofParameter<float> speed;
    ofParameter<bool> play;
    ofParameter<bool> dof;
    ofParameter<bool> god;
    ofParameterGroup guiGroup;
    
    CircleClass circle01;
    CircleClass circle02;
    CircleClass circle03;
    CircleClass circle04;
    
    ofSoundPlayer beat;
    
    ofxSyphonServer mainOutputSyphonServer;
    //ofxSyphonServer individualTextureSyphonServer;
    
    ofxSyphonClient mClient;
    
    ofxPostProcessing post;
    
    ofEasyCam cam;
    ofVec3f v1;
    
};

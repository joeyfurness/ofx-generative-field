#include "ofApp.h"
const int width = 1920;
const int height = 1080;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(width, height);
    ofBackground(0);
    
    //post.init(ofGetWidth(), ofGetHeight());
    
    //post.createPass<DofPass>()->setEnabled(true);
    //->setEnabled(dof); Apparently with a typo you get glitchArt
    //post.createPass<GodRaysPass>()->setEnabled(true);
    //post.createPass<FxaaPass>();
    
    circle01.setup();
    circle02.setup();
    circle03.setup();
    circle04.setup();
    
    guiGroup.setName("controls");
    guiGroup.add(circle01.circleParams);
    guiGroup.add(circle02.circleParams);
    guiGroup.add(circle03.circleParams);
    //guiGroup.add(circle04.circleParams);
    
    gui.setup(guiGroup);
    gui.add(volume.set("volume", 0.3, 0.0, 0.6));
    gui.add(speed.set("speed", 1.0, -3.0, 3.0));
    gui.add(play.set("play", false));
    gui.add(dof.set("dof", false));
    gui.add(god.set("god", false));
    
    beat.load("tng_mov_5.wav");
    beat.setLoop(false);
    //beat.play();
    
    v1.set(0,0,0);
    cam.setTarget(v1);
    
    ofSetWindowTitle("vjShaper");
    
    mainOutputSyphonServer.setName("ofx_Screen_Out");
    //individualTextureSyphonServer.setName("Texture Output");
    
    mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("","vjServer00");
    
    //tex.allocate(200, 100, GL_RGBA);
    
    ofSetFrameRate(30); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    if(play == false) beat.play();
    beat.setVolume(volume);
    beat.setSpeed(speed);
    
    circle01.update();
    circle02.update();
    circle03.update();
    //circle04.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // copy enable part of gl state
    //glPushAttrib(GL_ENABLE_BIT);
    
    // setup gl state
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    
    //post.begin();
    circle01.draw();
    circle02.draw();
    circle03.draw();
    //circle04.draw();
    //post.end();
    
    // set gl state back to original
    //glPopAttrib();
    
    mClient.draw(50, 50);
    
    mainOutputSyphonServer.publishScreen();
    
    //individualTextureSyphonServer.publishTexture(&tex);
    
    gui.draw();
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

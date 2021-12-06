#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	kinect.open();
}

//--------------------------------------------------------------
void ofApp::update() {
	kinect.update();
	if (kinect.isFrameNew()) {
		texture.loadData(kinect.getRgbPixels());
		//substracted.loadData(texture.getTextureMatrix - background.getTextureMatrix);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	texture.draw(0, 0, 960, 540);
	background.draw(960, 0, 960, 540);
	substracted.draw(0, 540, 960, 540);
}

void ofApp::exit() {
	kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 's') { 
		if (!kinect.isFrameNew()) { printf("No new frame available"); return; }
		background.loadData(kinect.getRgbPixels());
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}


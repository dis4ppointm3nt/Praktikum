#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	kinect.open();

	webCam.setVerbose(true);
	webCam.setup(320, 240);

	colorImg.allocate(320, 240);
	grayImg.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	


	bLearnBackground = true;
	thresholdValue = 80;
}

//--------------------------------------------------------------
void ofApp::update() {
	kinect.update();
	webCam.update();

	if (webCam.isFrameNew()) {
		//texture.loadData(kinect.getRgbPixels());
		auto cam = kinect.getPixels();

		cam.setNumChannels(3);
		cam.swapRgb();
		
		colorImg.setFromPixels(webCam.getPixels());
		grayImg.setFromColorImage(colorImg);
		//grayImg= colorImg;


		if (bLearnBackground == true) {
			grayBg = grayImg; // Note: this is 'operator overloading'
			bLearnBackground = false; // Latch: only learn it once.
		}
	grayDiff.absDiff(grayBg, grayImg);

	grayDiff.threshold(thresholdValue);

	contourFinder.findContours(grayDiff, 20, 25000, 10, true);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	/*
	colorImg.draw(0, 0, 960, 540);
	grayImg.draw(960, 540, 960, 540);
	backgroundImg.draw(960, 0, 960, 540);
	subtractedImg.draw(0, 540, 960, 540);
	*/
	//texture.draw(0, 0, 640, 480);
	//ofBackground(100, 100, 100);
	ofSetHexColor(0xffffff);
	colorImg.draw(0, 0, 320, 240);    // The incoming color image
	grayImg.draw(340, 0, 320, 240);  // A gray version of the incoming video
	grayBg.draw(20, 250);     // The stored background image
	grayDiff.draw(340, 250);  // The thresholded difference image


	ofNoFill();
	

	int numBlobs = contourFinder.nBlobs;
	for (int i = 0; i < numBlobs; i++) {
		contourFinder.blobs[i].draw(360, 540);
	}

}

void ofApp::exit() {
	kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	bLearnBackground = true;
	/*
	if (key == 's') { 
		if (!kinect.isFrameNew()) { printf(\n"No new frame available"); return; }
		backgroundImg.loadData(kinect.getRgbPixels());
	}
	*/
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


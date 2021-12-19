#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// Live Video
	//webCam.setVerbose(true);
	//webCam.setup(320, 240);

	//Movie Player
	videoPlayer.load("movies/Liegen2.mov");
	videoPlayer.setLoopState(OF_LOOP_NORMAL);
	videoPlayer.play();
	

	colorImg.allocate(320, 240);
	grayImg.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);
	dilatImg.allocate(320, 240);
	closingImg.allocate(320, 240);


	bLearnBackground = true;
	thresholdValue = 50;
	thresh1 = 70;
	thresh2 = 120;
	height = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

	bool newFrame = false;
	// Kinect Sensor
	//kinect.update();
	//newFrame = kinect.isFrameNew();

	// Webcam
	//webCam.update();
	//newFrame = webCam.isFrameNew();

	// Video
	videoPlayer.update();
	newFrame = videoPlayer.isFrameNew();

	if (newFrame) {
		//texture.loadData(kinect.getRgbPixels());

		colorImg.setFromPixels(videoPlayer.getPixels());
		grayImg.setFromColorImage(colorImg);

		if (bLearnBackground == true) {
			grayBg = grayImg; // Note: this is 'operator overloading'
			bLearnBackground = false; // Latch: only learn it once.
		}
	grayDiff.absDiff(grayBg, grayImg);

	grayDiff.blur();

	grayDiff.threshold(thresholdValue);

	// Manueller Threshhold
	/*greyThresh = grayImg.getPixels();

	int numPixels = grayDiff.getWidth() * grayDiff.getHeight();
	for (int i = 0; i < numPixels; i++) {
		if (greyThresh[i] < thresh1 && greyThresh[i] > thresh2) {
			greyThresh[i] = 255;
		}
		else {
			greyThresh[i] = 0;
		}
	}*/

	//Dilatation mit einer 3x3 Matrix
	dilatImg = grayDiff;
	dilatImg.dilate_3x3();
	//Closing of the Image
	closingImg = dilatImg;
	closingImg.erode_3x3();

	contourFinder.findContours(grayDiff, 20, 25000, 10, true);
	contourFinder2.findContours(closingImg, 20, (320*240)/4, true, true);
	}

	height = contourFinder2.blobs.size();

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
	grayImg.draw(340, 0, 320, 240);  // A gray version of the incoming video*
	grayBg.draw(20, 250);     // The stored background image
	grayDiff.draw(340, 250);  // The thresholded difference image
	dilatImg.draw(0, 500);
	closingImg.draw(680, 0);
	ofNoFill();
	

	int numBlobs = contourFinder.nBlobs;
	for (int i = 0; i < numBlobs; i++) {
		contourFinder.blobs[i].draw(360, 540);
	}

	int numBlobs2 = contourFinder2.nBlobs;
	for (int i = 0; i < numBlobs2; i++) {
		contourFinder2.blobs[i].draw(680, 0);
	}

}

void ofApp::exit() {
	webCam.close();
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


#pragma once

#include "ofMain.h"
#include "ofxKinectV2.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

//	ofxKinectV2 kinect;
//	ofTexture texture;
	/*ofTexture grayImg;
	ofTexture backgroundImg;
	ofTexture subtractedImg;*/

	ofPixels greyThresh;
	ofVideoGrabber webCam;
	ofVideoPlayer videoPlayer;
	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage grayImg;
	ofxCvGrayscaleImage grayImg2;
	ofxCvGrayscaleImage grayBg;
	ofxCvGrayscaleImage grayDiff;
	ofxCvGrayscaleImage dilatImg;
	ofxCvGrayscaleImage closingImg;
	ofxCvContourFinder contourFinder; 
	ofxCvContourFinder contourFinder2;

	int						thresholdValue;
	int						thresh1;
	int						thresh2;
	float						height;
	bool					bLearnBackground;

};

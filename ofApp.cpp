#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 15;
	for (int x = 0; x < ofGetWidth(); x += span) {

		for (int y = 0; y < ofGetHeight(); y += span) {

			auto noise_value = ofNoise(x * 0.01, y * 0.01 + ofGetFrameNum() * 0.035);

			if (y > ofGetHeight() * 0.85) {
			
				noise_value += ofMap(y, ofGetHeight() * 0.85, ofGetHeight(), 0.25, 1);
			}
			else if (y > ofGetHeight() * 0.65) {

				noise_value += ofMap(y, ofGetHeight() * 0.65, ofGetHeight() * 0.85, 0, 0.25);
			}
			else if(y < ofGetHeight() * 0.45){

				noise_value += ofMap(y, 0, ofGetHeight() * 0.45, -0.65, 0);
			}

			if (noise_value > 0.3) {
				
				ofDrawRectangle(glm::vec2(x, y), span - 2, span - 2);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}

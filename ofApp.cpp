#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp() {
	for (int i = this->particles.size() - 1; i > -1; i--) {
		delete this->particles[i];
		this->particles.erase(this->particles.begin() + i);
	}
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableSmoothing();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	for (int i = 0; i < 2048; i++) {
		this->particles.push_back(new Particle());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (Particle* p : this->particles) {
		p->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);

	this->cam.begin();

	for (Particle* p : this->particles) {
		p->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(1920, 1080, OF_WINDOW);
	ofRunApp(new ofApp());
}
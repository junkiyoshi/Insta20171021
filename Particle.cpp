#include "Particle.h"

Particle::Particle()
{
	this->location = ofVec2f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2));
	this->step = ofRandom(2.0, 5.0);
	this->body_size = ofRandom(10, 40);
	this->body_color.setHsb(ofRandom(255), 255, 255);
	this->alpha = ofRandom(200, 255);
}

void Particle::update()
{
	float x = this->location.x + this->step;
	float y = sin(x * this->step * 0.001) * ofGetHeight() * 0.5;
	//float y = sin(x * this->step * 0.0025) * ofGetHeight() * 0.5;
	this->location = ofVec2f(x, y);

	if (this->location.x > ofGetWidth() / 2 + this->body_size) {
		this->location.x = -ofGetWidth() / 2 - this->body_size;
	}

}

void Particle::draw()
{
	ofSetColor(this->body_color, this->alpha);
	ofDrawEllipse(this->location, this->body_size, this->body_size);
}
#pragma once

#include "ofVec3f.h"
#include "ofxOsc.h"

class AppInteractionController
{
private:
	ofxOscReceiver mOscReceiver;
public:
	void setup();
	std::vector<ofVec3f> getPoints();
};

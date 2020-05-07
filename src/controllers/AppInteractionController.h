#pragma once

#include <string>

#include "ofVec3f.h"
#include "ofxOsc.h"

#include "shared/AppSettings.h"

class AppInteractionController
{
private:
	ofxOscReceiver mOscReceiver;
	int mPort;
	bool mHasDepth;
	std::string mMessageGetX;
	std::string mMessageGetY;
	std::string mMessageGetZ;
public:
	AppInteractionController(
		const AppSettings::Communication& setting,
		int sourceIndex);
	void setup();
	std::vector<ofVec3f> getPoints();
};

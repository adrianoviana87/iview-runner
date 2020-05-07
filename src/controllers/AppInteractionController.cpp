#include <vector>

#include "ofAppRunner.h"

#include "controllers/AppInteractionController.h"

using namespace std;

void AppInteractionController::setup()
{
	ofxOscReceiverSettings settings;
	settings.port = 11777;
	mOscReceiver.setup(settings);
}

vector<ofVec3f> AppInteractionController::getPoints()
{
	vector<ofVec3f> points;
	float y = 0;
	float x = 0;
	while (mOscReceiver.hasWaitingMessages())
	{
		ofxOscMessage message;
		mOscReceiver.getNextMessage(message);
		auto address = message.getAddress();

		if (address == "/oscControl/slider2Dx")
		{
			x = message.getArgAsFloat(0);
		}
		else if (address == "/oscControl/slider2Dy")
		{
			y = message.getArgAsFloat(0);
			points.push_back({ x * ofGetWindowWidth(), y * ofGetWindowHeight() });
		}
	}

	return points;
}

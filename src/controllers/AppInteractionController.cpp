#include <vector>

#include "ofAppRunner.h"

#include "controllers/AppInteractionController.h"

using namespace std;

void AppInteractionController::setup()
{
	ofxOscReceiverSettings settings;
	settings.port = mPort;
	mOscReceiver.setup(settings);
}

AppInteractionController::AppInteractionController(
	const AppSettings::Communication& settings,
	int sourceIndex)
	: mPort(settings.activationSources[sourceIndex].port),
	mMessageGetX(
		settings.globalPrefix
		+ settings.activationSources[sourceIndex].prefix
		+ settings.activationSources[sourceIndex].getX),
	mMessageGetY(
		settings.globalPrefix
		+ settings.activationSources[sourceIndex].prefix
		+ settings.activationSources[sourceIndex].getY),
	mMessageGetZ(
		settings.globalPrefix
		+ settings.activationSources[sourceIndex].prefix
		+ settings.activationSources[sourceIndex].getZ),
	mHasDepth(settings.activationSources[sourceIndex].depth)
{
}

vector<ofVec3f> AppInteractionController::getPoints()
{
	vector<ofVec3f> points;
	float y = 0;
	float x = 0;
	float z = 0;
	while (mOscReceiver.hasWaitingMessages())
	{
		ofxOscMessage message;
		mOscReceiver.getNextMessage(message);
		auto address = message.getAddress();

		if (address == mMessageGetX)
		{
			x = message.getArgAsFloat(0);
		}
		else if (address == mMessageGetY)
		{
			y = message.getArgAsFloat(0);
			if (!mHasDepth)
			{
				points.push_back({ x * ofGetWindowWidth(), y * ofGetWindowHeight() });
			}
		}
		else if (address == mMessageGetZ)
		{
			z = message.getArgAsFloat(0);
			points.push_back({ x * ofGetWindowWidth(), y * ofGetWindowHeight(), z });
		}
	}

	return points;
}

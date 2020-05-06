#include "AppPresentation.h"

using namespace std;

void AppPresentation::onActivated(const ofVec3f &point)
{
	for (auto& layer : mLayers)
	{
		layer->onActivated(point);
	}
}

void AppPresentation::draw()
{
	for (auto& layer : mLayers)
	{
		layer->draw();
	}
}

void AppPresentation::update()
{
	for (auto& layer : mLayers)
	{
		layer->update();
	}
}

void AppPresentation::setup()
{
	for (auto& layer : mLayers)
	{
		layer->setup();
	}
}

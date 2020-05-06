#pragma once

#include "ofVec3f.h"

class AppGameComponent
{
public:
	virtual void onActivated(const ofVec3f &point);
	virtual void draw();
	virtual void update();
	virtual void setup();
	virtual ~AppGameComponent();
};

#pragma once

#include "ofVec3f.h"

class AppLayer
{
public:
  virtual void onActivated(const ofVec3f &point);
  virtual void draw();
  virtual void update();
  virtual void setup();
	virtual void mouseMoved(int x, int y);
	virtual void mousePressed(int x, int y, int button);
	virtual void mouseReleased(int x, int y, int button);
  virtual ~AppLayer();
};

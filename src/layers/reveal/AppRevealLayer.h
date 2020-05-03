#pragma once

#include "ofFbo.h"
#include "ofImage.h"
#include "ofShader.h"
#include "../AppLayer.h"

class AppRevealLayer : public AppLayer
{
private:
  ofImage mImage;
  ofImage mBrush;
  ofFbo mMaskFbo;
  ofFbo mFbo;
  ofShader mShader;
  bool mMouseDown;
public:
  void setup() override;
  void draw() override;
  void update() override;
	virtual void mousePressed(int x, int y, int button);
	virtual void mouseReleased(int x, int y, int button);
};

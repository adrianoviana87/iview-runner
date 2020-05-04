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
  bool mPointActive;
  ofVec3f mPoint;
public:
  void setup() override;
  void draw() override;
  void update() override;
  void onActivated(const ofVec3f &point) override;
};

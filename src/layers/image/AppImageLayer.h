#pragma once

#include "ofxThreadedImageLoader.h"
#include "ofImage.h"

#include "../AppLayer.h"

class AppImageLayer : public AppLayer
{
private:
  ofImage mImage;
public:
  void draw() override;
  void setup() override;
};

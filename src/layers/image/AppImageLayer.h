#pragma once

#include "ofxThreadedImageLoader.h"
#include "ofImage.h"

#include "../AppLayer.h"
#include "AppImageLayerDef.h"

class AppImageLayer : public AppLayer
{
private:
  ofImage mImage;
  AppImageLayerDef mDef;
public:
  AppImageLayer(AppImageLayerDef def);
  void draw() override;
  void setup() override;
};

#pragma once

#include "../AppLayer.h"

#include "ofImage.h"

class AppImageLayer : public AppLayer {
  private:
    ofImage mImage;
  public:
    void draw() override;
    void setup() override;
};

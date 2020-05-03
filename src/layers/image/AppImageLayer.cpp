#include "AppImageLayer.h"

#include "ofAppRunner.h"

void AppImageLayer::setup()
{
  mImage.load("./placeholder.png");
}

void AppImageLayer::draw()
{
  mImage.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}
#include "AppImageLayer.h"

#include "ofAppRunner.h"

#include "../../image-loader/AppImageLoader.h"

void AppImageLayer::setup()
{
  AppImageLoader::instance()->loadImage(mImage, "https://source.unsplash.com/random");
}

void AppImageLayer::draw()
{
  mImage.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

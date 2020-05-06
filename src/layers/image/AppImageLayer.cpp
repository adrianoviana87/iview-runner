#include "AppImageLayer.h"

#include "ofAppRunner.h"

#include "../../image-loader/AppImageLoader.h"

AppImageLayer::AppImageLayer(AppImageLayerDef def)
  : mDef(def)
{
}

void AppImageLayer::setup()
{
  AppImageLoader::instance()->loadImage(mImage, mDef.source);
}

void AppImageLayer::draw()
{
  mImage.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

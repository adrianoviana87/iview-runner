#pragma once

#include <string>
#include <memory>

#include "ofxThreadedImageLoader.h"


class AppImageLoader {
private:
  static std::shared_ptr<AppImageLoader> sInstance;
  ofxThreadedImageLoader mLoader;
public:
  void loadImage(ofImage& image, std::string path);
  ~AppImageLoader();

  static std::shared_ptr<AppImageLoader> instance();
};

#include <regex>
#include "AppImageLoader.h"

std::shared_ptr<AppImageLoader> AppImageLoader::sInstance;

bool looksLikeUrl(const std::string& path)
{
	return std::regex_match(path, std::regex("^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$"));
}

std::shared_ptr<AppImageLoader> AppImageLoader::instance()
{
  if (!sInstance)
  {
    sInstance = std::make_shared<AppImageLoader>();
  }

  return sInstance;
}

void AppImageLoader::loadImage(ofImage& image, std::string path)
{
  if (looksLikeUrl(path))
  {
    mLoader.loadFromURL(image, path);
  }
  else
  {
    mLoader.loadFromDisk(image, path);
  }
}

AppImageLoader::~AppImageLoader()
{
  mLoader.stopThread();
}

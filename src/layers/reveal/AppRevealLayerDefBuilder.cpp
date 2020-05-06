#include "AppRevealLayerDefBuilder.h"

AppRevealLayerDef appBuildRevealLayerDef(const Json::Value& jsonEl)
{
  AppRevealLayerDef def;

  def.source = jsonEl["source"].asString();

  return def;
}


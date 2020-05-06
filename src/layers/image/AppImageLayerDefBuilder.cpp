#include "AppImageLayerDefBuilder.h"

AppImageLayerDef appBuildImageLayerDef(const Json::Value& jsonEl)
{
	AppImageLayerDef def;
	def.source = jsonEl["source"].asString();

	return def;
}

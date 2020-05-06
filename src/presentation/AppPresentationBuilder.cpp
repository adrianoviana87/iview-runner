#include "ofxJSON.h"

#include "AppPresentation.h"
#include "../layers/image/AppImageLayer.h"
#include "../layers/image/AppImageLayerDefBuilder.h"
#include "../layers/reveal/AppRevealLayer.h"
#include "../layers/reveal/AppRevealLayerDefBuilder.h"

using namespace std;

unique_ptr<AppLayer> buildImageLayer(const Json::Value& jsonEl)
{
  return make_unique<AppImageLayer>(appBuildImageLayerDef(jsonEl));	
}

unique_ptr<AppLayer> buildRevealLayer(const Json::Value& jsonEl)
{
  return make_unique<AppRevealLayer>(appBuildRevealLayerDef(jsonEl));	
}

unique_ptr<AppLayer> buildLayer(const Json::Value& jsonEl)
{
	auto layerType = jsonEl["type"].asString();
	if (layerType == "image")
	{
		return buildImageLayer(jsonEl);
	}

	if (layerType == "reveal")
	{
		return buildRevealLayer(jsonEl);
	}

	return nullptr;
}

shared_ptr<AppPresentation> appBuildPresentation(const string& file)
{
	ofxJSONElement jsonEl;
	if (!jsonEl.open(file))
	{
		return nullptr;
	}

	if (!jsonEl["layers"].isArray())
	{
		return nullptr;
	}

	auto presentation = make_shared<AppPresentation>();
	auto& layerDefs = jsonEl["layers"];
	for (Json::ArrayIndex i = 0; i < layerDefs.size(); ++i)
	{
		auto layer = buildLayer(layerDefs[i]);
		if (layer)
		{
			presentation->mLayers.push_back(move(layer));
		}
	}

	return presentation;
}


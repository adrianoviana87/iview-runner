#include <string>

#include "ofxJSON.h"

#include "shared/AppSettings.h"

#define APP_SETTINGS_PATH "data\\settings.json"

using namespace std;

void loadCommunication(AppSettings::Communication& communication, const Json::Value& val)
{
	auto activationSourcesEl = val["activationSources"];
	if (activationSourcesEl.isArray())
	{
		for (Json::ArrayIndex i = 0; i < activationSourcesEl.size(); ++i)
		{
			auto& item = activationSourcesEl[i];
			AppSettings::Communication::ActivationSource source;
			source.depth = item["depth"].asBool();
			source.port = item["port"].asInt();
			source.prefix = item["prefix"].asString();
			source.getX = item["getX"].asString();
			source.getY = item["getY"].asString();
			source.getZ = item["getZ"].asString();
			communication.activationSources.push_back(source);
		}
	}

	communication.globalPrefix = val["globalPrefix"].asString();
}

void loadDisplay(AppSettings::Display& display, const Json::Value& val)
{
	display.width = val["width"].asInt();
	display.height = val["height"].asInt();
}

AppSettings appLoadSettings()
{
	const string path = APP_SETTINGS_PATH;
	ofxJSONElement el;
	AppSettings settings;
	if (el.open(path))
	{
		loadCommunication(settings.communication, el["communication"]);
		loadDisplay(settings.display, el["display"]);
	}

	return settings;
}

Json::Value createDisplay(const AppSettings::Display& display)
{
	Json::Value v;
	v["width"] = display.width;
	v["height"] = display.height;

	return v;
}

Json::Value createCommunication(const AppSettings::Communication& communication)
{
	Json::Value v;

	v["globalPrefix"] = communication.globalPrefix;
	auto& activationSources = v["activationSources"];
	for (auto& item : communication.activationSources)
	{
		Json::Value itemEl;
		itemEl["port"] = item.port;
		itemEl["prefix"] = item.prefix;
		itemEl["depth"] = item.depth;
		itemEl["getX"] = item.getX;
		itemEl["getY"] = item.getY;
		itemEl["getZ"] = item.getZ;
		activationSources.append(itemEl);
	}

	return v;
}

void appSaveSettings(const AppSettings& settings)
{
	ofxJSONElement el;
	el["display"] = createDisplay(settings.display);
	el["communication"] = createCommunication(settings.communication);

	el.save(APP_SETTINGS_PATH);
}


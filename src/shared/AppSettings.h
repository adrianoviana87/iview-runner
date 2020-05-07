#pragma once

#include <string>
#include <vector>

struct AppSettings
{
	struct Communication
	{
		struct ActivationSource
		{
			int port;
			std::string prefix;
			bool depth;
			std::string getX;
			std::string getY;
			std::string getZ;
		};

		std::string globalPrefix;
		std::vector<ActivationSource> activationSources;
	};

	struct Display
	{
		int width;
		int height;
	};

	Communication communication;
	Display display;
};


AppSettings appLoadSettings();
void appSaveSettings(const AppSettings& settings);

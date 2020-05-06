#pragma once

#include <memory>
#include <string>
#include <vector>

#include "../shared/AppGameComponent.h"
#include "../layers/AppLayer.h"

class AppPresentation : public AppGameComponent
{
private:
	std::vector<std::unique_ptr<AppLayer>> mLayers;
public:
	void onActivated(const ofVec3f &point) override;
	void draw() override;
	void update() override;
	void setup() override;
	friend std::shared_ptr<AppPresentation> appBuildPresentation(const std::string& file);
};

std::shared_ptr<AppPresentation> appBuildPresentation(const std::string& file);

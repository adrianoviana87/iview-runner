#pragma once

#include <memory>
#include "shared/AppGameComponent.h"
#include "presentation/AppPresentation.h"

class AppPresentationController : public AppGameComponent
{
private:
	std::shared_ptr<AppPresentation> mPresentation;
public:
	void onActivated(const ofVec3f &point) override;
	void draw() override;
	void update() override;
	void post(std::shared_ptr<AppPresentation> presentation);
	void post(const std::string& presentationPath);
};

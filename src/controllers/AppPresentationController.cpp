#include "controllers/AppPresentationController.h"

void AppPresentationController::onActivated(const ofVec3f &point)
{
	if (mPresentation)
	{
		mPresentation->onActivated(point);
	}
}

void AppPresentationController::draw()
{
	if (mPresentation)
	{
		mPresentation->draw();
	}
}

void AppPresentationController::update()
{
	if (mPresentation)
	{
		mPresentation->update();
	}
}

void AppPresentationController::post(std::shared_ptr<AppPresentation> presentation)
{
	mPresentation = presentation;
	mPresentation->setup();
}

void AppPresentationController::post(const std::string& presentationPath)
{
	auto presentation = appBuildPresentation(presentationPath);
	this->post(presentation);
}


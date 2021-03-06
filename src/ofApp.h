#pragma once

#include "ofMain.h"

#include <memory>
#include <vector>

#include "controllers/AppPresentationController.h"
#include "controllers/AppInteractionController.h"

#include "shared/AppSettings.h"

class ofApp : public ofBaseApp
{
private:
	AppPresentationController mPresentationController;
	std::vector<AppInteractionController> mInteractionControllers;
	AppSettings mAppSettings;
public:
	ofApp(const AppSettings& settings);
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};

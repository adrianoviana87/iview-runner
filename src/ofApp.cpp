#include "ofApp.h"

#include "layers/image/AppImageLayer.h"
#include "layers/reveal/AppRevealLayer.h"

using namespace std;

ofApp::ofApp(const AppSettings& settings)
	:mAppSettings(settings)
{

}

//--------------------------------------------------------------
void ofApp::setup()
{
  ofEnableAlphaBlending();
	for (int i = 0; i < mAppSettings.communication.activationSources.size(); ++i)
	{
		mInteractionControllers.emplace_back(mAppSettings.communication, i);
		mInteractionControllers.back().setup();
	}

	mPresentationController.setup();
	mPresentationController.post("sample-data/sample-presentation.json");
}

//--------------------------------------------------------------
void ofApp::update()
{
  if (ofGetMousePressed())
  {
    ofVec3f mousePoint(ofGetMouseX(), ofGetMouseY());
		mPresentationController.onActivated(mousePoint);
  }

	for (auto& interactionController : mInteractionControllers)
	{
		auto points = interactionController.getPoints();
		for (auto& point : points)
		{
			mPresentationController.onActivated(point);
		}
	}

	mPresentationController.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetColor(255, 255);
	mPresentationController.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

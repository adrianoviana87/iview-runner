#include "ofApp.h"

#include "layers/image/AppImageLayer.h"
#include "layers/reveal/AppRevealLayer.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup()
{
  ofEnableAlphaBlending();
	mPresentation = appBuildPresentation("sample-data/sample-presentation.json");
	mPresentation->setup();
}

//--------------------------------------------------------------
void ofApp::update()
{
  if (ofGetMousePressed())
  {
    ofVec3f mousePoint(ofGetMouseX(), ofGetMouseY());
		mPresentation->onActivated(mousePoint);
  }

	mPresentation->update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetColor(255, 255);
	mPresentation->draw();
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

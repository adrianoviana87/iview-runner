#include "ofApp.h"

#include "layers/image/AppImageLayer.h"
#include "layers/reveal/AppRevealLayer.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofEnableAlphaBlending();
  mLayers.push_back(make_shared<AppImageLayer>());
  mLayers.push_back(make_shared<AppRevealLayer>());
  for (auto &layer : mLayers)
  {
    layer->setup();
  }
}

//--------------------------------------------------------------
void ofApp::update()
{
  if (ofGetMousePressed())
  {
    ofVec3f mousePoint(ofGetMouseX(), ofGetMouseY());
    for (auto &layer : mLayers)
    {
      layer->onActivated(mousePoint);
    }
  }

  for (auto &layer : mLayers)
  {
    layer->update();
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofSetColor(255, 255);
  for (auto &layer : mLayers)
  {
    layer->draw();
  }
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

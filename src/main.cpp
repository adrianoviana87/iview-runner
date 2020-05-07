#include "ofMain.h"
#include "ofApp.h"

#include "shared/AppSettings.h"

//========================================================================
int main()
{
	AppSettings settings = appLoadSettings();
	ofSetupOpenGL(settings.display.width, settings.display.height, OF_WINDOW); // <-------- setup the GL context


	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp(settings));
}

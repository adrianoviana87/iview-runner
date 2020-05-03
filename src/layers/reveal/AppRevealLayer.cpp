#include "AppRevealLayer.h"

#include <string>

#include "ofAppRunner.h"
#include "ofGraphics.h"

using namespace std;

void AppRevealLayer::mousePressed(int x, int y, int button)
{
  mMouseDown = true;
}

void AppRevealLayer::mouseReleased(int x, int y, int button)
{
  mMouseDown = false;
}

void AppRevealLayer::setup()
{
  mImage.load("sample.jpg");
  mBrush.load("brush.png");

  int width = ofGetWindowWidth();
  int height = ofGetWindowHeight();

  mMaskFbo.allocate(width, height);
  mFbo.allocate(width, height);

#ifdef TARGET_OPENGLES
  shader.load("shaders_gles/alphamask.vert", "shaders_gles/alphamask.frag");
#else
  if (ofIsGLProgrammableRenderer())
  {
    string vertex = "#version 150\n\
    	\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelViewMatrix;\n\
    	uniform mat4 modelViewProjectionMatrix;\n\
    	\n\
    	\n\
    	in vec4  position;\n\
    	in vec2  texcoord;\n\
    	\n\
    	out vec2 texCoordVarying;\n\
    	\n\
    	void main()\n\
    	{\n\
	        texCoordVarying = texcoord;\
    		gl_Position = modelViewProjectionMatrix * position;\n\
    	}";
    string fragment = "#version 150\n\
		\n\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
		\
        out vec4 fragColor;\n\
		void main (void){\
		vec2 pos = texCoordVarying;\
		\
		vec3 src = texture(tex0, pos).rgb;\
		float mask = texture(maskTex, pos).r;\
		\
		fragColor = vec4( src , mask);\
		}";
    mShader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
    mShader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
    mShader.bindDefaults();
    mShader.linkProgram();
  }
  else
  {
    string shaderProgram = "#version 120\n \
		#extension GL_ARB_texture_rectangle : enable\n \
		\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
		\
		void main (void){\
		vec2 pos = gl_TexCoord[0].st;\
		\
		vec3 src = texture2DRect(tex0, pos).rgb;\
		float mask = texture2DRect(maskTex, pos).r;\
		\
		gl_FragColor = vec4( src , mask);\
		}";
    mShader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
    mShader.linkProgram();
  }
#endif

  // Let's clear the FBO's
  // otherwise it will bring some junk with it from the memory
  mMaskFbo.begin();
  ofClear(0, 0, 0, 255);
  mMaskFbo.end();

  mFbo.begin();
  ofClear(0, 0, 0, 255);
  mFbo.end();
  mMouseDown = false;
}

void AppRevealLayer::update()
{
  // MASK (frame buffer object)
  //
  mMaskFbo.begin();
  if (mMouseDown)
  {
    mBrush.draw(ofGetMouseX()- 25, ofGetMouseY() - 25, 50, 50);
  }

  mMaskFbo.end();

  // HERE the shader-masking happends
  //
  mFbo.begin();
  // Cleaning everthing with alpha mask on 0 in order to make it transparent for default
  ofClear(0, 0, 0, 0);

  mShader.begin();
  mShader.setUniformTexture("maskTex", mMaskFbo.getTexture(), 1);

  mImage.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

  mShader.end();
  mFbo.end();
}

void AppRevealLayer::draw()
{
  mFbo.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

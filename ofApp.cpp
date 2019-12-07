#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);
    img.load("brush.png");

}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // Do something if and only if the frame is new and unique.
        // Copy camera pixels to our pixels.
        pixels = grabber.getPixels();

        img.setFromPixels(pixels);
        
        // Upload pixels to a texture on the graphics card so we can draw it.
        texture.loadData(pixels);
        texture.loadData(img);
        
    }
}

void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(img.getWidth(), 0, 0);
    ofScale(-1, 1, 1);

    for (int x = 0; x < img.getWidth(); x += 10)
    {
        for (int y = 0; y < img.getHeight(); y += 10)
        {
            ofColor imgColor = img.getColor(x, y);

            float brightness = imgColor.getBrightness();

            float radius = ofMap(brightness, 0, 255, 2, 40);
        

            ofSetColor(imgColor);
            img.load("brush.png");
            img.setFromPixels(pixels);
            img.draw(20,420);
            
//            ofDrawCircle(x, y, radius);
        }
    }

    ofPopMatrix();

}

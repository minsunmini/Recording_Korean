#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"
#include "ofxTrueTypeFontUC.h"

class recorder : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    // mini these are functions for you:
    
    void recordForLetter(string letter, float duration);
    
    
    float recorderStopTime;
    
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioIn(float * input, int bufferSize, int nChannels);
    
    ofVideoGrabber      vidGrabber;
    ofxVideoRecorder    vidRecorder;
    ofSoundStream       soundStream;
   
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    string recordChar;
    
    ofFbo recordFbo;
    ofPixels recordPixels;
    
    ofImage instruction;
    
    ofxTrueTypeFontUC koreanSymbol;
    
    
    
};

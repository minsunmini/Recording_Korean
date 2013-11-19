#include "recorder.h"

//--------------------------------------------------------------
void recorder::setup(){
    
    sampleRate = 44100;
    channels = 2;
    

    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_VERBOSE);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(1280, 720);
    vidRecorder.setFfmpegLocation(ofFilePath::getAbsolutePath("ffmpeg")); // use this is you have ffmpeg installed in your data folder

    fileName = "testMovie";
    fileExt = ".mov"; // ffmpeg uses the extension to determine the container type. run 'ffmpeg -formats' to see supported formats

    // override the default codecs if you like
    // run 'ffmpeg -codecs' to find out what your implementation supports (or -formats on some older versions)
    vidRecorder.setVideoCodec("mpeg4"); 
    vidRecorder.setVideoBitrate("800k");
    vidRecorder.setAudioCodec("mp3");
    vidRecorder.setAudioBitrate("192k");

//    soundStream.listDevices();
//    soundStream.setDeviceID(11);
    soundStream.setup(this, 0, channels, sampleRate, 256, 4);

    ofSetWindowShape(vidGrabber.getWidth(), vidGrabber.getHeight()	);
     bRecording = false;
    ofEnableAlphaBlending();
    recorderStopTime = 0;
    recordChar = "";
    
}

void recorder::recordForLetter(string letter, float duration){
    
    if (bRecording) {
        return;  // if we are already recording, don't record!
    }
    
    bRecording = true;
    
    if(bRecording && !vidRecorder.isInitialized()) {
        vidRecorder.setup("output/" + letter + "/" + ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels);
    }
    
    
    recorderStopTime = ofGetElapsedTimef() + duration; // record for 3 seconds!

    
    recordChar = letter;
    
}


void recorder::exit() {
    vidRecorder.close();
}

//--------------------------------------------------------------
void recorder::update(){

    if (bRecording == true && ofGetElapsedTimef() > recorderStopTime){
        bRecording = false;
        vidRecorder.close();
    }
    
    vidGrabber.update();
    if(vidGrabber.isFrameNew() && bRecording){
        vidRecorder.addFrame(vidGrabber.getPixelsRef());
    }
    
}

//--------------------------------------------------------------
void recorder::draw(){

    ofSetColor(255, 255, 255);
    vidGrabber.draw(0,0);
    
}

void recorder::audioIn(float *input, int bufferSize, int nChannels){
    if(bRecording)
        vidRecorder.addAudioSamples(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void recorder::keyPressed(int key){
  
}

//--------------------------------------------------------------
void recorder::keyReleased(int key){

//    if(key=='r'){
//        bRecording = !bRecording;
//        if(bRecording && !vidRecorder.isInitialized()) {
//            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels);
////          vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30); // no audio
////            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, 0,0,0, sampleRate, channels); // no video
////          vidRecorder.setupCustomOutput(vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels, "-vcodec mpeg4 -b 1600k -acodec mp2 -ab 128k -f mpegts udp://localhost:1234"); // for custom ffmpeg output string (streaming, etc)
//        }
//    }
//    if(key=='c'){
//        bRecording = false;
//        vidRecorder.close();
//    }
}

//--------------------------------------------------------------
void recorder::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void recorder::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void recorder::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void recorder::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void recorder::windowResized(int w, int h){

}

//--------------------------------------------------------------
void recorder::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void recorder::dragEvent(ofDragInfo dragInfo){

}

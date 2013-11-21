#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    
    // this code makes folders a-z !
    /*
     for (int i = 0; i < 26; i++){
     string letter = "";
     letter += (char)('a' + i);
     string cmd = "cd " + ofFilePath::getAbsolutePath("output") + "; mkdir " +letter;
     system(cmd.c_str());
     }
     */
    
    player.loadMovie("miniRecorder.mp4");
    
    player.setLoopState(OF_LOOP_NONE);
    
    blackBorder.loadImage("box.png");
    
    movieRecorder.setup();    // This has the ofVideoGrabber in the function
    
    prevMoviePosition = 0;
    
    string keyName = "r,s,e,f,a,q,t,d,w,c,z,x,v,g,k,i,j,u,h,y,n,b,m,l,o,p";
    
    keyOrder = ofSplitString(keyName, ",");
    
    int keyFrameNum = 1029;
    
    for (int i = 0; i < 26; i++) {

        frames[i].frameNum = keyFrameNum;
//        frames[i].key = *(keyOrder[i].c_str());
        frames[i].key = ofToChar(keyOrder[i]);

        keyFrameNum += 95;
    }
    
//    frames[0].frameNum = 1027;
//    frames[0].key = 'r';
//    
//    frames[1].frameNum = 1122;
//    frames[1].key = 's';
//    
//    frames[2].frameNum = 1217;
//    frames[2].key = 'e';
    
}

void testApp::exit() {
    movieRecorder.exit();     // <------------ you want this
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    player.update();

    movieRecorder.update(); // <------------ you want this
    
    blackBorder.update();
    
    float currentPosition = player.getPosition();
    
    for (int i = 0; i < 26; i++) {
        
        int frameNow = currentPosition * player.getTotalNumFrames();
        int framePrev = prevMoviePosition * player.getTotalNumFrames();
        
        if (frames[i].frameNum > framePrev && frames[i].frameNum <= frameNow) {
            keyPressed(frames[i].key);
        }
        
    }
    
    prevMoviePosition = currentPosition;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    movieRecorder.draw();    // <------------ you want this  (replaces grabber);
    
    //----draw black border-----
    ofEnableAlphaBlending();
    ofSetColor(225, 225, 225, 225);
    blackBorder.draw(0,0);
    
    //----draw movie I made-----
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    player.draw(0,0);
    ofDisableBlendMode();
    
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Press spacebar to start the video
    if (key == ' '){
        
        player.setPosition(0);
        player.play();
        
    } else if (key == '\r') {
        player.setPosition(0.24);
        
        // why doesn't this work? Isn't it same as above?
        //player.setPosition(844 / player.getTotalNumFrames());
        
    } else {
        
        // convert the key into a "string"
        string letter = "";   // <------------ you want this
        letter += (char)key; // <------------ you want this
        
        // record this letter for 3 seconds;
        movieRecorder.recordForLetter(letter, 1.5);    // <------------ you want this
        
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    player.setPaused(true);
    float percent = x / (float)ofGetWidth();
    player.setPosition(percent);
    cout << "frame number " << (int)(percent * player.getTotalNumFrames()) << endl;
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}

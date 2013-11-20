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
    
    
    
    movieRecorder.setup();    // <------------ you want this
    
    userInterface.setup();
    

}

void testApp::exit() {
    movieRecorder.exit();     // <------------ you want this

}

//--------------------------------------------------------------
void testApp::update(){
    
    movieRecorder.update();     // <------------ you want this

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    movieRecorder.draw();    // <------------ you want this  (replaces grabber);

    
    userInterface.draw(movieRecorder.bRecording, movieRecorder.recordChar);

}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // (you need to handle space presses differently
//    if (key == ' '){
//        
//        
//    } else {
//        
//        
//    }
    
    // convert the key into a "string"
    string letter = "";   // <------------ you want this
    letter += (char)key; // <------------ you want this
    // record this letter for 3 seconds;
    movieRecorder.recordForLetter(letter, 3.0);    // <------------ you want this

    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

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

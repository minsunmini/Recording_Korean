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
    
    movieRecorder.setup();
}

void testApp::exit() {
    movieRecorder.exit();
}

//--------------------------------------------------------------
void testApp::update(){
    movieRecorder.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    movieRecorder.draw();
    

}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // convert the key into a "string"
    string letter = "";
    letter += (char)key;
    
    // record this letter for 3 seconds!
        movieRecorder.recordForLetter(letter, 3.0);
    
    
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

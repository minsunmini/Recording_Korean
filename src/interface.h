//
//  interface.h
//  miniRecorder
//
//  Created by Minsun Kim on 11/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class interface : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw(bool bRecording, string recordChar);
    
        ofImage blackBox;
        ofImage instruction;
        ofImage recordBn;
        ofImage startRecordBn;
        ofImage listenBn;
        ofImage stopListenBn;
    
        vector < string > koreanCharacters;
    
        ofxTrueTypeFontUC koreanFont;

};

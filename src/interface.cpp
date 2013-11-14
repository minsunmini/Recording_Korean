//
//  interface.cpp
//  miniRecorder
//
//  Created by Minsun Kim on 11/13/13.
//
//

#include "interface.h"

void interface::setup(){
    koreanFont.loadFont("hline.ttf", 64, true, true);
    
    string koreanLetters = "ㅁ,ㅠ,ㅊ,ㅇ,ㄷ,ㄹ,ㅎ,ㅗ,ㅑ,ㅓ,ㅏ,ㅣ,ㅡ,ㅜ,ㅐ,ㅔㅂ,ㄱ,ㄴ,ㅅ,ㅕ,ㅍ,ㅈ,ㅌ,ㅛ,ㅋ";
    
    koreanCharacters = ofSplitString(koreanLetters, ",");
    
    //
    //    koreanCharacters.push_back("ㅁ");
    //    koreanCharacters.push_back("ㅠ");
    //    koreanCharacters.push_back("ㅊ");
    //    
    //
    
    instruction.loadImage("instruction_screen.png");

}

void interface::update(){
}

void interface::draw(bool bRecording, string recordChar){
    
    //?
    if(bRecording){
        
        ofSetColor(0,0,0,100);
        ofRect(120, 40, 400, 400);
        ofSetColor(255, 255, 255);
        
        int charValue = (int)recordChar[0];
        charValue -= 97;
        
        
        if (charValue < 0){
            charValue = 0;
        }
        charValue = charValue % koreanCharacters.size();
        
        string koreanString = koreanCharacters[  charValue  ];
        
        koreanFont.drawStringAsShapes(koreanString, 300, 260);
        
        //stringstream ss;
        //ss << recordChar << endl;
        
        //ofSetColor(0,0,0,100);
        //ofRect(120, 40, 400, 400);
        //ofSetColor(255, 255, 255);
        //ofDrawBitmapString(ss.str(),320,240);
        
        //Make red circle when recording
        //ofSetColor(255, 0, 0);
        //ofCircle(ofGetWidth() - 20, 20, 5);
    } else {
        
        instruction.draw(120,40);
        
    }
    
}
#include "pianoviewmodel.h"



void PianoViewModel::setPianoKey(PianoKey* keyPtr, int keyIndex) {
    switch (keyIndex) {
    case 1:
        key1 = keyPtr;
        break;
    case 2:
        key2 = keyPtr;
        break;
    case 3:
        key3 = keyPtr;
        break;
    case 4:
        key4 = keyPtr;
        break;
    case 5:
        key5 = keyPtr;
        break;
    case 6:
        key6 = keyPtr;
        break;
    case 7:
        key7 = keyPtr;
        break;
    case 8:
        key8 = keyPtr;
        break;
    case 9:
        key9 = keyPtr;
        break;
    case 10:
        key10 = keyPtr;
        break;
    case 11:
        key11 = keyPtr;
        break;
    case 12:
        key12 = keyPtr;
        break;
    case 13:
        key13 = keyPtr;
        break;
    default:
        break;
    }
}


PianoKey* PianoViewModel::getPianoKeyPtr(int keyIndex) {

    PianoKey* pianoKey = nullptr;

    switch (keyIndex) {
    case 1:
        pianoKey = key1;
        break;
    case 2:
        pianoKey = key2;
        break;
    case 3:
        pianoKey = key3;
        break;
    case 4:
        pianoKey = key4;
        break;
    case 5:
        pianoKey = key5;
        break;
    case 6:
        pianoKey = key6;
        break;
    case 7:
        pianoKey = key7;
        break;
    case 8:
        pianoKey = key8;
        break;
    case 9:
        pianoKey = key9;
        break;
    case 10:
        pianoKey = key10;
        break;
    case 11:
        pianoKey = key11;
        break;
    case 12:
        pianoKey = key12;
        break;
    case 13:
        pianoKey = key13;
        break;
    default:
        break;
    }
    return pianoKey;
}

void PianoViewModel::pressKey(int index) {
    switch (index) {
    case 1:
        key1->changeColorToPressed();
        break;
    case 2:
        key2->changeColorToPressed();
        break;
    case 3:
        key3->changeColorToPressed();
        break;
    case 4:
        key4->changeColorToPressed();
        break;
    case 5:
        key5->changeColorToPressed();
        break;
    case 6:
        key6->changeColorToPressed();
        break;
    case 7:
        key7->changeColorToPressed();
        break;
    case 8:
        key8->changeColorToPressed();
        break;
    case 9:
        key9->changeColorToPressed();
        break;
    case 10:
        key10->changeColorToPressed();
        break;
    case 11:
        key11->changeColorToPressed();
        break;
    case 12:
        key12->changeColorToPressed();
        break;
    case 13:
        key13->changeColorToPressed();
        break;
    }
}


void PianoViewModel::releaseKey(int index) {
    switch (index) {
    case 1:
        key1->changeColorToReleased();
        break;
    case 2:
        key2->changeColorToReleased();
        break;
    case 3:
        key3->changeColorToReleased();
        break;
    case 4:
        key4->changeColorToReleased();
        break;
    case 5:
        key5->changeColorToReleased();
        break;
    case 6:
        key6->changeColorToReleased();
        break;
    case 7:
        key7->changeColorToReleased();
        break;
    case 8:
        key8->changeColorToReleased();
        break;
    case 9:
        key9->changeColorToReleased();
        break;
    case 10:
        key10->changeColorToReleased();
        break;
    case 11:
        key11->changeColorToReleased();
        break;
    case 12:
        key12->changeColorToReleased();
        break;
    case 13:
        key13->changeColorToReleased();
        break;
    }
}


void PianoViewModel::setLowerOctaveToKeys() {

    key1->getViewModelPtr()->changeNoteLabelToLower();
    key2->getViewModelPtr()->changeNoteLabelToLower();
    key3->getViewModelPtr()->changeNoteLabelToLower();
    key4->getViewModelPtr()->changeNoteLabelToLower();
    key5->getViewModelPtr()->changeNoteLabelToLower();
    key6->getViewModelPtr()->changeNoteLabelToLower();
    key7->getViewModelPtr()->changeNoteLabelToLower();
    key8->getViewModelPtr()->changeNoteLabelToLower();
    key9->getViewModelPtr()->changeNoteLabelToLower();
    key10->getViewModelPtr()->changeNoteLabelToLower();
    key11->getViewModelPtr()->changeNoteLabelToLower();
    key12->getViewModelPtr()->changeNoteLabelToLower();
    key13->getViewModelPtr()->changeNoteLabelToLower();
}


void PianoViewModel::setHigherOctaveToKeys() {

    key1->getViewModelPtr()->changeNoteLabelToHigher();
    key2->getViewModelPtr()->changeNoteLabelToHigher();
    key3->getViewModelPtr()->changeNoteLabelToHigher();
    key4->getViewModelPtr()->changeNoteLabelToHigher();
    key5->getViewModelPtr()->changeNoteLabelToHigher();
    key6->getViewModelPtr()->changeNoteLabelToHigher();
    key7->getViewModelPtr()->changeNoteLabelToHigher();
    key8->getViewModelPtr()->changeNoteLabelToHigher();
    key9->getViewModelPtr()->changeNoteLabelToHigher();
    key10->getViewModelPtr()->changeNoteLabelToHigher();
    key11->getViewModelPtr()->changeNoteLabelToHigher();
    key12->getViewModelPtr()->changeNoteLabelToHigher();
    key13->getViewModelPtr()->changeNoteLabelToHigher();
}
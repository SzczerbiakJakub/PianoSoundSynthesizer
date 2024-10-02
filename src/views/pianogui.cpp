#include "pianogui.h"



Piano::Piano(QWidget* parent) : QLabel(parent) {

    layout = new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    viewModel = new PianoViewModel();

    buildPiano();
}


void Piano::buildPiano() {
    setFixedSize(1200, 450);

    PianoKey* key1 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::C4);
    PianoKey* key2 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::D4);
    PianoKey* key3 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::E4);
    PianoKey* key4 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::F4);
    PianoKey* key5 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::G4);
    PianoKey* key6 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::A4);
    PianoKey* key7 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::B4);
    PianoKey* key8 = new PianoKey(this, PianoKeyColor::White, PianoKeyNotes::PianoKeyNote::C5);
    PianoKey* key9 = new PianoKey(this, PianoKeyColor::Black, PianoKeyNotes::PianoKeyNote::C4SHARP);
    PianoKey* key10 = new PianoKey(this, PianoKeyColor::Black, PianoKeyNotes::PianoKeyNote::D4SHARP);
    PianoKey* key11 = new PianoKey(this, PianoKeyColor::Black, PianoKeyNotes::PianoKeyNote::F4SHARP);
    PianoKey* key12 = new PianoKey(this, PianoKeyColor::Black, PianoKeyNotes::PianoKeyNote::G4SHARP);
    PianoKey* key13 = new PianoKey(this, PianoKeyColor::Black, PianoKeyNotes::PianoKeyNote::A4SHARP);

    layout->addWidget(key1);
    layout->addWidget(key2);
    layout->addWidget(key3);
    layout->addWidget(key4);
    layout->addWidget(key5);
    layout->addWidget(key6);
    layout->addWidget(key7);
    layout->addWidget(key8);

    key9->move(100, 0);
    key10->move(250, 0);
    key11->move(550, 0);
    key12->move(700, 0);
    key13->move(850, 0);

    viewModel->setPianoKey(key1, 1);
    viewModel->setPianoKey(key2, 2);
    viewModel->setPianoKey(key3, 3);
    viewModel->setPianoKey(key4, 4);
    viewModel->setPianoKey(key5, 5);
    viewModel->setPianoKey(key6, 6);
    viewModel->setPianoKey(key7, 7);
    viewModel->setPianoKey(key8, 8);
    viewModel->setPianoKey(key9, 9);
    viewModel->setPianoKey(key10, 10);
    viewModel->setPianoKey(key11, 11);
    viewModel->setPianoKey(key12, 12);
    viewModel->setPianoKey(key13, 13);
}


void Piano::setLowerOctaveLabels() {
    viewModel->getPianoKeyPtr(1)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(2)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(3)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(4)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(5)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(6)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(7)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(8)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(9)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(10)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(11)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(12)->changeNoteLabelToLower();
    viewModel->getPianoKeyPtr(13)->changeNoteLabelToLower();
}


void Piano::setHigherOctaveLabels() {
    viewModel->getPianoKeyPtr(1)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(2)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(3)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(4)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(5)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(6)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(7)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(8)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(9)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(10)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(11)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(12)->changeNoteLabelToHigher();
    viewModel->getPianoKeyPtr(13)->changeNoteLabelToHigher();
}
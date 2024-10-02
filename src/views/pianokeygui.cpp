#include "pianokeygui.h"



PianoKey::PianoKey(QWidget* parent, PianoKeyColor color, PianoKeyNotes::PianoKeyNote note)
    : QLabel(parent) {
    viewModel = new PianoKeyViewModel(color, note);
    buildPianoKey(color, note);
}


void PianoKey::buildPianoKey(PianoKeyColor color, PianoKeyNotes::PianoKeyNote note) {
    noteLabel = new QLabel(this);
    noteLabel->setText(QString::fromStdString(PianoKeyNotes::getNoteInString(note)));
    noteLabel->setFont(QFont("Arial", 20, QFont::Bold));
    noteLabel->setAlignment(Qt::AlignCenter);

    viewModel->setPianoKeyNoteLabel(noteLabel);

    switch (color)
    {
        case PianoKeyColor::White:
            setFixedSize(150, 450);
            setStyleSheet("border: 5px solid black; background-color: white;");
            noteLabel->setFixedSize(140, 50);
            noteLabel->move(5, 380);
            noteLabel->setStyleSheet("border: none; color: black;");
            break;

        case PianoKeyColor::Black:
            setFixedSize(100, 310);
            setStyleSheet("border: 5px solid black; background-color: black;");
            noteLabel->setFixedSize(90, 50);
            noteLabel->move(5, 240);
            noteLabel->setStyleSheet("border: none; color: white;");
            break;
    }
}


void PianoKey::changeColorToPressed() {

    switch (viewModel->getKeyDefaultColor())
    {
        case PianoKeyColor::White:
            setStyleSheet("border: 5px solid grey; background-color: lightgrey;");
            break;

        case PianoKeyColor::Black:
            setStyleSheet("border: 5px solid grey; background-color: darkgrey;");
            break;

    }
}


void PianoKey::changeColorToReleased() {

    switch (viewModel->getKeyDefaultColor())
    {
        case PianoKeyColor::White:
            setStyleSheet("border: 5px solid black; background-color: white;");
            break;

        case PianoKeyColor::Black:
            setStyleSheet("border: 5px solid black; background-color: black;");
            break;
    }
}


void PianoKey::changeNoteLabelToLower() {

    char octaveNotation = keyNote[keyNote.size() - 1];
    octaveNotation = (octaveNotation - 1);
    keyNote.pop_back();
    keyNote.push_back(octaveNotation);
    noteLabel->setText(QString::fromStdString(keyNote));
}


void PianoKey::changeNoteLabelToHigher() {

    char octaveNotation = keyNote[keyNote.size() - 1];
    octaveNotation = (octaveNotation + 1);
    keyNote.pop_back();
    keyNote.push_back(octaveNotation);
    noteLabel->setText(QString::fromStdString(keyNote));
}
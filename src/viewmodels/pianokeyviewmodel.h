#pragma once

#include <QLabel>
#include <QMap>



enum PianoKeyColor {
    White,
    Black
};


class PianoKeyNotes
{
public:
    static enum PianoKeyNote {

        //  THIRD OCTAVE
        C3,
        C3SHARP,
        D3,
        D3SHARP,
        E3,
        F3,
        F3SHARP,
        G3,
        G3SHARP,
        A3,
        A3SHARP,
        B3,

        //  FOURTH OCTAVE
        C4,
        C4SHARP,
        D4,
        D4SHARP,
        E4,
        F4,
        F4SHARP,
        G4,
        G4SHARP,
        A4,
        A4SHARP,
        B4,

        //  FIFTH OCTAVE
        C5,
        C5SHARP,
        D5,
        D5SHARP,
        E5,
        F5,
        F5SHARP,
        G5,
        G5SHARP,
        A5,
        A5SHARP,
        B5,
        C6
    };

    static std::string getNoteInString(PianoKeyNotes::PianoKeyNote note);
    
    static std::pair<PianoKeyNotes::PianoKeyNote, std::string> getLowerOctaveNote(
        PianoKeyNotes::PianoKeyNote note
    );
    
    static std::pair<PianoKeyNotes::PianoKeyNote, std::string> getHigherOctaveNote(
        PianoKeyNotes::PianoKeyNote note
    );

private:
    static const QMap<PianoKeyNotes::PianoKeyNote, std::string> noteDict;

};


class PianoKeyViewModel
{
public:
    PianoKeyViewModel(PianoKeyColor color, PianoKeyNotes::PianoKeyNote note);
    ~PianoKeyViewModel();
    PianoKeyColor getKeyDefaultColor() { return keyDefaultColor; }
    PianoKeyNotes::PianoKeyNote getKeyNote() { return keyNote; }

    void setPianoKeyNoteLabel(QLabel* noteLabelPtr) { noteLabel = noteLabelPtr; }

    void changeNoteLabelToLower();
    void changeNoteLabelToHigher();

private:

    /// <summary>
    /// Parametr typu string przechowujący wartość domyślnego koloru przypisanego klawiszowi.
    /// </summary>
    PianoKeyColor keyDefaultColor;

    /// <summary>
    /// Parametr typu string przechowujący symbol dźwięku przypisanego klawiszowi.
    /// </summary>
    PianoKeyNotes::PianoKeyNote keyNote;

    /// <summary>
    /// Widget znajdujący się na klawiszu, który przedstawia symbol przypisanego do klawisza dźwięku.
    /// </summary>
    QLabel* noteLabel;
};
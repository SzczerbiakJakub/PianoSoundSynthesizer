#include "pianokeyviewmodel.h"


const QMap<PianoKeyNotes::PianoKeyNote, std::string> PianoKeyNotes::noteDict{
	{PianoKeyNote::C3 , "C3"},
	{PianoKeyNote::C3SHARP , "C#3"},
	{PianoKeyNote::D3 , "D3"},
	{PianoKeyNote::D3SHARP , "D#3"},
	{PianoKeyNote::E3 , "E3"},
	{PianoKeyNote::F3 , "F3"},
	{PianoKeyNote::F3SHARP , "F#3"},
	{PianoKeyNote::G3 , "G3"},
	{PianoKeyNote::G3SHARP , "G#3"},
	{PianoKeyNote::A3 , "A3"},
	{PianoKeyNote::A3SHARP , "A#3"},
	{PianoKeyNote::B3 , "B3"},
	{PianoKeyNote::C4 , "C4"},
	{PianoKeyNote::C4SHARP , "C#4"},
	{PianoKeyNote::D4 , "D4"},
	{PianoKeyNote::D4SHARP , "D#4"},
	{PianoKeyNote::E4 , "E4"},
	{PianoKeyNote::F4 , "F4"},
	{PianoKeyNote::F4SHARP , "F#4"},
	{PianoKeyNote::G4 , "G4"},
	{PianoKeyNote::G4SHARP , "G#4"},
	{PianoKeyNote::A4 , "A4"},
	{PianoKeyNote::A4SHARP , "A#4"},
	{PianoKeyNote::B4 , "B4"},
	{PianoKeyNote::C5 , "C5"},
	{PianoKeyNote::C5SHARP , "C#5"},
	{PianoKeyNote::D5 , "D5"},
	{PianoKeyNote::D5SHARP , "D#5"},
	{PianoKeyNote::E5 , "E5"},
	{PianoKeyNote::F5 , "F5"},
	{PianoKeyNote::F5SHARP , "F#5"},
	{PianoKeyNote::G5 , "G5"},
	{PianoKeyNote::G5SHARP , "G#5"},
	{PianoKeyNote::A5 , "A5"},
	{PianoKeyNote::A5SHARP , "A#5"},
	{PianoKeyNote::B5 , "B5"},
	{PianoKeyNote::C6 , "C6"}
};


std::string PianoKeyNotes::getNoteInString(PianoKeyNotes::PianoKeyNote note) {
	return noteDict.value(note, "");
}

std::pair<PianoKeyNotes::PianoKeyNote, std::string> PianoKeyNotes::getLowerOctaveNote(
	PianoKeyNotes::PianoKeyNote note
)
{
	int index = 0;
	auto it = PianoKeyNotes::noteDict.begin();

	for (it; it != PianoKeyNotes::noteDict.end(); it++) {
		if (it.key() == note)
			break;
		index++;
	}

	for (int i = 0; i < 12; i++)
		it--;

	std::pair<PianoKeyNotes::PianoKeyNote, std::string> pair(it.key(), it.value());
	return pair;
}


std::pair<PianoKeyNotes::PianoKeyNote, std::string> PianoKeyNotes::getHigherOctaveNote(
	PianoKeyNotes::PianoKeyNote note
)
{
	int index = 0;
	auto it = PianoKeyNotes::noteDict.begin();

	for (it; it != PianoKeyNotes::noteDict.end(); it++) {
		if (it.key() == note)
			break;
		index++;
	}

	for (int i = 0; i < 12; i++)
		it++;

	std::pair<PianoKeyNotes::PianoKeyNote, std::string> pair(it.key(), it.value());
	return pair;
}

PianoKeyViewModel::PianoKeyViewModel(PianoKeyColor color, PianoKeyNotes::PianoKeyNote note) :
	keyDefaultColor(color), keyNote(note) {
};


PianoKeyViewModel::~PianoKeyViewModel() {
	delete noteLabel;
};


void PianoKeyViewModel::changeNoteLabelToLower() {
	std::pair<PianoKeyNotes::PianoKeyNote, std::string> pair = PianoKeyNotes::getLowerOctaveNote(keyNote);
	keyNote = pair.first;
	noteLabel->setText(QString::fromStdString(pair.second));
}


void PianoKeyViewModel::changeNoteLabelToHigher() {
	std::pair<PianoKeyNotes::PianoKeyNote, std::string> pair = PianoKeyNotes::getHigherOctaveNote(keyNote);
	keyNote = pair.first;
	noteLabel->setText(QString::fromStdString(pair.second));
}
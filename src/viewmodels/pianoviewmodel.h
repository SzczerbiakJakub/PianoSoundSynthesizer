#pragma once
#include "pianokeygui.h"

class PianoViewModel
{
public:
	PianoViewModel() {};
	~PianoViewModel() {};
    void setPianoKey(PianoKey* keyPtr, int keyIndex);
    PianoKey* getPianoKeyPtr(int keyIndex);


    /// <summary>
    /// Metoda odpowiedzialna za zmianę wyglądu klawisza określonego indeksem na wciśnięty.
    /// </summary>
    /// <param name="index"> Indeks klawisza do zmiany wyglądu.</param>
    void pressKey(int index);

    /// <summary>
    /// Metoda odpowiedzialna za zmianę wyglądu klawisza określonego indeksem na niewciśnięty.
    /// </summary>
    /// <param name="index"> Indeks klawisza do zmiany wyglądu.</param>
    void releaseKey(int index);

    void setLowerOctaveToKeys();
    void setHigherOctaveToKeys();

private:
    void buildPiano();

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 1.
    /// </summary>
    PianoKey* key1;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 2.
    /// </summary>
    PianoKey* key2;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 3.
    /// </summary>
    PianoKey* key3;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 4.
    /// </summary>
    PianoKey* key4;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 5.
    /// </summary>
    PianoKey* key5;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 6.
    /// </summary>
    PianoKey* key6;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 7.
    /// </summary>
    PianoKey* key7;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 8.
    /// </summary>
    PianoKey* key8;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 9.
    /// </summary>
    PianoKey* key9;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 10.
    /// </summary>
    PianoKey* key10;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 11.
    /// </summary>
    PianoKey* key11;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 12.
    /// </summary>
    PianoKey* key12;

    /// <summary>
    /// Wskaźnik do widgetu PianoKey określającego przycisk klawiatury o indeksie 13.
    /// </summary>
    PianoKey* key13;
};


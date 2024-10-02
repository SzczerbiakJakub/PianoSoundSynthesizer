#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "pianokeyviewmodel.h"



/// <summary>
/// Widget odpowiedzialny za pojedynczy klawisz wyświetlany na klawiaturze widocznej w czasie działania
/// programu.
/// </summary>
class PianoKey : public QLabel
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy PianoKey
    /// </summary>
    /// <param name="parent"> Wskaźnik do nadrzędnego widgetu, do którego będzie przypisany klawisz.</param>
    /// <param name="color"> Kolor wpływający na wygląd klawisza, możliwe wybory: "white", "black".</param>
    /// <param name="note"> Notacja dźwiękowa reprezentowana przez stworzony klawisz.</param>
    PianoKey(QWidget* parent, PianoKeyColor color, PianoKeyNotes::PianoKeyNote note);


    /// <summary>
    /// Destruktor obiektu klasy PianoKey
    /// </summary>
    ~PianoKey() {};

    /// <summary>
    /// Metoda odpowiedzialna za zmianę wyglądu danego klawisza po naciśnięciu odpowiadającego mu przycisku 
    /// na klawiaturze. Wyświetla na ekranie klawisz jako wciśnięty poprzez zmianę jego koloru na szary.
    /// </summary>
    void changeColorToPressed();

    /// <summary>
    /// Metoda odpowiedzialna za zmianę wyglądu danego klawisza po naciśnięciu odpowiadającego mu przycisku 
    /// na klawiaturze. Wyświetla na ekranie klawisz jako niewciśnięty poprzez zmianę jego koloru na domyślny.
    /// </summary>
    void changeColorToReleased();

    /// <summary>
    /// Metoda aktualizuje tekst na środku klawisza przedstawiający symbol reprezentowanego dźwieku. Zmienia 
    /// wartość reprezentowanej noty dźwiękowej o jedną oktawę w dół.
    /// </summary>
    void changeNoteLabelToLower();


    /// <summary>
    /// Metoda aktualizuje tekst na środku klawisza przedstawiający symbol reprezentowanego dźwieku. Zmienia 
    /// wartość reprezentowanej noty dźwiękowej o jedną oktawę w górę.
    /// </summary>
    void changeNoteLabelToHigher();


    inline PianoKeyViewModel* getViewModelPtr() { return viewModel; }

private:

    PianoKeyViewModel* viewModel;

    /// <summary>
    /// Parametr typu string przechowujący wartość domyślnego koloru przypisanego klawiszowi.
    /// </summary>
    std::string keyDefaultColor;

    /// <summary>
    /// Parametr typu string przechowujący symbol dźwięku przypisanego klawiszowi.
    /// </summary>
    std::string keyNote;

    /// <summary>
    /// Widget znajdujący się na klawiszu, który przedstawia symbol przypisanego do klawisza dźwięku.
    /// </summary>
    QLabel* noteLabel;


    void buildPianoKey(PianoKeyColor color, PianoKeyNotes::PianoKeyNote note);
};
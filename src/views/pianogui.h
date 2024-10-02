#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "pianoviewmodel.h"
#include "pianokeygui.h"




/// <summary>
/// Widget odpowiedzialny za klawiaturę wyświetlaną na ekranie.
/// </summary>
class Piano : public QLabel
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy Piano.
    /// </summary>
    /// <param name="parent"> Wskaźnik do nadrzędnego widgetu, do którego będzie przypisana klawiatura.</param>
    Piano(QWidget* parent);

    /// <summary>
    /// Destruktor obiektu klasy Piano.
    /// </summary>
    ~Piano() {};

    
    /// <summary>
    /// Metoda odpowiedzialna za reprezentację obecnie wybranej oktawy. Aktualizuje tekst reprezentujący 
    /// poszczególne noty pomniejszonę o jedną oktawę. Działa dla wszystkich klawiszy.
    /// </summary>
    void setLowerOctaveLabels();

    /// <summary>
    /// Metoda odpowiedzialna za reprezentację obecnie wybranej oktawy. Aktualizuje tekst reprezentujący 
    /// poszczególne noty powiększone o jedną oktawę. Działa dla wszystkich klawiszy.
    /// </summary>
    void setHigherOctaveLabels();

    inline QHBoxLayout* getLayout() { return layout; }
    inline PianoViewModel* getViewModelPtr() { return viewModel; }

private:
    /// <summary>
    /// Layout obiektu klasu Piano.
    /// </summary>
    QHBoxLayout* layout;

    /// <summary>
    /// A vievmodel of Piano widget.
    /// </summary>
    PianoViewModel* viewModel;

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
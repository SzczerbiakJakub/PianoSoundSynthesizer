#pragma once
#include <QLabel>
#include <QTimer>
#include <QObject>
#include "visualiseritemgui.h"
#include "visualiserviewmodel.h"



/// <summary>
/// Widget odpowiadający za wizualizację dzwięków granych z pomocą wirutalnego syntezatora.
/// </summary>
class Visualiser : public QLabel
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy Visualiser.
    /// </summary>
    /// <param name="parent"> Wskaźnik do nadrzędnego widgetu, do którego będzie przypisany będzie wizualiser.</param>
    Visualiser(QWidget* parent);

    /// <summary>
    /// Destruktor obiektu klasy Visualiser.
    /// </summary>
    ~Visualiser();


    /// <summary>
    /// Metoda dodająca do wizualizera kolejny obiekt klasy VisualizerItem na podstawie parametrów zagranego dźwięku.
    /// </summary>
    /// <param name="sound"> Wskaźnik do obiektu reprezentującego zagrany dźwięk.</param>
    void addNextSoundVisualization(Sound* sound);
    void plotNextSoundVisualization(int height);

    VisualiserViewModel* getViewModelPtr() { return viewModel; };


public slots:
    //void addNextSoundVisualization(Sound* sound);

    void handleNewItem(int value) {
        plotNextSoundVisualization(value);
    }

private:
    VisualiserViewModel* viewModel;

};
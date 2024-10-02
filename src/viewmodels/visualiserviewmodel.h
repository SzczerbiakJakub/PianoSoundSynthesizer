#pragma once
#include <QObject>
#include <QTimer>
#include "sound.h"
#include "visualiseritemgui.h"



class VisualiserViewModel : public QObject
{
    Q_OBJECT

public:
	VisualiserViewModel();
	~VisualiserViewModel();
    int getNextSoundVisualizationHeight(Sound* sound);
    inline std::vector<VisualiserItem*>* getVisualiserItemsPtr() { return items; };
    QTimer* newItemTimer;
    void setCurrentSound(Sound* soundPtr) { currentSound = soundPtr; };

signals:
    void newItemHeightSignal(int height);


private:
    Sound* currentSound;
    /// <summary>
    /// Wskaźnik do wektora zawierającego kolejne obiekty klasy VisualizerItem rozmieszczone na wizualizerze 
    /// (od lewej do prawej z poziomu ekranu).
    /// </summary>
    std::vector<VisualiserItem*>* items;


private slots:
    void sendNewItemHeightSignal() {
        int soundHeight = getNextSoundVisualizationHeight(currentSound);
        emit newItemHeightSignal(soundHeight);
    }


};


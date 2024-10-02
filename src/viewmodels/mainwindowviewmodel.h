#pragma once

#include <QPushButton>
#include "visualisergui.h"
#include "pianogui.h"
#include "sound.h"
#include "threads.h"
#include <QKeyEvent>
#include <QObject>
#include <QElapsedTimer>



class MainWindowViewModel : public QObject
{

public:
	MainWindowViewModel(QObject* parent);
	~MainWindowViewModel();

	void pressKey(int qKey);
	void releaseKey(int qKey);
	
	void setVisualizer(Visualiser* visualiserPtr) { visualiser = visualiserPtr; };
	inline void setPiano(Piano* pianoPtr) { piano = pianoPtr; }
	inline void setRecordButton(QPushButton* recordButtonPtr) { recordButton = recordButtonPtr; }
	inline void setPlayButton(QPushButton* playButtonPtr) { playButton = playButtonPtr; }
	
	inline AudioStream* getAudioStreamPtr() { return audioStream; }

	void displayAudioReplay();
	void toggleRecordingAudio();

	void checkForSoundKeyPressed(int qKey);


private:
	
	bool soundKeyPressed;

	/// <summary>
    /// Wskaźnik do obiektu klasy Visualizer reprezentujacego wizualizer na ekranie.
    /// </summary>
	Visualiser* visualiser = nullptr;

	/// <summary>
	/// Wskaźnik do obiektu klasy Piano reprezentujacego klawiaturę na ekranie.
	/// </summary>
	Piano* piano = nullptr;
	
	/// <summary>
	/// Wskaźnik do obiektu klasy QPushButton reprezentujacego przycisk odpowiedzialny za nagranie utworu.
	/// </summary>
	QPushButton* recordButton = nullptr;

	/// <summary>
	/// Wskaźnik do obiektu klasy QPushButton reprezentujacego przycisk odpowiedzialny za odtworzenie nagrania.
	/// </summary>
	QPushButton* playButton = nullptr;

	/// <summary>
	/// Wskaźnik do obiektu klasy QElapsedTimer odpowiedzialnego za pomiar czasu wciskania poszczególnego przycisku.
	/// </summary>
	QElapsedTimer* timer;

	QElapsedTimer* noSoundTimer;

	/// <summary>
	/// Czas pomiędzy wciśnięciem a puszczeniem poszczególnego przycisku.
	/// </summary>
	int elapsedTime;

	/// <summary>
	/// Wskaźnik do obiektu klasy AudioStream reprezentujacego źródło dźwięku programu.
	/// </summary>
	AudioStream* audioStream;

	KeyPressThread* keyPressThread;

	int keys[13] = {
		Qt::Key_A,
		Qt::Key_W,
		Qt::Key_S,
		Qt::Key_E,
		Qt::Key_D,
		Qt::Key_F,
		Qt::Key_T,
		Qt::Key_G,
		Qt::Key_Y,
		Qt::Key_H,
		Qt::Key_U,
		Qt::Key_J,
		Qt::Key_K,
	};
};


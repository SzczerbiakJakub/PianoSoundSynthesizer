#include "mainwindowviewmodel.h"



MainWindowViewModel::MainWindowViewModel(QObject* parent) : QObject(parent) {
    soundKeyPressed = false;
    keyPressThread = new KeyPressThread(&soundKeyPressed);
    timer = new QElapsedTimer();
    noSoundTimer = new QElapsedTimer();
    audioStream = new AudioStream();
    elapsedTime = 0;
    keyPressThread->start();
};


MainWindowViewModel::~MainWindowViewModel() {

    delete piano;
    delete recordButton;
    delete playButton;
    delete timer;
    keyPressThread->terminate();
    delete keyPressThread;
    delete visualiser;
    delete noSoundTimer;
    delete audioStream;
};


void MainWindowViewModel::checkForSoundKeyPressed(int qKey) {

    bool logic = false;
    for (int i = 0; i < 13; i++)
    {
        if (keys[i] == qKey)
        {
            logic = true;
            break;
        }
    }
    soundKeyPressed = logic;
}

void MainWindowViewModel::pressKey(int qKey) {

    checkForSoundKeyPressed(qKey);

    switch (qKey) {
        case Qt::Key_A:
            piano->getViewModelPtr()->pressKey(1);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(0));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(0));
            break;
        case Qt::Key_W:
            piano->getViewModelPtr()->pressKey(9);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(1));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(1));
            break;
        case Qt::Key_S:
            piano->getViewModelPtr()->pressKey(2);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(2));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(2));
            break;
        case Qt::Key_E:
            piano->getViewModelPtr()->pressKey(10);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(3));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(3));
            break;
        case Qt::Key_D:
            piano->getViewModelPtr()->pressKey(3);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(4));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(4));
            break;
        case Qt::Key_F:
            piano->getViewModelPtr()->pressKey(4);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(5));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(5));
            break;
        case Qt::Key_T:
            piano->getViewModelPtr()->pressKey(11);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(6));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(6));
            break;
        case Qt::Key_G:
            piano->getViewModelPtr()->pressKey(5);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(7));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(7));
            break;
        case Qt::Key_Y:
            piano->getViewModelPtr()->pressKey(12);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(8));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(8));
            break;
        case Qt::Key_H:
            piano->getViewModelPtr()->pressKey(6);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(9));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(9));
            break;
        case Qt::Key_U:
            piano->getViewModelPtr()->pressKey(13);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(10));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(10));
            break;
        case Qt::Key_J:
            piano->getViewModelPtr()->pressKey(7);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(11));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(11));
            break;
        case Qt::Key_K:
            piano->getViewModelPtr()->pressKey(8);
            keyPressThread->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(12));
            visualiser->getViewModelPtr()->setCurrentSound(SoundEffects::getSoundFromCurrentOctave(12));
            break;
    }

    if (SoundEffects::recording && !SoundEffects::replay->empty())
    {
        int noSoundDuration = noSoundTimer->elapsed();

        SoundEffects::recordReplayElement(NULL, noSoundDuration);
    }

    timer->restart();
}


void MainWindowViewModel::releaseKey(int qKey) {

    elapsedTime = timer->elapsed();
    soundKeyPressed = false;

    switch (qKey) {
        case Qt::Key_A:
            piano->getViewModelPtr()->releaseKey(1);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(0), elapsedTime);
            break;

        case Qt::Key_W:
            piano->getViewModelPtr()->releaseKey(9);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(1), elapsedTime);
            break;

        case Qt::Key_S:
            piano->getViewModelPtr()->releaseKey(2);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(2), elapsedTime);
            break;

        case Qt::Key_E:
            piano->getViewModelPtr()->releaseKey(10);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(3), elapsedTime);
            break;

        case Qt::Key_D:
            piano->getViewModelPtr()->releaseKey(3);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(4), elapsedTime);
            break;

        case Qt::Key_F:
            piano->getViewModelPtr()->releaseKey(4);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(5), elapsedTime);
            break;

        case Qt::Key_T:
            piano->getViewModelPtr()->releaseKey(11);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(6), elapsedTime);
            break;

        case Qt::Key_G:
            piano->getViewModelPtr()->releaseKey(5);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(7), elapsedTime);
            break;

        case Qt::Key_Y:
            piano->getViewModelPtr()->releaseKey(12);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(8), elapsedTime);
            break;

        case Qt::Key_H:
            piano->getViewModelPtr()->releaseKey(6);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(9), elapsedTime);
            break;

        case Qt::Key_U:
            piano->getViewModelPtr()->releaseKey(13);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(10), elapsedTime);
            break;

        case Qt::Key_J:
            piano->getViewModelPtr()->releaseKey(7);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(11), elapsedTime);
            break;

        case Qt::Key_K:
            piano->getViewModelPtr()->releaseKey(8);
            SoundEffects::recordReplayElement(SoundEffects::getSoundFromCurrentOctave(12), elapsedTime);
            break;

        case Qt::Key_Up:
            if (SoundEffects::higherOctaveAvailable)
            {
                piano->getViewModelPtr()->setHigherOctaveToKeys();
            }
            SoundEffects::setHigherOctave();
            break;

        case Qt::Key_Down:
            if (SoundEffects::lowerOctaveAvailable)
            {
                piano->getViewModelPtr()->setLowerOctaveToKeys();
            }
            SoundEffects::setLowerOctave();
            break;
    }

    visualiser->getViewModelPtr()->setCurrentSound(nullptr);
    noSoundTimer->restart();
}


void MainWindowViewModel::displayAudioReplay() {
    keyPressThread->displayRecordedAudio();
}


void MainWindowViewModel::toggleRecordingAudio() {

    if (SoundEffects::recording)
    {
        SoundEffects::recording = false;
        recordButton->setText("RECORD REPLAY");
    }
    else
    {
        while (!SoundEffects::replay->empty()) {
            SoundEffects::replay->pop();
        }
        SoundEffects::recording = true;
        recordButton->setText("STOP RECORDING");
    }
}
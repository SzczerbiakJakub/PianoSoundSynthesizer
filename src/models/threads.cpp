#include "threads.h"



KeyPressThread::KeyPressThread(bool* keyPressed) : keyPressed(keyPressed) {
    currentSound = NULL;
    audioStream = new AudioStream();
    displayAudio = false;
}


KeyPressThread::~KeyPressThread() {
    delete audioStream;
    delete currentSound;
}


void KeyPressThread::displayRecordedAudio() {
    std::queue<std::pair<Sound*, int>*> bufferCopy = *SoundEffects::replay;

    displayAudio = true;
    while (!bufferCopy.empty()) {
        if (bufferCopy.front()->first != nullptr)
        {
            setCurrentSound(bufferCopy.front()->first);
            displayAudio = true;
        }
        else
            displayAudio = false;

        displayAudioForCertainTime(bufferCopy.front()->second);
        bufferCopy.pop();
    }

    displayAudio = false;
}


void KeyPressThread::displayAudioForCertainTime(int ms) {
    QElapsedTimer* timer = new QElapsedTimer();
    timer->start();

    while (timer->elapsed() < ms)
        continue;

    delete timer;
}


void KeyPressThread::run()
{
    while (true)
    {
        if ((*keyPressed || displayAudio) and currentSound != nullptr)
        {
            while ((*keyPressed || displayAudio))
                audioStream->playAudio(currentSound);
            currentSound = NULL;
        }
        QThread::sleep(0.02);
    }
}
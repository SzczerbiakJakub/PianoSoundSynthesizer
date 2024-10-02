#pragma once

#include <iostream>
#include <windows.h>
#include <Mmdeviceapi.h>
#include <audioclient.h>
#include <QElapsedTimer>
#include <vector>
#include <queue>


/// <summary>
/// Klasa odpowiedzialna za dźwięk.
/// </summary>
class Sound
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy Sound.
    /// </summary>
    /// <param name=freq> Częstotliwość tworzonego dźwięku. </param>
    Sound(float freq) : frequency(freq) {};

    /// <summary>
    /// Konstruktor obiektu klasy Sound.
    /// </summary>
    ~Sound();

    /// <summary>
    /// Metoda odpowiadająca za ustawienie formatu dźwięku.
    /// </summary>
    /// <param name=freq> Format dźwięku. </param>
    HRESULT SetFormat(WAVEFORMATEX*);

    /// <summary>
    /// Metoda odpowiadająca za wczytanie danych z obiektu Sound.
    /// </summary>
    /// <param name=totalFrames> Całkowite klatki dźwięku. </param>
    /// <param name=dataOut> Wskaźnik do bufora wyjściowego dźwięku. </param>
    /// <param name=flags> Flagi przetwarzanego bufora. </param>
    HRESULT LoadData(UINT32 totalFrames, BYTE* dataOut, DWORD* flags);

    /// <summary>
    /// Metoda odtwarzająca dane dźwiękowe obiektu.
    /// </summary>
    void refresh();

    /// <summary>
    /// Częstotliwość stworzonego dźwięku.
    /// </summary>
    float frequency = 440;

private:
    void init();
    bool initialised = false;
    bool silent = false;
    WAVEFORMATEXTENSIBLE  format;
    unsigned int pcmPos = 0;
    UINT32 bufferSize;
    UINT32 bufferPos = 0;
    static const unsigned int sampleCount = 96000;
    float* pcmAudio = nullptr;

};

/// <summary>
/// Klasa odpowiedzialna za streaming dźwięku.
/// </summary>
class AudioStream
{
public:
    /// <summary>
    /// Konstruktor obiektu klasy AudioStream.
    /// </summary>
    AudioStream();

    /// <summary>
    /// Destruktor obiektu klasy AudioStream.
    /// </summary>
    ~AudioStream();

    /// <summary>
    /// Metoda inicjulizująca klienta streamującego dźwięk.
    /// </summary>
    HRESULT initializeAudioClient();

    /// <summary>
    /// Metoda inicjulizująca klienta grającego dźwięk.
    /// </summary>
    HRESULT initializeRenderClient();

    /// <summary>
    /// Metoda odpowiedzialna za granie dźwięku na podstawie wczytanego obiektu.
    /// </summary>
    /// <param name=audioSource> Wskaźnik do obiektu klasy Sound </param>
    HRESULT playAudio(Sound* audioSource);

    /// <summary>
    /// Metoda zwracająca zmienna pAudioClient przypisaną do obiektu.
    /// </summary>
    IAudioClient* getAudioClient() { return pAudioClient; }

    /// <summary>
    /// Metoda zwracająca zmienna pRenderClient przypisaną do obiektu.
    /// </summary>
    IAudioRenderClient* getAudioRenderClient() { return pRenderClient; }



private:
    /// <summary>
    /// Obiekt klasy HRESULT
    /// </summary>
    HRESULT hr;

    /// <summary>
    /// Obiekt klasy REFERENCE_TIME zawierający wartość zapytanego czasu trwania bufora dźwiękowego
    /// </summary>
    REFERENCE_TIME hnsRequestedDuration;

    /// <summary>
    /// Obiekt klasy REFERENCE_TIME zawierający wartość rzeczywistego czasu trwania bufora dźwiękowego
    /// </summary>
    REFERENCE_TIME hnsActualDuration;

    /// <summary>
    /// Wskaźnik do obiektu klasy IAudioClient będącego klientem serwującym dźwięk
    /// </summary>
    IAudioClient* pAudioClient;

    /// <summary>
    /// Wskaźnik do obiektu klasy IAudioRenderClient będącego klientem odtwarzającym dźwięk
    /// </summary>
    IAudioRenderClient* pRenderClient;

    /// <summary>
    /// Wskaźnik do obiektu klasy WAVEFORMATEX zawierającego format używanego dźwięku
    /// </summary>
    WAVEFORMATEX* pwfx;

    /// <summary>
    /// Wskaźnik do obiektu klasy WAVEFORMATEX zawierającego format dźwięku najbardziej zbliżony do zadanego
    /// </summary>
    WAVEFORMATEX* pClosestMatch = nullptr;

    /// <summary>
    /// Całkowita ilość klatek w buforze
    /// </summary>
    UINT32 bufferFrameCount;

    /// <summary>
    /// Ilość wolnych klatek w buforze
    /// </summary>
    UINT32 numFramesAvailable;

    /// <summary>
    /// Ilość zajętych klatek w buforze
    /// </summary>
    UINT32 numFramesPadding;

    /// <summary>
    /// Obiekt klasy HANDLE
    /// </summary>
    HANDLE hEvent = NULL;

    /// <summary>
    /// Obiekt klasy HANDLE
    /// </summary>
    HANDLE hTask = NULL;

    /// <summary>
    /// Wskaźnik do bufora dźwięku
    /// </summary>
    BYTE* pData;

    /// <summary>
    /// Flagi bufora
    /// </summary>
    DWORD flags = 0;
};



/// <summary>
/// Klasa odpowiedzialna za obsługę dźwięku w programie.
/// </summary>
class SoundEffects
{
public:
    /// <summary>
    /// Zmienna logiczna zawierająca stan nagrywania.
    /// </summary>
    static bool recording;

    /// <summary>
    /// Metoda odpowiedzialna za nagrywanie granego dźwięku.
    /// </summary>
    /// <param name=sound> Wskaźnik do obiektu klasy Sound </param>
    /// <param name=duration> Czas trwania dźwięku </param>
    static void recordReplayElement(Sound* sound, int duration);

    /// <summary>
    /// Metoda odpowiedzialna za odtwarzanie nagranego dźwięku.
    /// </summary>
    /// <param name=audioStream> Wskaźnik do streamera dźwięku </param>
    static void displayReplay(AudioStream* audioStream);

    /// <summary>
    /// Wskaźnik na wektor par dźwięk - czas trwania, który zawiera informacje o nagraniu.
    /// </summary>
    static std::queue<std::pair<Sound*, int>*>* replay;

    /// <summary>
    /// Wektor zawierający dźwięki trzeciej oktawy.
    /// </summary>
    static std::vector<Sound*> thirdOctave;

    /// <summary>
    /// Wektor zawierający dźwięki czwartej oktawy.
    /// </summary>
    static std::vector<Sound*> fourthOctave;

    /// <summary>
    /// Wektor zawierający dźwięki piątej oktawy.
    /// </summary>
    static std::vector<Sound*> fifthOctave;

    /// <summary>
    /// Wskaźnik na obecnie wykorzystywaną oktawę.
    /// </summary>
    static std::vector<Sound*>* currentOctave;

    /// <summary>
    /// Zmienna logiczna zawierająca dostępność niższej oktawy.
    /// </summary>
    static bool lowerOctaveAvailable;

    /// <summary>
    /// Zmienna logiczna zawierająca dostępność wyższej oktawy.
    /// </summary>
    static bool higherOctaveAvailable;

    /// <summary>
    /// Metoda zmieniająca obecną oktawę na niższą.
    /// </summary>
    static void setLowerOctave();

    /// <summary>
    /// Metoda zmieniająca obecną oktawę na wyższą.
    /// </summary>
    static void setHigherOctave();

    /// <summary>
    /// Metoda zwracająca wskaźnik na żądany dźwięk z obecnej oktawy.
    /// </summary>
    /// <param name=index> Indeks żądanego dźwięku. </param>
    static Sound* getSoundFromCurrentOctave(int index);

    /// <summary>
    /// Metoda ustawiająca format dla poszczególnych dźwięków.
    /// </summary>
    /// <param name=format> Wskaźnik na żądany format. </param>
    static HRESULT setSoundsFormats(WAVEFORMATEX* format);


    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C3.
    /// </summary>
    static Sound* soundC3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C3#.
    /// </summary>
    static Sound* soundC3Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D3.
    /// </summary>
    static Sound* soundD3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D3#.
    /// </summary>
    static Sound* soundD3Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk E3.
    /// </summary>
    static Sound* soundE3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F3.
    /// </summary>
    static Sound* soundF3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F3#.
    /// </summary>
    static Sound* soundF3Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G3.
    /// </summary>
    static Sound* soundG3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G3#.
    /// </summary>
    static Sound* soundG3Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A3.
    /// </summary>
    static Sound* soundA3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A3#.
    /// </summary>
    static Sound* soundA3Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk B3.
    /// </summary>
    static Sound* soundB3;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C4.
    /// </summary>
    static Sound* soundC4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C4#.
    /// </summary>
    static Sound* soundC4Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D4.
    /// </summary>
    static Sound* soundD4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D4#.
    /// </summary>
    static Sound* soundD4Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk E4.
    /// </summary>
    static Sound* soundE4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F4.
    /// </summary>
    static Sound* soundF4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F4#.
    /// </summary>
    static Sound* soundF4Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G4.
    /// </summary>
    static Sound* soundG4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G4#.
    /// </summary>
    static Sound* soundG4Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A4.
    /// </summary>
    static Sound* soundA4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A4#.
    /// </summary>
    static Sound* soundA4Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk B4.
    /// </summary>
    static Sound* soundB4;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C5.
    /// </summary>
    static Sound* soundC5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C5#.
    /// </summary>
    static Sound* soundC5Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D5.
    /// </summary>
    static Sound* soundD5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk D5#.
    /// </summary>
    static Sound* soundD5Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk E5.
    /// </summary>
    static Sound* soundE5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F5.
    /// </summary>
    static Sound* soundF5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk F5#.
    /// </summary>
    static Sound* soundF5Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G5.
    /// </summary>
    static Sound* soundG5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk G5#.
    /// </summary>
    static Sound* soundG5Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A5.
    /// </summary>
    static Sound* soundA5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk A5#.
    /// </summary>
    static Sound* soundA5Sharp;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk B5.
    /// </summary>
    static Sound* soundB5;

    /// <summary>
    /// Wskaźnik na obiekt klasy SOund reprezentujący dźwięk C6.
    /// </summary>
    static Sound* soundC6;
};
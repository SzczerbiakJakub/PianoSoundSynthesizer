#include "sound.h"


const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
const IID IID_IAudioClient = __uuidof(IAudioClient);
const IID IID_IAudioRenderClient = __uuidof(IAudioRenderClient);


Sound::~Sound()
{
    if (pcmAudio)
    {
        delete[] pcmAudio;
    }
}


void Sound::refresh()
{
    initialised = false;
    pcmPos = 0;
}

void Sound::init()
{
    pcmPos = 0;
    pcmAudio = new float[sampleCount];
    const float radsPerSec = 2 * 3.1415926536 * frequency / (float)format.Format.nSamplesPerSec;
    for (unsigned long i = 0; i < sampleCount; i++)
    {
        float sampleValue = sin(radsPerSec * (float)i);
        pcmAudio[i] = sampleValue;
    }
    initialised = true;
}


HRESULT Sound::SetFormat(WAVEFORMATEX* wfex)
{
    if (wfex->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
    {
        format = *reinterpret_cast<WAVEFORMATEXTENSIBLE*>(wfex);
    }
    else
    {
        format.Format = *wfex;
        format.Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
        INIT_WAVEFORMATEX_GUID(&format.SubFormat, wfex->wFormatTag);
        format.Samples.wValidBitsPerSample = format.Format.wBitsPerSample;
        format.dwChannelMask = 0;
    }
    const UINT16 formatTag = EXTRACT_WAVEFORMATEX_ID(&format.SubFormat);

    std::cout << "Audio Format: ";
    switch (formatTag)
    {
    case WAVE_FORMAT_IEEE_FLOAT:
        std::cout << "WAVE_FORMAT_IEEE_FLOAT\n";
        break;
    case WAVE_FORMAT_PCM:
        std::cout << "WAVE_FORMAT_PCM\n";
        break;
    default:
        std::cout << "Wave Format Unknown\n";
        break;
    }
    return 0;
}


HRESULT Sound::LoadData(UINT32 totalFrames, BYTE* dataOut, DWORD* flags)
{
    float* fData = (float*)dataOut;
    UINT32 totalSamples = totalFrames * format.Format.nChannels;
    if (!initialised)
    {
        init();
        bufferSize = totalFrames * format.Format.nChannels;
    }
    if (pcmPos < sampleCount)
    {
        for (UINT32 i = 0; i < totalSamples; i += format.Format.nChannels)
        {
            for (size_t chan = 0; chan < format.Format.nChannels; chan++)
            {
                fData[i + chan] = (pcmPos < sampleCount) ? pcmAudio[pcmPos] : 0.0f;
            }
            pcmPos++;
        }
        bufferPos += totalSamples;
        bufferPos %= bufferSize;
    }
    else
    {
        refresh();
    }

    return 0;
}



Sound* SoundEffects::soundC3 = new Sound(131);
Sound* SoundEffects::soundC3Sharp = new Sound(139);
Sound* SoundEffects::soundD3 = new Sound(147);
Sound* SoundEffects::soundD3Sharp = new Sound(156);
Sound* SoundEffects::soundE3 = new Sound(165);
Sound* SoundEffects::soundF3 = new Sound(175);
Sound* SoundEffects::soundF3Sharp = new Sound(185);
Sound* SoundEffects::soundG3 = new Sound(196);
Sound* SoundEffects::soundG3Sharp = new Sound(208);
Sound* SoundEffects::soundA3 = new Sound(220);
Sound* SoundEffects::soundA3Sharp = new Sound(233);
Sound* SoundEffects::soundB3 = new Sound(247);
Sound* SoundEffects::soundC4 = new Sound(262);
Sound* SoundEffects::soundC4Sharp = new Sound(277);
Sound* SoundEffects::soundD4 = new Sound(294);
Sound* SoundEffects::soundD4Sharp = new Sound(311);
Sound* SoundEffects::soundE4 = new Sound(330);
Sound* SoundEffects::soundF4 = new Sound(349);
Sound* SoundEffects::soundF4Sharp = new Sound(370);
Sound* SoundEffects::soundG4 = new Sound(392);
Sound* SoundEffects::soundG4Sharp = new Sound(415);
Sound* SoundEffects::soundA4 = new Sound(440);
Sound* SoundEffects::soundA4Sharp = new Sound(466);
Sound* SoundEffects::soundB4 = new Sound(494);
Sound* SoundEffects::soundC5 = new Sound(523);
Sound* SoundEffects::soundC5Sharp = new Sound(554);
Sound* SoundEffects::soundD5 = new Sound(587);
Sound* SoundEffects::soundD5Sharp = new Sound(622);
Sound* SoundEffects::soundE5 = new Sound(659);
Sound* SoundEffects::soundF5 = new Sound(698);
Sound* SoundEffects::soundF5Sharp = new Sound(740);
Sound* SoundEffects::soundG5 = new Sound(784);
Sound* SoundEffects::soundG5Sharp = new Sound(830);
Sound* SoundEffects::soundA5 = new Sound(880);
Sound* SoundEffects::soundA5Sharp = new Sound(932);
Sound* SoundEffects::soundB5 = new Sound(988);
Sound* SoundEffects::soundC6 = new Sound(1047);


HRESULT SoundEffects::setSoundsFormats(WAVEFORMATEX* format) {
    HRESULT hr;
    hr = soundC3->SetFormat(format);
    hr = soundC3Sharp->SetFormat(format);
    hr = soundD3->SetFormat(format);
    hr = soundD3Sharp->SetFormat(format);
    hr = soundE3->SetFormat(format);
    hr = soundF3->SetFormat(format);
    hr = soundF3Sharp->SetFormat(format);
    hr = soundG3->SetFormat(format);
    hr = soundG3Sharp->SetFormat(format);
    hr = soundA3->SetFormat(format);
    hr = soundA3Sharp->SetFormat(format);
    hr = soundB3->SetFormat(format);
    hr = soundC4->SetFormat(format);
    hr = soundC4Sharp->SetFormat(format);
    hr = soundD4->SetFormat(format);
    hr = soundD4Sharp->SetFormat(format);
    hr = soundE4->SetFormat(format);
    hr = soundF4->SetFormat(format);
    hr = soundF4Sharp->SetFormat(format);
    hr = soundG4->SetFormat(format);
    hr = soundG4Sharp->SetFormat(format);
    hr = soundA4->SetFormat(format);
    hr = soundA4Sharp->SetFormat(format);
    hr = soundB4->SetFormat(format);
    hr = soundC5->SetFormat(format);
    hr = soundC5Sharp->SetFormat(format);
    hr = soundD5->SetFormat(format);
    hr = soundD5Sharp->SetFormat(format);
    hr = soundE5->SetFormat(format);
    hr = soundF5->SetFormat(format);
    hr = soundF5Sharp->SetFormat(format);
    hr = soundG5->SetFormat(format);
    hr = soundG5Sharp->SetFormat(format);
    hr = soundA5->SetFormat(format);
    hr = soundA5Sharp->SetFormat(format);
    hr = soundB5->SetFormat(format);
    hr = soundC6->SetFormat(format);
    return hr;
}


AudioStream::AudioStream() {

    IMMDeviceEnumerator* pEnumerator;
    IMMDevice* pDevice;

    hnsRequestedDuration = 1000000;
    hnsActualDuration;
    pAudioClient = NULL;
    pRenderClient = NULL;
    pwfx = NULL;

    hr = CoInitialize(nullptr);

    hr = CoCreateInstance(CLSID_MMDeviceEnumerator,
        NULL,
        CLSCTX_ALL, IID_IMMDeviceEnumerator,
        (void**)&pEnumerator);
    if (FAILED(hr))
        return;

    hr = pEnumerator->GetDefaultAudioEndpoint(
        eRender, eConsole, &pDevice);
    if (FAILED(hr))
        return;

    hr = pDevice->Activate(
        IID_IAudioClient, CLSCTX_ALL,
        NULL, (void**)&pAudioClient);
    if (FAILED(hr))
        return;

    hr = pAudioClient->GetMixFormat(&pwfx);
    if (FAILED(hr))
        return;

    hr = pAudioClient->IsFormatSupported(AUDCLNT_SHAREMODE_EXCLUSIVE, pwfx, &pClosestMatch);

    hr = pAudioClient->Initialize(
        AUDCLNT_SHAREMODE_SHARED,
        AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
        hnsRequestedDuration,
        hnsRequestedDuration,
        pwfx,
        NULL);
    if (FAILED(hr))
        return;

    hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (hEvent == NULL)
    {
        hr = E_FAIL;
        return;
    }

    hr = pAudioClient->SetEventHandle(hEvent);
    if (FAILED(hr))
        return;

    hr = pAudioClient->GetBufferSize(&bufferFrameCount);
    if (FAILED(hr))
        return;

    hr = pAudioClient->GetService(
        IID_IAudioRenderClient,
        (void**)&pRenderClient);
    if (FAILED(hr))
        return;

    hr = SoundEffects::setSoundsFormats(pwfx);
    if (FAILED(hr))
        return;

    pEnumerator->Release();
    pEnumerator = NULL;
    
    pDevice->Release();
    pDevice = NULL;

    hr = pAudioClient->Start();
    if (FAILED(hr))
        return;
}


AudioStream::~AudioStream() {

    CoTaskMemFree(pwfx);
    hr = pAudioClient->Stop();
    if (pRenderClient != NULL)
    {

        pRenderClient->Release();
        pRenderClient = NULL;
    }
    if (pRenderClient != NULL)
    {

        pRenderClient->Release();
        pRenderClient = NULL;
    }
    CoUninitialize();

}

HRESULT AudioStream::playAudio(Sound* audioSource) {

    if (audioSource != NULL)
    {
        hr = pRenderClient->GetBuffer(bufferFrameCount, &pData);
        if (FAILED(hr))
            return hr;

        hr = audioSource->LoadData(bufferFrameCount, pData, &flags);
        if (FAILED(hr))
            return hr;

        hr = pRenderClient->ReleaseBuffer(bufferFrameCount, flags);
        if (FAILED(hr))
            return hr;
    }
}


bool SoundEffects::recording = false;


std::queue<std::pair<Sound*, int>*>* SoundEffects::replay = new std::queue<std::pair<Sound*, int>*>;


void SoundEffects::recordReplayElement(Sound* sound, int duration) {
    if (recording)
        replay->push(new std::pair<Sound*, int>(sound, duration));
}


std::vector<Sound*> SoundEffects::thirdOctave = {
    SoundEffects::soundC3, SoundEffects::soundC3Sharp, SoundEffects::soundD3,
    SoundEffects::soundD3Sharp, SoundEffects::soundE3, SoundEffects::soundF3,
    SoundEffects::soundF3Sharp, SoundEffects::soundG3, SoundEffects::soundG3Sharp,
    SoundEffects::soundA3, SoundEffects::soundA3Sharp, SoundEffects::soundB3,
    SoundEffects::soundC4
};


std::vector<Sound*> SoundEffects::fourthOctave = {
    SoundEffects::soundC4, SoundEffects::soundC4Sharp, SoundEffects::soundD4,
    SoundEffects::soundD4Sharp, SoundEffects::soundE4, SoundEffects::soundF4,
    SoundEffects::soundF4Sharp, SoundEffects::soundG4, SoundEffects::soundG4Sharp,
    SoundEffects::soundA4, SoundEffects::soundA4Sharp, SoundEffects::soundB4,
    SoundEffects::soundC5
};

std::vector<Sound*> SoundEffects::fifthOctave = {
    SoundEffects::soundC5, SoundEffects::soundC5Sharp, SoundEffects::soundD5,
    SoundEffects::soundD5Sharp, SoundEffects::soundE5, SoundEffects::soundF5,
    SoundEffects::soundF5Sharp, SoundEffects::soundG5, SoundEffects::soundG5Sharp,
    SoundEffects::soundA5, SoundEffects::soundA5Sharp, SoundEffects::soundB5,
    SoundEffects::soundC6
};


std::vector<Sound*>* SoundEffects::currentOctave = &SoundEffects::fourthOctave;


Sound* SoundEffects::getSoundFromCurrentOctave(int index) {

    std::vector<Sound*> listOfSound = *SoundEffects::currentOctave;
    return listOfSound[index];
}


bool SoundEffects::lowerOctaveAvailable = true;
bool SoundEffects::higherOctaveAvailable = true;


void SoundEffects::setLowerOctave() {
    if (SoundEffects::currentOctave == &SoundEffects::fourthOctave)
    {
        SoundEffects::currentOctave = &SoundEffects::thirdOctave;
        lowerOctaveAvailable = false;
    }
    else if (SoundEffects::currentOctave == &SoundEffects::fifthOctave)
    {
        SoundEffects::currentOctave = &SoundEffects::fourthOctave;
        higherOctaveAvailable = true;
    }
}

void SoundEffects::setHigherOctave() {
    if (SoundEffects::currentOctave == &SoundEffects::fourthOctave)
    {
        SoundEffects::currentOctave = &SoundEffects::fifthOctave;
        higherOctaveAvailable = false;
    }
    else if (SoundEffects::currentOctave == &SoundEffects::thirdOctave)
    {
        SoundEffects::currentOctave = &SoundEffects::fourthOctave;
        lowerOctaveAvailable = true;
    }
}
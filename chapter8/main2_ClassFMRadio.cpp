//
// Created by zhuda on 2023/9/8.
//
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

class FMRadio {
public:
    FMRadio();

    FMRadio(double freq, int vol);

    void init();

    double getFrequency();

    void setFrequency(double newFreq);

    int getVolume();

    void setVolume(int newVolume);

    double setPerset(int index, double freq);

    bool presetExists(int index);

    double getPreset(int index);

private:
    void checkFrequency(double freq);

    void checkPreset(int index);
    void initialize(double freq, int vol);

    double frequency;
    int volume;
    int attenuation;    // o is no attenuation, 10 is maximum attenuation.
    double presets[6];
//    map<int, double> presets;
};
void FMRadio::initialize(double freq, int vol) {
    for (size_t i = 0; i < 6; ++i) {
        presets[i] = 0.0;
    }
    frequency = freq;
    volume = vol;
}
void FMRadio::checkFrequency(double freq) {
    assert(freq >= 87.5 && freq <= 108.8);
}

void FMRadio::checkPreset(int index) {
    assert(index >= 1 && index <= 6);
}

FMRadio::FMRadio(double freq, int vol) {
    initialize(freq, vol);
}

FMRadio::FMRadio() {
    initialize(87.5, 5);
}

void FMRadio::init() {
    for (size_t i = 0; i < 6; ++i) {
        presets[i] = 0.0;
    }
    frequency = 87.5;
    volume = 5;
}

double FMRadio::getFrequency() {
    return frequency;
}

void FMRadio::setFrequency(double newFreq) {
//    assert(newFreq >= 87.5 && newFreq <= 108.0);
    checkFrequency(newFreq);
    frequency = newFreq;
}

int FMRadio::getVolume() {
    return 10 - attenuation;
}

void FMRadio::setVolume(int newVol) {
    assert(newVol >= 0 && newVol <= 10);
    attenuation = 10 - newVol;
}

double FMRadio::setPerset(int index, double freq) {
//    assert(index >= 1 && index <= 6);
//    assert(freq >= 87.5 && freq <= 108.0);
    checkPreset(index);
    checkFrequency(freq);
    presets[index - 1] = freq;
    return freq;
}

bool FMRadio::presetExists(int index) {
//    assert(index >= 1 && index <= 6);
    checkPreset(index);
    return presets[index - 1] == 0.0;   // -1 maps [1, 6] to [0, 5]
//    return presets.find(index) != presets.end();
}

double FMRadio::getPreset(int index) {
    assert(presetExists(index));
    return presets[index];
}

int main() {
    FMRadio myRadio(88.5, 5);

    if (myRadio.presetExists(1))
        cout << "Preset 1: " << myRadio.getPreset(1) << endl;
    else
        cout << "Preset 1 not programmed." << endl;

//    myRadio.setFrequency(110.0);
    double f = myRadio.getFrequency();


    myRadio.setVolume(10);
    cout << myRadio.getVolume() << endl;

    return 0;
}
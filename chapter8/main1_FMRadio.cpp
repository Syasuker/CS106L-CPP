//
// Created by zhuda on 2023/9/8.
//
#include <iostream>
#include <map>

using namespace std;

struct FMRadio {
    double freguency;
    int volume;

    map<int, double> presets;
//    double presets[6];
};

bool SetDevicePower(double powerLevel);

void TuneReceiver(FMRadio radio);

int main() {
    FMRadio myRadio;
    myRadio.presets[1] = 88.5;
    myRadio.presets[2] = 89.3;

    myRadio.freguency = 88.5;
    myRadio.volume = 3;

    myRadio.freguency = 110.0;
    myRadio.volume = 11;
    myRadio.presets[0] = 85.0;

    TuneReceiver(myRadio);

    return 0;
}

void TuneReceiver(FMRadio radio) {
    double powerLevel = (radio.freguency - 87.5) / (108.0 - 87.5);
    SetDevicePower(powerLevel);
}

void LoadPreset(FMRadio &radio, int preset) {
    /*Check whether this preset exists. */
    map<int, double>::iterator itr = radio.presets.find(preset);
    /*If not, don't do anything.    */
    if (itr == radio.presets.end())
        return;
    /*  Otherwise, change the radio frequency.  */
    radio.freguency = itr->second;
}


//
// Created by zhuda on 2023/9/9.
//

#ifndef CHAPTER8_FMRADIO_H
#define CHAPTER8_FMRADIO_H

class FMRadio {
public:
    FMRadio();
    FMRadio(double freq, int vol);

    double getFrequency();
    void setFrequency(double newFreq);

    int getVolume();
    void setVolume(int newVolume);

    double setPreset(int index, double freq);
    bool presetExists(int index);
    double getPreset(int index);

private:
    void checkFrequency(double freq);
    void checkPreset(int index);
    void initialize(double freq, int vol);

    double frequency;
    int volume;
    double presets[6];
};

#endif //CHAPTER8_FMRADIO_H

//
// Created by zhuda on 2023/9/11.
//
#include <iostream>

using namespace std;

class Window {
public:
    void drawWindow();
    static int getRemainingInstances();

private:
    static Palette sharePal;
    static int numInstances;
};

Palette Window::sharePal;
int Window::numInstances = 0;

int Window::getRemainingInstances() {
    return numInstances;
}

int main() {
    cout << Window::getRemainingInstances() << endl;
    return 0;
}
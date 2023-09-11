//
// Created by zhuda on 2023/9/11.
//
#include <iostream>

using namespace std;

class Window {
public:
    Window(Palette* p);
    void drawWindow();

private:
//    Palette* pal;
    static Palette sharedPal;
    static int numInstances;
};

Palette Window::sharedPal;
int Window::numInstances = 0;

Window::Window(int *p) {
    ++numInstances;
}
Window::~Window() {
    /*  All older cleanup code   */
    --numInstances;
    if (numInstances == 0)
        cout << "No more Windows!*" << endl;
}

class MyClass {
public:
    void doSomething();

private:
    static int myStaticData;
};

int MyClass::myStaticData = 137;

void MyClass::doSomething() {
    ++myStaticData; // Modifies myStaticData for all classes
}

int main() {
    return 0;
}
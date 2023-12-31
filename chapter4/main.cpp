#include <iostream>
#include <string>
#include "strutils.h"
#include "mathUtils.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout << ConvertToLowerCase("THIS IS STRING!")  << endl;

    cout << "value of Max -> " << Max(1.37, 1.24) << endl;
    return 0;
}

// Magenta
enum Color {
    Red, Green, Blue, Cyan, Magenta, Yellow
};

enum LengthUnit {

};

string colorTOString(Color c) {
    switch (c) {
        case Red: return "Red";
        case Blue: return "Blue";
        case Green: return "Green";
        case Cyan: return "Cyan";
        case Magenta: return "Magenta";
        case Yellow: return "Yellow";
        default: return "<unknown>";
    }
}

Color getOppositeColor(Color c) {
    switch (c) {
        case Red: return Cyan;
        case Blue: return Yellow;
        case Green: return Magenta;
        case Cyan: return Red;
        case Magenta: return Green;
        case Yellow: return Blue;
        default: return c;  // Unknown color, undefined result
    }
}

Color GetOppositeColor(Color c) {
    switch (c) {
#define DEFINE_COLOR(color, opposite) case color: return opposite;
#include "color.h"
#undef DEFINE_COLOR
        default: return c;
    }
}

string ColorToString(Color c) {
    switch (c) {
#define DEFINE_COLOR(color, opposite) case color: return #color;
#include "color.h"
#undef DEFINE_COLOR

        default: return "<unknown>";
    }
}


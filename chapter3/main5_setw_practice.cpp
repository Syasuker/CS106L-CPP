#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout << setw(10) << 137 << endl;
    cout << setw(20) << "Hello there!" << endl;

    cout << '[' << left << setw(10) << "Hello!" << ']' << endl;     //
    cout << '[' << right << setw(10) << "Hello!" << ']' << endl;    //

    cout << setfill('0') << setw(8) << 1000 << endl;
    cout << setw(8) << 1000 << endl;

    cout << setfill('-') << setw(20) << "" << setfill(' ');

    return 0;
}

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass();

    ~MyClass();

    MyClass(const MyClass &other);      // Copy constructor.
    MyClass& operator = (const MyClass& other);
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


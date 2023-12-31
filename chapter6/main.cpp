#include <iostream>
#include <vector>
#include <set>
using namespace std;

const size_t kNumIterations = 10000;

int DieRoll();
size_t RunProcess();

int main() {
    std::cout << "Hello, World!" << std::endl;

    srand(static_cast<unsigned>(time(NULL)));
    size_t total = 0;

    for (size_t k = 0; k < kNumIterations; ++k) {
        total += RunProcess();
    }

    cout << "Average number of steps: "
         << double(total) / kNumIterations << endl;
    return 0;
}

/**
 * Rolls a six-sided die and returns the number that came up;
 * @return
 */
int DieRoll() {
    /*
     * rand() % 6 gives back a value between 0 and 5, inclusive, Adding one to this gives us a
     * valid number for a die roll.
     */
//    return (rand() % 365) + 1;
//    return (rand() % 20) + 1;
    return (rand() % 6) + 1;
}

size_t RunProcess() {
    set<int> generated;
//    vector<int> generated;

    while (true) {
        int nextValue = DieRoll();
        cout << " DieRoll is " << nextValue << endl;

//        for (size_t k = 0; k < generated.size(); ++k) {
//            if (generated[k] == nextValue)
//                return generated.size() + 1;
//        }

/*  Check if this is value has been rolled before.  */
        if (generated.count(nextValue))
            return generated.size() + 1;

        generated.insert(nextValue);     // vector size is backout?

    }


}

void demoIterator() {
    vector<int> myVector;    /*   */
    for (vector<int>::iterator itr = myVector.begin();
        itr != myVector.end();  ++itr)
    {
        cout << *itr << endl;
    }

}

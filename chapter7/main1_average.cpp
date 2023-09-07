#include <iostream>
#include <fstream>
#include <set>
#include <numeric>

using namespace std;

int main() {
    ifstream input("data.txt");
    multiset<int> values;

    /* Read the data from the file. */
    int currValue;
    while (input >> currValue)
        values.insert(currValue);

    /*  Compute the average.    */
    double total = 0.0;
    for (multiset<int>::iterator itr = values.begin();
        itr != values.end();    ++itr) {
        total += *itr;
    }
    cout << "Average is: " << total / values.size() << endl;

    cout << accumulate(values.begin(), values.end(), 0.0)   / values.size() << endl;

    cout << accumulate(values.lower_bound(42), values.upper_bound(137), 0) << endl;

}

template <typename InputIterator, typename Type> inline
Type accumulate(InputIterator start, InputIterator stop, Type initial) {
    while(start != stop) {
        initial += *start;
        ++start;
    }
    return initial;
}
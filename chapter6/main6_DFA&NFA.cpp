//
// Created by zhuda on 2023/9/5.
//
#include <iostream>
#include <map>
#include <set>

using namespace std;

struct DFA {
    map<pair<int, char>, int> transitions;
    set<int> acceptingStates;
    int startState;
};

struct NFA {
    multimap<pair<int, char>, int> transitions;
    set<int> acceptingStates;
    int startState;
};

bool IsEmailAddress(string input);

bool SimulateDFA(DFA &d, string input);

DFA LoadEmailDFA();

int main() {
    DFA dfa;

    bool b = SimulateDFA(dfa, "0011");

    return 0;
}

DFA LoadEmailDFA() {
    DFA dfa;
    // TODO
    return dfa;
}

bool SimulateNFA(NFA &nfa, string input) {
    set<int> currStates;
    currStates.insert(nfa.startState);

    for (string::iterator itr = input.begin(); itr != input.end(); ++itr
            ) {
        set<int> nextStates;
        for (set<int>::iterator state = currStates.begin();
             state != currStates.end(); ++state) {
            /*  Get all states that we transition to from this current state.   */
            pair<multimap<pair<int, char>, int>::iterator,
                    multimap<pair<int, char>, int>::iterator>
                    transitions = nfa.transitions.equal_range(make_pair(*state, *itr));
            /*  Add these new states to the nextStates set.     */
            for (; transitions.first != transitions.second; ++transitions.first) {
                /**
                 * transitions.first is the current iterator, and its second field is the
                 * value (new state) in the STL multimap.
                 */
                nextStates.insert(transitions.first->second);
            }
        }
    }

    for (set<int>::iterator itr = currStates.begin(); itr != currStates.end(); ++itr) {
        if (nfa.acceptingStates.count(*itr)) return true;
    }
    return false;
}

bool SimulateDFA(DFA &d, string input) {
    int currState = d.startState;
    for (string::iterator itr = input.begin(); itr != input.end(); ++itr) {
        cout << *itr << endl;
        currState = d.transitions[make_pair(currState, *itr)];
        /*  TODO    */
    }
    //  lookup whether the currState variable is contained in the acceptingStates set in the DFA struct;
    return d.acceptingStates.find(currState) != d.acceptingStates.end();
}

bool SimulateNFA(DFA &nfa);

bool IsEmailAddress(string input) {
    DFA emailChecker = LoadEmailDFA();      // Implemented elsewhere

    /* Transform the string one character at a time.    */
    for (string::iterator itr = input.begin(); itr != input.end(); ++itr) {
        /**
         * isalnum is exported by <cctype> and checks if the input is an alphanumberic character.
         */
        if (isalnum(*itr))
            *itr = 'a';
            /*
             * If we don't have alphanumeric data, we have to be a dot or at-sign or the input is invalid.
             */
        else if (*itr != '.' && *itr != '@')
            return false;
    }
    return SimulateDFA(emailChecker, input);
}
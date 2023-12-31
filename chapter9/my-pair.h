//
// Created by zhuda on 2023/9/9.
//

#ifndef CHAPTER9_MY_PAIR_H
#define CHAPTER9_MY_PAIR_H

template<typename FirstType, typename SecondType>
class MyPair {
public:
    FirstType getFirst();

    void setFirst(FirstType newValue);

    SecondType getSecond();

    void setSecond(SecondType newValue);

private:
    FirstType first;
    SecondType second;
};

template<typename FirstType, typename SecondType>
FirstType MyPair<FirstType, SecondType>::getFirst() {
    return first;
}

template<typename FirstType, typename SecondType>
void MyPair<FirstType, SecondType>::setFirst(FirstType newValue) {
    first = newValue;
}

template<typename FirstType, typename SecondType>
SecondType MyPair<FirstType, SecondType>::getSecond() {
    return second;
}

template<typename FirstType, typename SecondType>
void MyPair<FirstType, SecondType>::setSecond(SecondType newValue) {
    second = newValue;
}

#endif //CHAPTER9_MY_PAIR_H


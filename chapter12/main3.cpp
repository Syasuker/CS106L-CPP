//
// Created by zhuda on 2023/9/13.
//
#include <iostream>
#include <memory>

using namespace std;
int SomeComplicatedFunction();

struct nodeT {
    int data;
    nodeT *next;
};

nodeT *GetNewCell() {
    nodeT *newCell = new nodeT;
    newCell->next = NULL;
    newCell->data = SomeComplicatedFunction();
    return newCell;
}

nodeT *GetNewCell() {
    auto_ptr<nodeT> newCell(new nodeT);
    newCell->next = NULL;
    newCell->data = SomeComplicatedFunction();
    return newCell.release();   // Tell the auto_ptr to stop managing memory.
}

auto_ptr<nodeT> GetNewCell() {
    auto_ptr<nodeT> newCell(new nodeT);
    newCell->next = NULL;
    newCell->data = SomeComplicatedFunction();
    return newCell;
}
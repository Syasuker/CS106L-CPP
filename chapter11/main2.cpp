//
// Created by zhuda on 2023/9/13.
//

#include <cstddef>

template<typename T>
class ListSet {
public:
    ListSet();

    ListSet(const ListSet &other);

    ListSet &operator=(const ListSet &other);

    ~ListSet();

    void insert(const T &toAdd);

    bool contains(const T &toFind) const;

private:
    struct cellT {
        T data;
        cellT *next;
    };
    cellT *list;

    void copyOther(const ListSet &other);

    void clear();

};

template<typename T>
void ListSet<T>::copyOther(const ListSet<T> &other) {
    cellT **current = &list;

    for (cellT *source = other.list; source != NULL; source = source->next) {
        *current = new cellT;
        (*current)->data = source->data;
        (*current)->next = NULL;

        current = &((*current)->next);
    }
}

template<typename T>
void ListSet<T>::copyOther(const ListSet<T> &other) {
    for (cellT *source = other.list; source != NULL; source = source->next) {
        cellT *newNode = new cellT;
        newNode->data = source->next;
        newNode->next = list;
        list = newNode;
    }
}
//
// Created by zhuda on 2023/9/12.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class grid {
public:
    /*  Constructors destructors.   */
    grid();                             // Create empty grid
    grid(size_t rows, size_t cols);     // Construct to specified size

    void clear();                       // Empty the grid
    void resize(size_t rows, size_t cols);  // Resize the grid

    size_t numRows() const;                 // Returns number of rows in the grid.
    size_t numCols() const;                 // Returns number of colums in the grid
    bool empty() const;                     // Returns whether the grid is empty
    size_t size() const;                    // Returns the number of elements

    T &getAt(size_t row, size_t col);          // Access individual elements
    const T &getAt(size_t row, size_t col) const; // Same, but const

    typedef typename vector<T>::iterator iterator;
    typedef typename vector<T>::const_iterator const_iterator;

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    iterator row_begin(size_t row);

    const_iterator row_begin(size_t row) const;

    iterator row_end(size_t row);

    const_iterator row_end(size_t row) const;

    class MutableReference {
    public:
        friend class grid;

        T &operator[](size_t col);

    private:
        MutableReference(grid *owner, size_t row);

        grid *const owner;
        const size_t row;
    };

    MutableReference operator[](int row);

    class ImmutableReference {
    public:
        friend class grid;

        const T &operator[](size_t col) const;

    private:
        MutableReference(const grid *owner, size_t row);

        const grid *const owner;
        const size_t row;
    };

    ImmutableReference operator[](size_t row) const;


    bool operator<(const grid &other) const;

    bool operator<=(const grid &other) const;

    bool operator==(const grid &other) const;

    bool operator!=(const grid &other) const;

    bool operator>=(const grid &other) const;

    bool operator>(const grid &other) const;

private:
    vector<T> elems;
    size_t rows;
    size_t cols;
};

template<typename T>
bool grid<T>::operator<(const grid &other) const {
    if (rows != other.rows)
        return rows < other.rows;

    if (cols != other.cols)
        return cols < other.cols;

    return lexicographical_compare(begin(), end(), other.begin(), other.end());
}

template<typename T>
bool grid<T>::operator>=(const grid &other) const {
    return !(*this < other);
}

template<typename T>
bool grid<T>::operator==(const grid &other) const {
    return !(*this < other) && !(other < *this);
}

template<typename T>
bool grid<T>::operator!=(const grid &other) const {
    return (*this < other) || (other < *this);
}

template<typename T>
bool grid<T>::operator>(const grid &other) const {
    return other < *this;
}

template<typename T>
bool grid<T>::operator<=(const grid &other) const {
    return !(other < *this);
}

template<typename T>
grid<T>::MutableReference::MutableReference(grid<T> *owner, size_t row)
        : owner(owner), row(row) {
}

template<typename T>
T &grid<T>::MutableReference::operator[](size_t col) {
    return owner->getAt(row, col);
}

template<typename T>
typename grid<T>::MutableReference grid<T>::operator[](int row) {
    return MutableReference(this, row);
}

template<typename T>
grid<T>::grid()
        :rows(0), cols(0) {

}

template<typename T>
grid<T>::grid(size_t rows, size_t cols)
        :elems(rows * cols), rows(rows), cols(cols) {

}

template<typename T>
void grid<T>::clear() {
    resize(0, 0);
}

template<typename T>
void grid<T>::resize(size_t rows, size_t cols) {
    /* see below for assign */
    elems.assign(rows * cols, ElemType());

    /* Explicit this-> required since parameters have same name as members. */
    this->rows = rows;
    this->cols = cols;
}

template<typename T>
size_t grid<T>::numRows() const {
    return rows;
}

template<typename T>
size_t grid<T>::numCols() const {
    return cols;
}

template<typename T>
size_t grid<T>::size() const {
    return numRows() * numCols();
}

/* Use row-major ordering to access the proper element of the vector. */
template<typename T>
T &grid<T>::getAt(size_t row, size_t col) {
    return elems[col + row * cols];
}

template<typename T>
const T &grid<T>::getAt(size_t row, size_t col) const {
    return elems[col + row * cols];
}

template<typename T>
typename grid<T>::iterator grid<T>::begin() {
    return elems.begin();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::begin() const {
    return elems.begin();
}

template<typename T>
typename grid<T>::iterator grid<T>::end() {
    return elems.end();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::end() const {
    return elems.end();
}

template<typename T>
typename grid<T>::iterator grid<T>::row_begin(size_t row) {
    return begin() + numCols() * row;
}

template<typename T>
typename grid<T>::const_iterator grid<T>::row_begin(size_t row) const {
    return begin() + numCols() * row;
}

template<typename T>
typename grid<T>::iterator grid<T>::row_end(size_t row) {
    return row_begin(row) + numCols();
}

template<typename T>
typename grid<T>::const_iterator grid<T>::row_end(size_t row) const {
    return row_begin(row) + numCols();
}



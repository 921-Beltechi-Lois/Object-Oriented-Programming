//
// Created by loisb on 06.04.2022.
//

#ifndef T1_911_BELTECHI_LOIS_1_DYNAMICVECTOR_H
#define T1_911_BELTECHI_LOIS_1_DYNAMICVECTOR_H


template <typename T>
class DynamicVector{
private:
    //TElem* elems;
    T* elems;
    int capacity, size;

public:
    DynamicVector(int capacity=10); // default
    DynamicVector(const DynamicVector& v); //copy

    DynamicVector& operator=(const DynamicVector& v); //assig op

    ~DynamicVector();

    void resize();
    void add(const T& elem);
    void remove(int pos);
    void update(const T& elem, int pos);

    /// overload [] operator to get element directly on position
    T& operator[](int index) { return this->elems[index]; }

    int getSize() const {return this->size;}
    //void setSize(int value) { this->size=value;}
    T* getAllElems() const;
    T get_arr_on_pos( int pos);


};

//////////////////////////////////////////////////////

template <typename T>
DynamicVector<T>::DynamicVector(int capacity): size{0}, capacity{capacity} {
    this->elems= new T[capacity];
}
//// ???
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> &v) {
    this->size = v.size;
    this->capacity= v.capacity;
    this->elems = new T[this->capacity];
    for(int i=0;i<this->size;i++)
        this->elems[i] = v.elems[i];  ///destroy v?
}

template <typename T>
DynamicVector<T>&DynamicVector<T>::operator=(const DynamicVector<T>& v) {
    if (this == &v)
        return *this;

    this->capacity = v.capacity;
    this->size = v.size;

    delete[] this->elems;         /// vs here
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

template <typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->elems;
}

template <typename T>
void DynamicVector<T>::resize() {
    this->capacity+=10;
    T* newElems= new T[this->capacity];
    for(int i=0; i<this->size;i++){
        newElems[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems= newElems;
}

/// ????
template <typename T>
T* DynamicVector<T>::getAllElems() const
{
    return this->elems;
}
// T = event
template <typename T>
T DynamicVector<T>::get_arr_on_pos(int pos)
{
    return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(const T& elem) {
    if (this->size == this->capacity)
        this->resize();
    this->elems[this->size++] = elem;
}

template <typename T>
void DynamicVector<T>::remove(int pos) {
    this->elems[pos]=this->elems[this->size-1];
    this->size--;
}

template <typename T>
void DynamicVector<T>::update(const T& elem, int pos) {
    this->elems[pos] = elem;
}

#endif //T1_911_BELTECHI_LOIS_1_DYNAMICVECTOR_H

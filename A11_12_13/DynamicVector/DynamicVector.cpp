//
// Created by loisb on 24.03.2022.
//

//#include "DynamicVector.h"
//
//DynamicVector::DynamicVector(int capacity): size{0}, capacity{capacity} {
//    this->elems= new TElem[capacity];
//}
//
//DynamicVector::DynamicVector(const DynamicVector &v) {
//    this->size = v.size;
//    this->capacity= v.capacity;
//    this->elems = new TElem[this->capacity];
//    for(int i=0;i<this->size;i++)
//        this->elems[i] = v.elems[i];  ///destroy v?
//}
//
//DynamicVector& DynamicVector::operator=(const DynamicVector &v) {
//    if (this == &v)
//        return *this;
//
//    this->capacity = v.capacity;
//    this->size = v.size;
//
//    delete[] this->elems;         /// vs here
//    this->elems = new TElem[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        this->elems[i] = v.elems[i];
//
//    return *this;
//}
//
//DynamicVector::~DynamicVector() {
//    delete[] this->elems;
//}
//
//void DynamicVector::resize() {
//    this->capacity+=10;
//    TElem* newElems= new TElem[this->capacity];
//    for(int i=0; i<this->size;i++){
//        newElems[i] = this->elems[i];
//    }
//    delete[] this->elems;
//    this->elems= newElems;
//}
//
//TElem* DynamicVector::getAllElems() const
//{
//    return this->elems;
//}
//
//Event DynamicVector::get_arr_on_pos(int pos)
//{
//    return this->elems[pos];
//}
//
//void DynamicVector::add(const TElem &elem) {
//    if (this->size == this->capacity)
//        this->resize();
//    this->elems[this->size++] = elem;
//}
//
//void DynamicVector::remove(int pos) {
//    this->elems[pos]=this->elems[this->size-1];
//    this->size--;
//}
//
//void DynamicVector::update(const TElem &elem, int pos) {
//    this->elems[pos] = elem;
//}



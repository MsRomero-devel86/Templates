/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<string>
#include<list>
using namespace std;

#include"List.h"

template<class T>
List<T>::List() {
    this-> pt = 0;
    this->size = 0;
    this->index = 0;
}

template<class T>
List<T>::List(int size) {
    this->size = size;
    this->index = 0;
    pt = new T[this->size];
}

template<class T>
bool List<T>::add(T t) {
    if (this->index >= this->size)
        return false;
    pt[index++] = t;
    return true;
}

template<class T>
List<T>::~List() {
    delete []this->pt;
}

template<class T>
T List<T>::get(int position) {
    if (position < 0 || position >= index)
        throw position;
    return pt[position];
}
//remove element at certain index, dececrment
template<class T>
T List<T>::removeAt(int pos) {
    pos = pt[index--];
    return pos;
}
////boolean function to call the remove, a element at array index
template<class T>
bool List<T>::remove(int position) {
    /*
    if (this->index >= this->size)
        return false;
    pt[index--] = position;
    return true;
    
     */
    if (position >= index || position < 0) {
        throw position;
        return true;
    }
    return false;


}

//template<class T>
//List<T> &List<T>::operator=(List<T> &l) {
//    List<T>temp(l);
//
//}
////    if (this != &list) {
////        if (list.size != size) {
////            delete[]pt;
////            size = 0;
////            pt = nullptr;
////            pt = new int[temp.size];
////            size = list.size;
////        }
////        copy(list.pt, list.pt + list.size, pt);
////    }
////    return *this;
//}
//overloading operator that prints the list 

template<class T >
ostream& operator<<(ostream & stream, List<T> & list) {
    for (int i = 0; i < list.getSize(); ++i)
        stream << list.get(i) << " ";
    return stream;
}
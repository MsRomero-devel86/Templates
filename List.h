

/* 
 * File:   List.h
 * Author: meghan
 *
 * Created on April 1, 2019, 10:48 AM
 */

#ifndef LIST_H
#define LIST_H

#include<list>

template<class T>
class List {
private:
    int size; //# of values in the array
    int index; //holder of position of value in the array 
    T *pt; //point to allocated memory

public:

    List();
    List(int size);
    List(List<T> &l);
    //List<T>& operator=(const List<T>& l);
    ~List(); //destructor
    bool add(T t); //boolean add function
    T get(int position); //function to find the index
    T removeAt(int pos); //remove element at index();
    //function to find out how many elements in the list

    int getSize()const {
        return index;
    }
    bool remove(int position); //function to remove elements from the list

    //    friend ostream& operator<<(ostream & stream, const List<T> &list);
};


#endif /* LIST_H */


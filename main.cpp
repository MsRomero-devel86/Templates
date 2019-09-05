
/* 
 * File:   main.cpp
 * Author:Meghan
 *
 * 
 */

//#include <cstdlib>
#include<iostream>
#include<string>
#include<exception>//needed for the excepetion class 
//that implements the what function
#include<list>


using namespace std;
#include"List.cpp"
//#include"List.h"

class MyException : public exception {
public:

    MyException() {
        //exception::what();
    }
};

class MyClass {
private:
    int x;
public:

    MyClass() {
        x = -11111;
    }

    MyClass(int x) {
        this-> x = x;
    }

    MyClass(MyClass &c) {
        this ->x = c.x;
    }

    int getX() {
        return x;
    }

    MyClass & operator=(int x) {
        this->x = x;
        return *this;
    }

    MyClass & operator=(const MyClass & c) {
        this->x = c.x;
        return *this;
    }

    friend ostream& operator<<(ostream & stream, const MyClass & o);
};

ostream & operator<<(ostream & stream, const MyClass & o) {
    stream << o.x;
    return stream;
}




int main() {
 
    List<double> list0(3);
    list0.add(3.14);
    list0.add(2.14);
    cout << "list0: " << list0 << endl;
    List<int> list1(3);
    list1.add(1);
    list1.add(2);

    cout << "list1: " << list1 << endl;

    List<int> list2(2);
    list2.add(1);
    list2.add(2);
    cout << "list2: " << list2 << endl;

    List<int> list3;
    list3 = list2;
    cout << "list3: " << list3 << endl;

    List <MyClass> list4(2);
    MyClass c1(100);
    MyClass c2(200);
    list4.add(c1);
    list4.add(c2);
    cout << "list 4:" << list4 << endl;

    List <MyClass> list5(2);
    list5.add(c1);
    cout << "list 5: " << list5 << endl;
    list4 = list5;
    cout << "list 4: " << list4 << endl;

    list3.removeAt(0);
    cout << "list 3 after removal : " << list3 << endl;
    list3.removeAt(1);
    cout << "list 3 again after another removal: " << list3 << endl;


    try {
        list3.remove(0);
    } catch (int e) {
        cout << "Exception, index out of bounds:" << e << endl;
    }

    try {
        list4.remove(2);
    } catch (int e) {
        cout << "Exception, index out of bounds:" << e << endl;
    }
    return 0;
}




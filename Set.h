//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SET_H
#define HW1_SET_H
using namespace std;
#include <iostream>
#include "Vect.h"
class Set {
public:
    Set();
    Set(const Set &other);
    Set(int *&elements, int count, string nom);
    void printSet() const;
    int pop();
    void add(int item);
    int get(int item) { return vic.get(item);}
    void Sort();
    void destroy() {  vic.destroy(); }
    string getName() const { return (name); }
    void setName(string name){ this->name=name; }
    void setSize(int size) { this->size=size; }
    int getSize() const { return size; }
    bool operator<(const Set& b);

private:
    Vect vic;
    int size;
    string name;

};


#endif //HW1_SET_H

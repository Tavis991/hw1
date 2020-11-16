//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SET_H
#define HW1_SET_H
using namespace std;
#include <iostream>

class Set {
public:
    Set();
    Set(int *&elements, int count, string nom);
    void printSet() const;
    void Sort();
    void destroy() { delete(elms); }
    string getName() const { return (name); }
    void setElms(int*& elements) { this->elms=elements; }
    int **getElms() { return &elms; }
    void setName(string name){ this->name=name; }
    void setSize(int size) { this->size=size; }
    int getSize() const { return size; }
    void add(int item);

private:
    int *elms;
    int size;
    string name;
};


#endif //HW1_SET_H

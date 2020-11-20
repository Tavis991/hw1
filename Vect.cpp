//
// Created by tuli on 20/11/2020.
//
#include <iostream>
#include "Vect.h"
using namespace std;

Vect::Vect(const Vect& other)
:elms( new int [other.capacity] ),capacity(other.capacity),current(other.current){ //copy ctor
    for (int i=0; i<capacity; i++){
        this->elms[i]   =  other.elms[i];
    }
}
Vect::Vect(int capacity) { //size setting ctor
    elms = new int[capacity];
    this->capacity = capacity;
    current = 0;
}

Vect::Vect() //empty ctor
    {
        elms = new int[1];
        capacity = 1;
        current = 0;
    }
    // add an element  last
void  Vect::push(int data) //this is push, add to end of vector
    {
        if (current == capacity) { // re allocating vector
            int* temp = new int[capacity+1];
            for (int i = 0; i < capacity; i++) {    temp[i] = elms[i];   }
            delete[] elms;   capacity++;
            elms = temp;
        }
        elms[current] = data;    current++;
    }

    int Vect::get(int index) const {  // function to get element at index
        //if (index < current)
            return elms[index];
    }
    int Vect::pop() { return elms[current--]; }  // function to delete last element
    int Vect::size() { return current; }     // function to get size of the vector
    void Vect::print() const  { //printing the vector
        for (int i = 0; i < current; i++) {
            cout << elms[i] ;
            if (i<current-1) cout << ",";
        }
    }
int Vect::getCapacity() const {
    return capacity;
}

void Vect::Sort(){
    int i, j, key;
    for (i = 1; i < current; i++){  //sorting function for vector
        key = elms[i];
        j = i - 1;
        while (j >= 0 && elms[j] > key){
            elms[j + 1] = elms[j];
            j = j - 1;
        }
        elms[j + 1] = key;
    }
}

void Vect::destroy() {
       delete(this->elms);
}



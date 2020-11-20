//
// Created by tuli on 20/11/2020.
//

#ifndef HW1_VECT_H
#define HW1_VECT_H


class Vect {
    friend class Set;
    friend class SetCalc;
    Vect();
    Vect(const Vect& other);
    Vect(int capacity);
    void destroy();
    void push(int data, int index);
    void push(int data);
    int get(int index) const;
    void print() const;
    int size();
    int pop();
public:
    int getCapacity() const;

private:

private:
    int* elms;
    int capacity;
    int current;

    void Sort();
};


#endif //HW1_VECT_H

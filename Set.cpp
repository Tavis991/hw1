//
// Created by tuli on 07/11/2020.
//

#include "Set.h"

Set::Set()
:size(0), name("0")
{}
Set::Set(const Set& other)
:vic(other.vic),  size(other.size) ,name(other.name)//copy ctor
{}

bool Set::operator<(const Set &b) { //operator < for set used for sorting power set
    if (size < b.getSize()) return false;
    else if (b.getSize() > size) return true; //by size
    else {
        for (int i = 0; i < size; i++) {
            if (vic.get(i)>b.vic.get(i)) return true; //then by elms
            else if (vic.get(i)<b.vic.get(i)) return false;
        }
    }
    return false;
}

Set::Set(int *&elements, int count, string nom) //constructor
:name(nom){
    int *temp = new int[count];
    int j=0;
    bool flg;
    for(int i=0;i<count;i++){
        flg=false;
        for (int k=0;k<j;k++){  //here we are deleting duplicates
            if(elements[i]==temp[k]){flg=true; break;}
        }
        if (!flg){temp[j]=elements[i]; j++;}
    }
    vic.elms=new int[j+1]; //allocating premenent array
    vic.capacity=j+1; //setting size
    this->size=j;
    for(int i=0;i<j;i++){
        vic.elms[i]=temp[i];
    }
    delete(elements); //delete the original arr
    delete(temp); //delete temp arr
    this->vic.current=j;
    this->vic.Sort();
}


void  Set::printSet() const{
    cout << '{';
    vic.print();
    cout << '}';
}

void Set::add(int item) {
    vic.push(item);
    size++;
}

int Set::pop() { //this removes last item
    size--;
    return(vic.pop());
}










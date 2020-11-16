//
// Created by tuli on 07/11/2020.
//

#include "Set.h"
Set::Set()
:name("0"),size(0),elms(NULL)
{}

Set::Set(int *&elements, int count, string nom)
:name(nom){
//    cout<<"this is set init"<<endl;
    //cout<<"this is set initcount"<<count<<endl;
    int temp[count];
    int j=0;
    bool flg;
    for(int i=0;i<count;i++){
        flg=false;
        for (int k=0;k<j;k++){  //deleting duplicates
            if(elements[i]==temp[k]){flg=true; break;}
        }
        if (!flg){temp[j]=elements[i]; j++;}
        //cout<<elements[i];
    }
    elms=new int[j]; //allocating premenet array
    for(int i=0;i<j;i++){

        elms[i]=temp[i];
        //cout<<elms[i]<<"this is temp"<<endl;
    }
    delete(elements);
    this->size=j;
    this->Sort();
}

void Set::Sort(){
    int i, j, key;
    for (i = 1; i < size; i++){
        key = elms[i];
        j = i - 1;
        while (j >= 0 && elms[j] > key){
            elms[j + 1] = elms[j];
            j = j - 1;
        }
        elms[j + 1] = key;
    }
//    for(int i=0;i<size;i++){
//       cout<<elms[i]<<"this is sorted set";
//    }
}
void  Set::printSet() const{
    cout<<'{';
    for(int i=0;i<size;i++){
        cout<<elms[i];
        if(i<size-1){cout<<',';}
    }
    cout<<'}';
}

void Set::add(int item) {
    int* new_arr = new int[size+1];
    int i;
    for (i=0; i<size; i++){
        new_arr[i]=elms[i];
    }
    size++;
    new_arr[i]=item;
    //delete(elms);
    elms = new_arr;
    cout<<elms[i];
    //Sort();
    cout<<"this is add"; printSet();
}

void Set::pop(int item) {
    int* new_arr = new int[size-1];
    int i,j;
    for (i=0; i<size; i++,j++){
        if (elms[i] == item) continue; j--;
        new_arr[j]=elms[i];
    }
    size--;
    elms = new_arr;
    cout<<elms[i];
    //Sort();
    cout<<"this is pop"; printSet();
}













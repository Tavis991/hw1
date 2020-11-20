//
// Created by tuli on 07/11/2020.
//
#include "Set.h"
#include "SetLL.h"
#include "LLNode.h"
void SetLL::append(Set *new_set) { /* 1. allocate node */
    LLNode *newNode = new LLNode(new_set);
    if (isEmpty()) { head = newNode; }
    else {
        gotoEnd();
    curr->setNext(newNode);
    curr=newNode;
    }
    size++;
}

void SetLL::Replace(Set*& new_set){
    curr->getData()->destroy();
    curr->setData(new_set);
}

void SetLL::Destroy() {
    if (isEmpty()) return;   // if is empty nothing to delete
    gotoBeginning();
    LLNode* temp=head;
    while(temp->getNext()){    //deleting ..
        curr = temp->getNext();
        temp->Destroy();
        delete(temp);
        temp=curr;
    }
}

LLNode * SetLL::find(string name) {  // i return pointer because reference cannot be null
    if (isEmpty()) return NULL;
    gotoBeginning();
    do {if ( curr->getData()->getName() == name ) { return curr; } }
    while( gotoNext());
    return NULL;
}

int SetLL::del(LLNode* del) {
    if (isEmpty()) return 0;
    if ( del == head ) {
        LLNode* tmp = del->getNext(); // if i want to delete head
    head->Destroy(); head=tmp;  return 0;}
    else if ( del->getNext()){   // if i want to delete in mid
        LLNode* tmp = del->getNext();
        gotoPrior();
        curr->getNext()->Destroy();
        curr->setNext(tmp); //skip pointers over deleted element
        return 0;
    }
    gotoPrior();
    curr->getNext()->Destroy();
    curr->nullify();
    size--;
    return 0;
}

void SetLL::gotoPrior() {
    LLNode* temp = curr;
    gotoBeginning();
    while (curr->getNext() != temp) { gotoNext();}
}



//
// Created by tuli on 07/11/2020.
//
#include "Set.h"
#include "SetLL.h"
#include "LLNode.h"
void SetLL::append(Set *new_set) { /* 1. allocate node */
//    cout<<"this is append"<<endl;
//    new_set->printSet();
    LLNode *newNode = new LLNode(new_set);
    if (isEmpty()) { head = newNode; }
    else {
        gotoEnd(); cout<<"append at end";
    curr->setNext(newNode);
    curr=newNode;
    cout<<"this is append"<<endl;
    }
}

void SetLL::Replace(Set*& new_set){
    cout<<"replace";
    curr->Destroy();
    curr->setData(new_set);
}

void SetLL::Destroy() {
    if (isEmpty()) return;
    cout<<"this is setllDEL";
    gotoBeginning();
    LLNode* temp=head;
    head->Destroy();
    delete(head);
    while(temp->getNext()){
        curr = temp->getNext();
        temp->Destroy();
        delete(temp);
        temp=temp;
    }
}

void SetLL::Print() {
    if(isEmpty()) return;
    gotoBeginning();
    do { curr->printNod(); }
    while ( gotoNext());
}

LLNode * SetLL::find(string name) {
    if (isEmpty()) return NULL;
    gotoBeginning();
    do {if ( curr->getData()->getName() == name ) { return curr; } }
    while( gotoNext());
    return NULL;
}

int SetLL::del(LLNode* del) {
    if (isEmpty()) return 0;
    if ( del == head ) { LLNode* tmp = del->getNext();
    head->Destroy(); head=tmp;  return 0;}
    else if ( del->getNext()){
        LLNode* tmp = del->getNext();
        gotoPrior();
        curr->getNext()->Destroy();
        curr->setNext(tmp);
        return 0;
    }
    gotoPrior();
    curr->getNext()->Destroy();
    curr->nullify();
    return 0;
}

void SetLL::gotoPrior() {
    LLNode* temp = curr;
    gotoBeginning();
    while (curr->getNext() != temp) { gotoNext();}
}

//void SetLL::gotoPrior() {gotoBeginning(); while(curr->getNext()!=)
//
//}



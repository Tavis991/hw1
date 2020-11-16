//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SETLL_H
#define HW1_SETLL_H
#include "Set.h"
#include "LLNode.h"

class SetLL {
public:
    SetLL(){
        head=NULL;
        curr=NULL;
    }
    void append(Set* set);
    int gotoNext() { if ( curr->getNext() ) { curr = curr->getNext(); return 1; } return 0;}
    int hasNext() { if ( curr->getNext() ) { return 1; } return 0;}
    void gotoPrior();
    void gotoBeginning() { curr = head; }
    void gotoEnd() { while ( hasNext() ) gotoNext(); }
    void Destroy();
    void Print();
    bool isEmpty()  {if (head) { return false;}  return true; }
    LLNode* getCurr(){ return curr;}
    void Replace(Set*& new_set);
    LLNode* getHead() { return head; }
    int del (LLNode* del);
    LLNode* find (string name);

private:
    LLNode* head;
    LLNode* curr;
};


#endif //HW1_SETLL_H

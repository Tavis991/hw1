
#ifndef HW1_LLNODE_H
#define HW1_LLNODE_H
#include "Set.h"

class LLNode {
public:
    LLNode()
    :next(NULL) {}
    LLNode(Set*& set)
    :next(NULL),data(set) {}
    LLNode *getNext() { return next; }
    void nullify() { next=NULL; }
    void printNod(){ data->printSet(); }
    void setNext(LLNode *& new_node) { next=new_node; }
    void setData(Set *&new_set) { data=new_set; }
    Set* getData() { return data; };
    void Destroy(){ data->destroy(); data=NULL; next=NULL;}

private:
    LLNode* next;
    Set* data;
};


#endif //HW1_LLNODE_H

//
// Created by tuli on 07/11/2020.


#include "SetCalc.h"
SetCalc::SetCalc()
:NAMERR2("ERROR: "), NAMERR(" does not exist"),SIZERR("ERROR: group has more than 10 elements"),INPERR("ERROR: invalid input"),CMDRR("ERROR: invalid command; type 0 for exit")
{}

int SetCalc::run() {

    string temp;// return value for checking purpose
    getline(cin,temp);
    stringstream tip(temp);
    if (tip.gcount()>1) { cerr << CMDRR << endl ; return 1;}  //illegal cmd
    unsigned char cmd=tip.get();
    cin.clear();
    if(!isdigit(cmd)){
        cerr << CMDRR << endl;
        return 1;
    }
    cmd=cmd-'0';
    switch(cmd){
        case(1): //add

            if(setAdd()){return 1;}
            return 1;
        case(2):
            if(setDel());
            return 2;
        case(3):
            if (!setUnion()) {  return 1;}
            return 1;
        case(4):
            if (setIntersect()) { return 1; }
            return 4;
        case(5):
            if(powerSet()){ return 1; }
            return 5;
        case(6):
            if(!setPrint()){
                return 1;}
            return 1;
        case(0):

            if (SetLINKED.isEmpty())  {return 0; }
            else { SetLINKED.Destroy(); return 0;}

        default:
            cerr << CMDRR << endl;
            return 1;
    }
return 1;
}

int SetCalc::setAdd() {
    int elmtSIZE;
    string nom;
    int *elmts = new int;  // temp input array
    nom = parsi.parseNameX(false);
    if ((nom == "0")) { cerr << INPERR << endl; return 1; } //parse name if illegal return
    elmtSIZE = parsi.parseSet(elmts);
    if (elmtSIZE == -1) { cerr << INPERR << endl; return 1; } //parse set if illegal return
    Set *a = new Set(elmts, elmtSIZE, nom);
    if ( SetLINKED.find(a->getName())) { SetLINKED.Replace(a) ;
        return 0; }
    SetLINKED.append(a);
    return 0;
}

int const SetCalc::setPrint() {
    string tst;
    string nom = parsi.parseNameX(false);
    if ((nom == "0")) { cerr << INPERR << endl; return 1; }
    LLNode* temp = ( SetLINKED.find(nom));
    if (temp) { cout<<temp->getData()->getName()<<"=";
    temp->printNod();
    cout<<endl;
    return 0; }
    else { cerr <<NAMERR2<< nom << NAMERR << endl; return 1; }
}

int SetCalc::setIntersect() {

    string nom1;
    string nom2;
    string nomNew;
    if( parsi.parse2Name(nom1, nom2) =="0" ){ cerr << INPERR << endl; return 1; }//parsing names
    LLNode* bit1 = SetLINKED.find(nom1);
    if(!bit1) { cerr <<NAMERR2 << nom1 << NAMERR << endl; return 1;}
    LLNode* bit2 = SetLINKED.find(nom2);
    if(!bit2)  { cerr <<NAMERR2 << nom2 << NAMERR << endl; return 1;}//new name
    nomNew = parsi.parseNameX(false);
    if ((nomNew == "0")) { cerr << INPERR << endl; return 1; }
    int count =0;
    int * temps = new int[ max(bit1->getData()->getSize(),bit2->getData()->getSize()) ]; //max size if contained
    for (int i=0; i<bit1->getData()->getSize(); i++){  //copying if elm appear in both
        for (int j=0; j<bit2->getData()->getSize(); j++){
            if ((bit1->getData()->get(i) == (bit2->getData()->get(j)))){
                  temps[count++] =  (bit1->getData()->get(i));
            }
        }
    }
    Set* sect = new Set(temps, count, nomNew);
    if ( SetLINKED.find ( sect->getName())) { SetLINKED.Replace(sect) ; //if set in list override
        return 0; }
    SetLINKED.append(sect);

    return 0;
}

int SetCalc::setDel(){
    string nom;
    nom = parsi.parseNameX(false);
    if (nom == "0") { cerr << INPERR << endl; return 1; } //searching for element in list by name
    LLNode* tmp = ( SetLINKED.find(nom) ) ;
    if (!tmp) { cerr << NAMERR2 <<nom<< NAMERR << endl; return 1; }
    SetLINKED.del(tmp);
    return 0;
}

int SetCalc::setUnion() { // this is union,
    string nom1;
    string nom2;
    string nomNew;
    if( parsi.parse2Name(nom1, nom2)=="0") { cerr << INPERR << endl; return 1; } //parsing
    LLNode* bit1 = SetLINKED.find(nom1);
    if(!bit1) { cerr <<NAMERR2 << nom1 << NAMERR << endl; return 1;}
    LLNode* bit2 = SetLINKED.find(nom2);
    if(!bit2)  { cerr <<NAMERR2 << nom2 << NAMERR << endl; return 1;} //searching for sets in list

    nomNew = parsi.parseNameX(false);
    if ((nomNew == "0")) {cerr << INPERR << endl; return 1;}
    int count = bit1->getData()->getSize()+bit2->getData()->getSize();
    int * temps = new int[count]; //max size if unrelated

    for ( int i=0; i<bit1->getData()->getSize(); i++ ){ //copying
        *temps++ = (bit1->getData()->get(i));
    }
    for ( int i=0; i<bit2->getData()->getSize(); i++ ){
        *temps++ = (bit2->getData()->get(i));
    }
    temps-=count;
    Set* unii = new Set (temps, count, nomNew); //appending new set
    if ( SetLINKED.find ( unii->getName()) ) { SetLINKED.Replace(unii) ;
        return 0; }
    SetLINKED.append(unii);
    return 0;
}

int SetCalc::powerSet(){
    string nom;
    nom = parsi.parseNameX(false);
    if((nom == "0")) { cerr << INPERR << endl; return 1; }
    LLNode* tmp = SetLINKED.find(nom);
    if ((!tmp) || (tmp->getData()->getSize()>10))  { cerr <<NAMERR2 << nom << NAMERR << endl; return 1;}
    SetLL* powLink = new SetLL();
    Set* subset = new Set();     //powerset function creates a new linked list just for the power set
    Set* OGset = tmp->getData();
    const int Oshel = pow(2.0,OGset->getSize());
    powerSetLLHelper(OGset, subset, powLink, 0 ); //helper function calculates subsets recursivly

    powLink->gotoBeginning();
    Set* powArr = new Set[Oshel]; //linked list copied to a new array of known size
    for (int i=0; i<Oshel; i++){
        powArr[i] = *powLink->getCurr()->getData();
        powLink->gotoNext();
    }
    powerSort(powArr,Oshel);  //sorting function sorts array sorting array is easy and cheaper to sorting a linked list
    cout << "P("<<OGset->getName()<<")={"; //printings set of sets
    for (int i=0; i<Oshel; i++){
        powArr[i].printSet();
        if (i<Oshel-1) cout<<",";
    }
    cout<<"}"<<endl;
    powLink->Destroy();
    delete[] powArr; //free memory
    return 0;
}

int SetCalc::powerSetLLHelper(Set *&given_set, Set *&subset, SetLL*& powLink, int index){

    if (index >= given_set->getSize()) {  //recursion iterates over index, if reached add to list
        Set* T = new Set(*subset);
        powLink->append(T); powLink->gotoPrior(); return 0;} //for every item in  OG set there are two subsets in a power set
    else {
        powerSetLLHelper(given_set, subset, powLink,index+1); //one subset is a set with the item
        subset->add(given_set->get(index));

        powerSetLLHelper(given_set, subset, powLink,index+1); //and one without the item
        subset->pop();
    }
    return 0;
}

void SetCalc::powerSort(Set *&arr, int Oshel){
    int i, j;
    Set key;
        for (i = 1; i < Oshel; i++){  //sorting function for set, using insertion sort,
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] < key){ //set operator '<' helps us use this sorting algorithm naturally
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
}
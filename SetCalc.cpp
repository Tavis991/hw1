//
// Created by tuli on 07/11/2020.
//


#include "SetCalc.h"
SetCalc::SetCalc()
:NAMERR("ERROR:does not exist"),SIZERR("ERROR:group has more than 10 elements"),INPERR("ERROR:input error"),CMDRR("ERROR: invalid command, type 0 for exit")
{size=0;

}
inline void clearC(){   cout << string( 20, '\n' );}

int SetCalc::run() {
    cout << "Set Calculator" << endl;
    unsigned char cmd=0;
    cin>>cmd;
    if(!isdigit(cmd)){
        cerr << CMDRR;
        return 1;
    }
    cmd=cmd-'0';
    switch(cmd){
        case(1): //add
            cout <<"pressed 1"<<endl;
            if(setAdd()){return 1;}
            SetLINKED.Print();
            cout<<"this is calc add function"<<endl;
            return 1;
        case(2):
            if(setDel());
            cout <<"pressed 2";
            return 2;
        case(3):
            clearC();
            cout <<"pressed 3"<<endl;
            if (!setUnion()) { SetLINKED.Print(); return 1;}
            return 1;
        case(4):
            clearC();
            cout <<"pressed 4"<<endl;
            if (setIntersect()) { SetLINKED.Print(); return 1; }
            return 4;
        case(5):
            clearC();
            cout <<"pressed 3"<<endl;
            if(powerSet()){ return 1; }
            return 5;
        case(6):
            if(!setPrint()){
                cout<<endl<<"this is full list";
                SetLINKED.Print();
                return 1;}
            return 1;
        case(0):
            cout <<"pressed 0";
            if (SetLINKED.isEmpty())  {return 0; cout<<"this is del";}
            else { SetLINKED.Destroy(); return 0;}

        default:
            cerr << CMDRR;
            return 1;
    }
return 1;
}

int SetCalc::setAdd() {
    clearC();
    int elmtSIZE;
    string nom;
    int *elmts = new int;  //pointer problems here FIXED:))
    nom = parsi.parseNameX(true);
    if ((nom == "0")) { cerr << INPERR; return 1; }
    //cout << nom;
    elmtSIZE = parsi.parseSet(elmts);
    //cout<<"this is calc pars count"<<elmtSIZE<<endl;
    if (elmtSIZE == -1) { cerr << INPERR; return 1; }
    //for (int i=0;i<elmtSIZE;i++) {cout << elmts[i]<<endl; }//debug print
    Set *a = new Set(elmts, elmtSIZE, nom);
    //a->printSet();
    cout<<"this is calc setADD"<<endl;
    if ( SetLINKED.find(a->getName())) { SetLINKED.Replace(a) ;
        return 0; }
    SetLINKED.append(a);
   // delete (a);
    return 0;
}

int const SetCalc::setPrint() {
    string nom = parsi.parseNameX(true);
    if ((nom == "0")) { cerr << INPERR; return 1; }
    LLNode* temp = ( SetLINKED.find(nom));
    if (temp) { temp->printNod(); return 0; }
    else { cerr << NAMERR; return 1; }
}

int SetCalc::setIntersect() {

    string nom1;
    string nom2;
    string nomNew;
    if( parsi.parse2Name(nom1, nom2) =="0" ){ cerr << INPERR; return 1; }
    nomNew = parsi.parseNameX(false);
    if ((nomNew == "0")) { cerr << INPERR; return 1; }
    LLNode* bit1 = SetLINKED.find(nom1);    if(!bit1) { cerr << NAMERR; return 1;}
    LLNode* bit2 = SetLINKED.find(nom2);   if(!bit2)  { cerr << NAMERR; return 1;}
    int count =0;
    int * temps = new int[ max(bit1->getData()->getSize(),bit2->getData()->getSize()) ]; //max size if contained
    for (int i=0; i<bit1->getData()->getSize(); i++){  //copying if elm appear in both
        for (int j=0; j<bit2->getData()->getSize(); j++){
            if ((*bit1->getData()->getElms())[i] == (*bit2->getData()->getElms())[j]){
                  temps[count++] =  (*bit1->getData()->getElms())[i];
            }
        }
    }
    Set* sect = new Set(temps, count, nomNew);
    if ( SetLINKED.find ( sect->getName())) { SetLINKED.Replace(sect) ;
        return 0; }
    SetLINKED.append(sect);
    return 0;
}

int SetCalc::setDel(){
    clearC();
    string nom;
    nom = parsi.parseNameX(true);
    if (nom == "0") { cerr << INPERR; return 1; }
    LLNode* tmp = ( SetLINKED.find(nom) ) ;
//    if(!tmp){ return 1;}
//    tmp->printNod();
//    cout<<"this is del FOUND"<<endl;
    if (!tmp) { cerr << NAMERR; return 1; }
   // SetLINKED.Print();
    SetLINKED.del(tmp);
    return 0;
}

int SetCalc::setUnion() { // this is union,
    clearC();
    string nom1;
    string nom2;
    string nomNew;
    if( parsi.parse2Name(nom1, nom2)=="0") { cerr << INPERR; return 1; } //parsing
    nomNew = parsi.parseNameX(false);
    if ((nomNew == "0")) {cerr << INPERR; return 1;}

    LLNode* bit1 = SetLINKED.find(nom1);    if(!bit1) { cerr << NAMERR; return 1;}
    LLNode* bit2 = SetLINKED.find(nom2);   if(!bit2)  { cerr << NAMERR; return 1;} //searching for sets in list
    int count = bit1->getData()->getSize()+bit2->getData()->getSize();
    int * temps = new int[count]; //max size if unrelated

    for ( int i=0; i<bit1->getData()->getSize(); i++ ){ //copying
        *temps++ = (*bit1->getData()->getElms())[i];
    }
    for ( int i=0; i<bit2->getData()->getSize(); i++ ){
        *temps++ = (*bit2->getData()->getElms())[i];
    }
    temps-=count;
    cout<<"this is uniuni FOUND2"<<endl;
    Set* unii = new Set (temps, count, nomNew); //appending new set
    if ( SetLINKED.find ( unii->getName()) ) { SetLINKED.Replace(unii) ;
        return 0; }
    SetLINKED.append(unii);
    return 0;
}

int SetCalc::powerSet(){
    clearC();
    string nom;
    nom = parsi.parseNameX(true);
    if((nom == "0")) { cerr << INPERR; return 1; }
    LLNode* tmp = SetLINKED.find(nom);
    if ((!tmp) || (tmp->getData()->getSize()>10))  { cerr << NAMERR; return 1;}
    int oshelN = pow(2.0,tmp->getData()->getSize()); //size of P(A)
    Set* powSet = new Set[oshelN];
    SetLL* powLink= new SetLL;
    Set* subset = new Set();
    Set* OGset = tmp->getData();
    powerSetHelper(OGset, subset, powSet, 0);
    powSet -= oshelN;
    for( int i=0; i<oshelN; i++){
        powSet[i].printSet();
    }
    return 0;
}

int SetCalc::powerSetHelper(Set *&given_set, Set *&subset, Set *&powSet, int index){
    //int* array = new int[given_set->getSize()];
    if (index == given_set->getSize()) { Set* tmp = new Set(*subset->getElms(),subset->getSize(),"A"); *powSet++ = *tmp; return 0;}
    else {

        powerSetHelper(given_set, subset, powSet,index+1);
        subset->add((*given_set->getElms())[index]);
        subset->setSize(subset->getSize()+1);
        //subset->printSet();
        powerSetHelper(given_set, subset, powSet,index+1);
    }
return 0;
}

int SetCalc::powerSetLLHelper(Set *&given_set, Set *&subset, SetLL *&powSet, int index){
    //int* array = new int[given_set->getSize()];
    if (index == given_set->getSize()) { Set* tmp = new Set(*subset->getElms(),subset->getSize(),"A"); *powSet++ = *tmp; return 0;}
    else {

        powerSetHelper(given_set, subset, powSet,index+1);
        subset->add((*given_set->getElms())[index]);
        subset->setSize(subset->getSize()+1);
        //subset->printSet();
        powerSetHelper(given_set, subset, powSet,index+1);
    }
    return 0;
}
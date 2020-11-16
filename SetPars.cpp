//
// Created by tuli on 07/11/2020.
//

#include <cstdlib>
#include "SetPars.h"
SetPars::SetPars(){}
//
//string SetPars::parseName() {
//    nullti();
//    cin.ignore();
//    getline(cin,t);
//    stringstream tip(t);
//    tip>>t;
//    cout<<"this is t"<<t<<endl;
//    if (t.size()>8 || t.size()==0) return "0";
//    for (int i=0;i<t.size();i++) { if (! isupper(t[i])) { return "0";}}
//    string test;
//    tip>>test; if(test.size()>0) return "0";
//    cout<<"this is last t"<<t<<endl;
//    return t;
//}
string SetPars::parseNameX(bool flag) {
    nullti();
    if (flag) cin.ignore();
    getline(cin,t);
    stringstream tip(t);
    tip>>t;
    cout<<"this is t"<<t<<endl;
    if (t.size()>8 || t.size()==0) return "0";
    for (int i=0;i<t.size();i++) { if (! isupper(t[i])) { return "0";}}
    string test;
    tip>>test; if(test.size()>0) return "0";
    cout<<"this is last t"<<t<<endl;
    return t;
}

string SetPars::parse2Name(string & nom1, string & nom2){
    cin.ignore();
    getline(cin,t);
    stringstream tip(t);
    tip>>t;
    if ( (t.size()>8) || (t.size()==0)) return "0";
    for (int i=0;i<t.size();i++) { if (! isupper(t[i]) ) { return "0"; } }
    nom1 = t;
    tip>>t;
    if ((t.size()>8) || t.size()==0) return "0";
    for (int i=0;i<t.size();i++) { if (! isupper(t[i]) ) { return "0"; } }
    nom2 = t;
    string test;
    tip>>test; if(test.size()>0) return "0";
    return "1";
}

int SetPars::parseSet(int *& pointy) {
    string temp;
    int tempNUM;
    int count=0;

    getline(cin,temp);
    int *arr= new int[(temp.size()/2)]; // i want this dynamical aloc, max size of legal arr
    pointy=arr; //assigning aloc to pointer

    if ((const char)temp[0]!='{') { return -1; } //initial conditions
    int i=1;
    if (temp.size()==2){
        if (temp[i]=='}'){ return 0;} else{return -1;}
    }  //empty set
    if ((!isdigit(temp[i]) && (temp[i] != '-'))) {return -1;} //must start as number
    for  (i=1;i<temp.size()-1;i++){ //parsing set string
            string tempINT;
            int j=0; //max digits in int
                while(temp[i]!=' ' && i<temp.size()-1) { //break tokenizing loop if ' '
                    if (isdigit(temp[i])){
                        tempINT += temp[i++];
                             if ((++j)>9) { return -1; } //max digits in int
                     }
                    else if ((j==0) && (temp[i]=='-'))  { tempINT += temp[i++];}
                    else { return -1; } //illegal input
                }
            stringstream tip(tempINT);
            tip>>tempNUM;
            *arr=tempNUM;
            arr++; count++;
            }

        if (temp[i-1]!='}') { return -1;}
        arr -= count; return count;
    }


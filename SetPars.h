//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SETPARS_H
#define HW1_SETPARS_H



#include "Set.h"
#include <sstream>
using namespace std;


class SetPars {
public:
    SetPars();
   // string parseName();
    int parseSet(int *& pointy);
    string parse2Name(string & nom1, string & nom2);
    void nullti() {t="";}
    string parseNameX(bool flag);

private:
    string t;

};


#endif //HW1_SETPARS_H

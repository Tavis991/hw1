//
// Created by tuli on 07/11/2020.
//

#ifndef HW1_SETCALC_H
#define HW1_SETCALC_H

#include "cmath"
#include "SetPars.h"
#include "SetLL.h"
class SetCalc {
public:
    int run();
    SetCalc();
    int const setPrint ();
    int setAdd ();
    int setDel();
    int setIntersect();
    int setUnion();
    void Destroy() { SetLINKED.Destroy();}
    int powerSet();
private:
    const string NAMERR;
    const string SIZERR;
    const string INPERR;
    const string CMDRR;

    SetLL SetLINKED;
    SetPars parsi;
    int size;
    int powerSetHelper(Set *&given_set, Set *&subset, Set *&pow, int index);

    int powerSetLLHelper(Set *&given_set, Set *&subset, Set *&powSet, int index);

    int powerSetLLHelper(Set *&given_set, Set *&subset, SetLL *&powSet, int index);
};


#endif //HW1_SETCALC_H

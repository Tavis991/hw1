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
    const string NAMERR2;
    const string NAMERR;
    const string SIZERR;
    const string INPERR;
    const string CMDRR;

    SetLL SetLINKED;
    SetPars parsi;
    int powerSetLLHelper(Set *&given_set, Set *&subset, SetLL *&powSet, int index);

    void powerSort(Set *&arr, int Oshel);
};


#endif //HW1_SETCALC_H

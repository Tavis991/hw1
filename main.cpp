#include <iostream>
#include "Set.h"
#include "SetCalc.h"
void prompt();
int main() {
    cout << "Hello setcalculator!" << endl;
    prompt();
    SetCalc cal;
    while(cal.run()) {
        prompt();
    }
   // cal.Destroy();
    return 0;
}

void prompt(){
    cout << "[1] Press to save a new Set $use: <setname> enter <{e l m s}>" << endl;
    cout << "[2] Press to delete a Set by name" << endl;
    cout << "[3] Press to create a union Set $use: <a b> enter <aUb>" << endl;
    cout << "[4] Press to create a intersection Set "<< endl;
    cout << "[5] Press to print a power Set of a Set "<< endl;
    cout << "[6] Press to print a Set "<< endl;
    cout << "[0] Press to exit "<< endl;
}

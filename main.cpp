#include <iostream>
#include "Set.h"
#include "SetCalc.h"
void prompt();
int main() {
    prompt();
    SetCalc cal;
    while(cal.run()) {
        prompt();
    }
    return 0;
}

void prompt(){
    cout << "[1] add set" << endl;
    cout << "[2] remove set" << endl;
    cout << "[3] union" << endl;
    cout << "[4] intersection"<< endl;
    cout << "[5] power set"<< endl;
    cout << "[6] print"<< endl;
    cout << "[0] exit"<< endl;
}

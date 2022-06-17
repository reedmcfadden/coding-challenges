//============================================================================
// Name        : codeforces_round_792.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
    int numTests = 0;
    cin >> numTests;
    
    while (numTests > 0) {
        int zeroes = 0;
        int ones = 0;
        
        cin >> zeroes;
        cin >> ones;
        
        string minCreepString = "";
    
        while (zeroes > 0 && ones > 0) {
            minCreepString += '1';
            minCreepString += '0';
            --zeroes;
            --ones;
        }
        
        while (zeroes > 0) {
            minCreepString += "0";
            --zeroes;
        }
        
        while (ones > 0) {
            minCreepString += "1";
            --ones;
        }
        
        cout << minCreepString << endl;
        --numTests;
    }

	return 0;
}

//============================================================================
// Name        : codeforces_round_792.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <climits>

using namespace std;

int digitMinimization(int input) {
	// convert int to string for easier parsing
	string s = to_string(input);
	int n = s.size();
	
	// if string is one digit, it will be removed. return -1 to indicate this
	if (n == 1) {
		return -1;
	}
	// if the string is size 2, return the second digit because this is the only swap that can occur
	else if (n == 2) {
	    int res = (int) (s[1] - '1') + 1;
	    return res;
	}
	// if the size is 3, return the smaller of s[0] or s[2]
	if (n == 3) {
	    int digit1 = (int) (s[0] - '1') + 1;
	    int digit2 = (int) (s[2] - '1') + 1;
	    if (digit1 < digit2) {
	        return digit1;
	    }
	    else {
	        return digit2;
	    }
	}
	
	// if size >= 4, then take the smallest digit from the entire int. with this size, any digit
	// can be put into the first position with the right rotations
	int lowest = INT_MAX;
	for (int i = 0; i < s.size(); ++i) {
		int n = (int) (s[i] - '1') + 1;

		if (n < lowest) {
			lowest = n;
		}
	}

	return lowest;
}

int main() {
    int n;
    while (cin >> n) {
        int result = digitMinimization(n);
        if (result != -1) {
            cout << result << endl;
        }
    }

	return 0;
}

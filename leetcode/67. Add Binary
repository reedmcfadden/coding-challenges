class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        
        // make strings same size by adding leading zeroes to smaller string
        while (a.size() != b.size()) {
            if (a.size() < b.size()) {
                a.insert(0, "0");
            }
            else {
                b.insert(0, "0");
            }
        }
        
        size_t n = a.size();   // take either length, as they are the same now
        for (size_t i = 0; i < n; ++i) {
            int curr = a[n - 1 - i] - '0' + b[n - 1 - i] - '0' + carry;
            
            // add new bit to string
            if (curr == 0 || curr == 2) {
                res += "0";
            }
            else {
                res += "1";
            }
            
            // update the carry
            if (curr == 2 || curr == 3) {
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        
        // handle final carry
        if (carry == 1) {
            res += "1";
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

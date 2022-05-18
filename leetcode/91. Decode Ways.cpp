class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.size();
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            if (c != '0') {
                curr += prev1;
            }
            if (i + 1 < s.size() && (c == '1' || c == '2' && s[i + 1] <= '6')) {
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
            curr = 0;
        }
        
        return prev1;
    }
};

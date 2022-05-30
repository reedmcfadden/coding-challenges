class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitCount(n + 1, 0);
        int power = 1;
        
        for (int i = 1; i <= n; ++i) {
            // update power each time a new power of 2 is reached
            if (i == power * 2) {
                power = i;
            }
            
            bitCount[i] = 1 + bitCount[i - power];
        }
        
        return bitCount;
    }
};

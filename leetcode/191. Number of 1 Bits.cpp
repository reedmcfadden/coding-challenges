class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numOnes = 0;
        for (int i = 0; i < 32; ++i) {
            // get the ith bit
            int bit = 1 & (n >> i);
            
            // if ith bit was one, increment numOnes counter
            if (bit) {
                ++numOnes;
            }
        }
        
        return numOnes;
    }
};

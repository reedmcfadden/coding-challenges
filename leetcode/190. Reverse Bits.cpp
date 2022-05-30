class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0) {
            return n;
        }
        
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            // shift i'th bit to position 0 then AND with binary 1
            int bit = (n >> i) & 1; 
            // shift retrieved bit to proper position, and OR with the answer var
            ans = ans | (bit << (31 - i));
        }
        
        return ans;
    }
};

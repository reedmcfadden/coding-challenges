class Solution {
public:
    int getSum(int a, int b) {
        // a is used to store the answer
        // b is used to store the carry while bitwise calculations are occurring
        
        while (b != 0) {
            // must be cast to unsigned int to avoid negative int left shift errors
            int temp_b = ((unsigned int) a & b) << 1;
            a = a ^ b;
            b = temp_b;
        }
        
        return a;
    }
};

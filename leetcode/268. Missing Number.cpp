class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = 0;
        int maxSum = n;
        
        for (int i = 0; i < n; ++i) {
            // sum the actual elements in nums
            actualSum += nums[i];
            
            // create the sum of values 1 through n for the max sum
            // the 0 is skipped because it does not contribute to the sum
            maxSum += i;
        }
        
        // determine the missing number with a bitwise XOR
        // if the number are the same, i.e. nums contains 1 through n, 
        // then we know that the 0 is missing
        return maxSum - actualSum;
    }
    
    // alternative O(n) time and O(1) space requires each element to be xor'd.
    // found the sum solution to be more intuitive.
};

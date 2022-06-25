class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = nums[0];
        int n = nums.size();
        
        // bitwise xor every element. this return false (or negates) duplicate bits. The bits of the single number will remain at the end.
        for (int i = 1; i < n; ++i) {
            target ^= nums[i];
        }
        
        return target;
    }
};
